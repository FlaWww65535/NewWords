#include<iostream>
using namespace std;
const int MAXN = 1e5+50;
int p;
long long v[MAXN];
struct Tree
{
	int l; int r;
	long long sum; long long plz; long long mlz;

}tree[4*MAXN];
inline void build(int i,int l,int r)
{
	tree[i].l = l; tree[i].r = r;
	tree[i].plz = 0; tree[i].mlz = 1;
	if (l == r) { tree[i].sum = v[l]; tree[i].sum %= p; return; }
	int mid = (l + r) / 2;
	build(2 * i, l, mid);
	build(2 * i + 1, mid + 1, r);
	tree[i].sum = tree[2 * i].sum + tree[2 * i + 1].sum;
	tree[i].sum %= p;
}
inline void pushdown(int i)
{
	if (tree[i].mlz!=1)
	{
		tree[2 * i].plz *= tree[i].mlz;
		tree[2 * i].plz %= p;
		tree[2 * i + 1].plz *= tree[i].mlz;
		tree[2 * i + 1].plz %= p;//儿子的加标记乘上父亲的乘标记
		tree[2 * i].mlz *= tree[i].mlz;
		tree[2 * i].mlz %= p;
		tree[2 * i + 1].mlz *= tree[i].mlz;
		tree[2 * i + 1].mlz %= p;//儿子的乘标记乘父亲的乘标记
		tree[2 * i].sum *= tree[i].mlz;
		tree[2 * i].sum %= p;
		tree[2 * i + 1].sum *= tree[i].mlz;
		tree[2 * i + 1].sum %= p;
		tree[i].mlz = 1;
	}
	if (tree[i].plz)
	{
		tree[2 * i].plz += tree[i].plz;
		tree[2 * i].plz %= p;
		tree[2 * i + 1].plz += tree[i].plz;
		tree[2 * i + 1].plz %= p;
		int mid = (tree[i].r + tree[i].l) / 2;
		tree[2 * i].sum += tree[i].plz * (mid - tree[2*i].l + 1);
		tree[2 * i + 1].sum += tree[i].plz * (tree[2 * i + 1].r - mid);
		tree[i].plz = 0;
	}
	return;
}
inline void add(int i, int l, int r, int k)
{
	if (l <= tree[i].l && r >= tree[i].r)
	{
		tree[i].sum += k * (tree[i].r-tree[i].l + 1);
		tree[i].sum%= p;
		tree[i].plz += k; 
		tree[i].plz %= p;
		return;
	}
	pushdown(i);
	if (tree[2*i].r>= l)
	{
		add(2 * i, l, r, k);
	}
	if (tree[2 * i + 1].l <= r)
	{
		add(2 * i + 1, l, r, k);
	}
	tree[i].sum = tree[2 * i].sum + tree[2 * i + 1].sum;
	tree[i].sum %= p;
	return;
}
inline void mul(int i, int l, int r, int k)
{
	if (l <= tree[i].l && r >= tree[i].r)
	{
		tree[i].plz *= k;
		tree[i].plz %= p;
		tree[i].sum *= k;
		tree[i].sum %= p;
		tree[i].mlz *= k;
		tree[i].mlz %= p;
		return;
	}
	pushdown(i);
	if (tree[2 * i].r >= l)
	{
		mul(2 * i, l, r, k);
	}
	if (tree[2 * i + 1].l <= r)
	{
		mul(2 * i + 1, l, r, k);
	}
	tree[i].sum = tree[2 * i].sum + tree[2 * i + 1].sum;
	tree[i].sum %= p;
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
	if (tree[i * 2].r >= l) {
		sum += search(i * 2, l, r); sum%= p;
	}
	if (tree[i * 2 + 1].l <= r) {
		sum += search(i * 2 + 1, l, r); sum %= p;
	}
	return sum;
}
int main()
{
	int n,m;
	cin >> n>>m>>p;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	build(1, 1, n);
	while (m--)
	{
		int op;
		long long x, y, k;
		cin >> op;
		switch (op)
		{
		case 1:
			cin >> x >> y >> k;
			mul (1, x, y, k);
			break;
		case 2:
			cin >> x >> y>>k;
			add(1, x, y, k);
			break;
		case 3:
			cin >> x >> y;
			cout << search(1, x, y)<<endl;
			break;
		}
	}
	return 0;
}
