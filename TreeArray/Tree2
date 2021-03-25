#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
const int MAXN = 500050;
int v[MAXN];
struct Tree
{
	int l, r;
	int sum, mark;
}tree[4*MAXN];
void build(int i,int l,int r)
{
	if (l == r) { tree[i].l = l; tree[i].r = r;tree[i].sum = v[l]; tree[i].mark = 0; return; }
	tree[i].l = l; tree[i].r = r;
	int mid = (l + r) / 2;
	build(2 * i, l, mid);
	build(2 * i + 1, mid + 1, r);
	tree[i].sum = tree[2 * i].sum + tree[2 * i + 1].sum;
	tree[i].mark = 0;
}
int find(int i, int dis)
{
	if (tree[i].l == tree[i].r) { return tree[i].sum+tree[i].mark; }
	int res = 0;
	res += tree[i].mark;
	if (tree[2*i].r >= dis) { res+=find(i * 2, dis); }
	if (tree[2*i+1].l <= dis) { res += find(i * 2 + 1, dis); }
	return res;
}
void add(int i,int l, int r, int k)
{
	if (tree[i].l >= l && tree[i].r <= r) { tree[i].mark += k; return; }
	if (tree[i * 2].r >= l) { add(i * 2, l, r, k); }
	if (tree[i * 2 + 1].l <= r) { add(i * 2 + 1, l , r, k); }
}
int main()
{
	/*FILE* fin;
	FILE* fout;
	fin = freopen("input.txt", "r", stdin);
	fout = freopen("output.txt", "w", stdout);*/
	int n;
	cin >> n;
	int t;
	cin >> t;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	build(1, 1, n);

	while (t--)
	{
		int op;
		cin >> op;
		switch (op)
		{
		case 1:
			int x, y, k;
			cin >> x >> y >> k;
			add(1, x, y, k);
			break;
		case 2:
			int d;
			cin >> d;
			cout << find(1, d)<<endl;
		}
	}
	/*fclose(stdin);
	fclose(stdout);*/
	return 0;
}
