#include<iostream>
#include<cstdio>
using namespace std;
int max(int x, int y) { return x > y ? x : y; }
inline int fread()
{
	int ans = 0;
	char ch;
	int flag = 1;
	ch = getchar();
	while (ch < '0' || ch>'9')
	{
		if (ch == '-') { flag = -1; }
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		ans = ans * 10 + ch - '0';
		ch = getchar();
	}
	return flag * ans;
}
const int MAXN = 1e5 + 50;
int logbx[MAXN];
int n, m;
void pre()
{
	logbx[0] = -1;//初始项
	for (int i = 1; i <= n; i++)
	{
		logbx[i] = logbx[i / 2] + 1;//递推
	}
}
int f[MAXN][20];//logn不大于20
int main()
{
	n = fread(); m = fread();
	for (int i = 1; i <= n; i++)
	{
		f[i][0] = fread();
	}
	pre();//预处理log数组
	for (int j = 1; j <= logbx[n]; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)//注意i，j的左右边界
		{
			f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
		}
	int l, r, s;
	for (int i = 0; i < m; i++)
	{
		l = fread(); r = fread();
		s = logbx[r - l + 1];//区间所包含的最大的2的幂次，即用于覆盖的两区间的长度
		printf("%d\n", max(f[l][s], f[r - (1 << s) + 1][s]));//没有关闭stdout的情况下printf更快
		//两区间的长度要注意
		//重复贡献问题，即使有重叠区域也没关系
	}
	return 0;
}
