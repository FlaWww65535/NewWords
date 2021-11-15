#include<iostream>
using namespace std;
const int MAXN = 5000, MAXM = 200000;
int cnt = 0;
int head[MAXN], fa[MAXN];
int find(int x)
{
	if (fa[x] == x)return x;
	return fa[x] = find(fa[x]);
}
struct Edge
{
	int from, next, to;
	int len;
	bool operator>(Edge& y)
	{
		return y.len < this->len;
	}
	bool operator<(Edge& y)
	{
		return y > * this;
	}
}edge[MAXM];
bool visit[MAXN];
void addedge(int u, int v, int s)
{
	edge[++cnt].next = head[u];
	edge[cnt].from = u;
	edge[cnt].to = v;
	edge[cnt].len = s;
	head[u] = cnt;
}
void qsort(int l, int r, Edge a[])
{
	Edge mid = a[(l + r) / 2];
	int i = l, j = r;
	while (i <= j)
	{
		while (a[i] < mid)i++;
		while (a[j] > mid)j--;
		if (i <= j)
		{
			Edge temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++; j--;
		}
	}
	if (j > l)qsort(l, j, a);
	if (i < r)qsort(i, r, a);
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		addedge(x, y, z);
	}
	qsort(1, m, edge);
	for (int i = 1; i <= n; i++)
	{
		fa[i] = i;
	}
	//kruskal
	int sum = 0, num = 0;
	for (int i = 1; i <= m; i++)
	{
		int u = edge[i].from, v = edge[i].to;
		if (find(u) != find(v)) { fa[fa[u]] = v; sum += edge[i].len; num++; }
		if (num >= n - 1)break;
	}
	cout << sum;
	return 0;
}
