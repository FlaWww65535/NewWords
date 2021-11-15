#include<iostream>
using namespace std;
const int MAXN = 1e5+50;
long long v[MAXN];
struct Tree
{
	long long sum; long long lz;
	int l; int r;
}tree[4*MAXN];
inline void build(int i,int l,int r)
{
	tree[i].l = l; tree[i].r = r;
	if (l == r) { tree[i].sum = v[l]; tree[i].lz = 0; return; }
	int mid = (l + r) / 2;
	build(2 * i, l, mid);
	build(2 * i + 1, mid + 1, r);
	tree[i].sum = tree[2 * i].sum + tree[2 * i + 1].sum;
	tree[i].lz = 0;
}
inline void pushdown(int i)
{
	if (tree[i].lz)
	{
		tree[2 * i + 1].lz += tree[i].lz;
		tree[2 * i].lz += tree[i].lz;
		int mid = (tree[i].r +tree[i].l)/2;
		tree[2 * i].sum += tree[i].lz*(mid-tree[i].l+1);
		tree[2 * i+1].sum += tree[i].lz * (tree[i].r - mid);
		tree[i].lz = 0;
	}
}
inline void add(int i, int l, int r, long long k)
{
	if (l <= tree[i].l && r >= tree[i].r)
	{
		tree[i].sum += k * (tree[i].r-tree[i].l + 1);
		tree[i].lz += k; 
		return;
	}
	pushdown(i);
	if (tree[2*i].r>= l)
	{
		add(2 * i, l, r, k);
	}
	if (tree[2*i+1].l <= r)
	{
		add(2 * i+1, l, r, k);
	}
	tree[i].sum = tree[2 * i].sum + tree[2 * i + 1].sum;
	return;
}
inline long long search(int i, int l, int r)
{
	if (l <= tree[i].l && r >= tree[i].r)
	{
		return tree[i].sum;
	}
	if (l > tree[i].r || r < tree[i].l) { return 0; }
	pushdown(i);
	long long sum = 0;
	if (tree[i * 2].r >= l)  sum += search(i * 2, l, r);
	if (tree[i * 2 + 1].l <= r)  sum += search(i * 2 + 1, l, r);
	return sum;
}
int main()
{
	int n,m;
	cin >> n>>m;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	build(1, 1, n);
	while (m--)
	{
		int op;
		int x, y, k;
		cin >> op;
		switch (op)
		{
		case 1:
			cin >> x >> y >> k;
			add(1, x, y, k);
			break;
		case 2:
			cin >> x >> y;
			cout << search(1, x, y)<<endl;
			break;
		}
	}
	return 0;
}
