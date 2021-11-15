#include<iostream>
#include<cstdio>
using namespace std;
int  qpow(int n, int t,int p)
{
	long long  temp = n%p;
	long long ans = 1;
	if (t == 1) { return temp % p; }
	while (t > 1)
	{
		if (t % 2)
		{

			ans *= temp;
			ans %= p;			
			temp = ((temp % p) * (temp % p)) % p;
			t /= 2;
		}
		else
		{
			temp = ((temp % p) * (temp % p)) % p;
			t /= 2;
		}
	}
	return ans*temp%p;
}
int main()
{
	int n,t,p;
	cin >> n >> t >> p;
	int ans= qpow(n, t, p);
	printf("%d^%d mod %d=%d", n, t, p, ans);
	return 0;
}
