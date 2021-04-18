#include<iostream>
using namespace std;
const int MAXN = 1E5 + 5;
int fa[MAXN], dep[MAXN], siz[MAXN], son[MAXN];
int dfsn[MAXN], dfsk[MAXN],top[MAXN],val[MAXN];
int mod;
struct Edge
{
	int to;
	int next;
}edge[MAXN];
int cnt;
int num;
int head[MAXN];
void insert(int u, int v)
{
	edge[++cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt;
	edge[++cnt].to = u;
	edge[cnt].next = head[v];
	head[v] = cnt;
}
inline void dfs1(int x)
{
	dep[x] = dep[fa[x]] + 1;
	siz[x] = 1;
	for (int i = head[x]; i; i = edge[i].next)
	{
		int v = edge[i].to;
		if (fa[x] == v)continue;
		fa[v] = x;
		dfs1(v);	
		siz[x] += siz[v];
		if (siz[son[x]] < siz[v])son[x] = v;
	}
}
inline void dfs2(int x,int topf)
{
	top[x] = topf;
	dfsn[++num] = x; dfsk[x] = num;
	if (!son[x]) { return; }
	else
	{
		dfs2(son[x],topf);
		for (int i = head[x]; i; i=edge[i].next)
		{
			int v = edge[i].to;
			if (fa[x] == v||v==son[x])continue;
			dfs2(v, v);
		}
	}
}
//线段树部分
struct Tree
{
	int l;int r;
	long long sum; long long lz;
}tree[4*MAXN];
inline void push_up(int i)
{
	tree[i].sum = tree[i << 1].sum + tree[i << 1 | 1].sum;
	tree[i].sum %= mod;
}
inline void push_down(int i)
{
	tree[i << 1].lz += tree[i].lz;
	tree[i << 1].sum += tree[i << 1].lz * (tree[i << 1].r - tree[i << 1].l + 1);
	tree[i<<1].sum %= mod;
	tree[i << 1|1].lz += tree[i].lz;
	tree[i << 1|1].sum += tree[i << 1].lz * (tree[i << 1|1].r - tree[i << 1|1].l + 1);
	tree[i << 1|1].sum %= mod;
	tree[i].lz = 0;
}
inline void build(int i,int l,int r)
{
	tree[i].l = l; tree[i].r = r;
	tree[i].lz = 0;
	if (l == r) 
	{ 
		tree[i].sum = val[dfsn[l]]; 
		tree[i].sum %= mod;
		tree[i].lz = 0;
		return;
	}
	int mid = (l + r) / 2;
	build(i<<1, l, mid);
	build(i << 1 | 1, mid + 1, r);
	push_up(i);
}
inline void update(int i, int l, int r, long long k)
{
	if (tree[i].l >= l && tree[i].r <= r) { 
		tree[i].sum += (long long)(tree[i].r - tree[i].l + 1) * k;  tree[i].sum %= mod; tree[i].lz += k; tree[i].lz %= mod; return; 
	}
	push_down(i);
	if (tree[i<<1|1].l <= r) { update(i << 1 | 1, l, r, k); }
	if (tree[i<<1].r >=l) { update(i << 1, l, r, k); }
	push_up(i);
}
inline long long query(int i, int l, int r)
{
	if (tree[i].l >= l && tree[i].r <= r) {
		return tree[i].sum;
	}
	if (l > tree[i].r || r < tree[i].l) { return 0; }
	push_down(i);
	long long sum = 0;
	if (tree[i * 2].r >= l) {
		sum += query(i<<1, l, r); sum %= mod;
	}
	if (tree[i * 2 + 1].l <= r) {
		sum += query(i<<1|1, l, r); sum %= mod;
	}
	sum %= mod;
	return sum;
}
//树上路径
inline void change(int x, int y,long long k)
{
	while (top[x] != top[y])
	{
		if (dep[x] < dep[y]) { swap(x, y); }
 		update(1, dfsn[top[x]], dfsn[x], k);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) { swap(x, y); }
	update(1, dfsn[x], dfsn[y], k);
}
inline long long ask(int x, int y)
{
	long long res(0);
	while (top[x] != top[y])
	{
		if (dep[x] < dep[y]) { swap(x, y); }
		res += query(1, dfsn[top[x]], dfsn[x]);
		res %= mod;
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) { swap(x, y); }
	res += query(1, dfsn[x], dfsn[y]);
	res %= mod;
	return res;
}
int main()
{
	int n, m, r;
	cin >> n >> m >> r >> mod;
	for (int i = 1; i <= n; i++)
	{
		cin >> val[i];
	}
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		insert(u, v);
	}
	dfs1(r);
	dfs2(r,r);
	build(1, 1,n);
	while (m--)
	{
		int op, x, y;
		long long k;
		cin >> op;
		switch (op)
		{
		case 1:
			cin >> x >> y >> k;
			change(x, y, k);
			break;
		case 2:
			cin >> x >> y;
			cout << ask(x, y)<<endl;
			break;
		case 3:
			cin >> x >> k;
			update(1,dfsn[x], dfsn[x] + siz[x] - 1, k);
			break;
		case 4:
			cin >> x;
			cout << query(1, dfsn[x], dfsn[x] + siz[x] - 1)<<endl;
			break;
		}
	}
	return 0;
}
