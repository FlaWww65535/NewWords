#include<iostream>
using namespace std;
typedef long long ll;
const int MAXN = 5e5;
ll v[MAXN];
ll c[MAXN];
ll ans = 0;
void msort(int l, int r,ll a[])
{
	if (l >= r)return;
	int mid = (l + r) / 2;
	msort(l, mid,a);
	msort(mid + 1, r,a);
	int i = l, k = l, j = mid + 1;
	while (i <= mid && j <= r)
	{
		if (a[i] <= a[j])
		{
			c[k++] = a[i++];
		}
		else
		{
			c[k++] = a[j++];
			ans += mid - i + 1;
		}
	}
	while (i <= mid)
	{
		c[k++] = a[i++];
	}
	while (j <= r)
	{
		c[k++] = a[j++];
	}
	for (int t = l; t <= r; t++)
	{
		a[t] = c[t];	
	}
}
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> v[i];
	}
	msort(0, n - 1, v);
	cout << ans;
	return 0;
}
