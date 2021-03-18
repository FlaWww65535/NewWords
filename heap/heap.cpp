#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 1e6;
inline int fread()
{
	int a = 0;
	bool sign = 0;
	char ch = getchar();
	while (!isdigit(ch)) { sign |= ch == '-'; ch = getchar(); }
	while (isdigit(ch)) { a = a * 10 + ch - '0'; ch = getchar(); }
	return sign ? -a : a;
}
void swap(int& x, int& y) { int temp = x; x = y; y = temp; }
int max(int& x, int& y) { return x > y ? x : y; }
int heap[MAXN];
int hsize = 0;
void hadd(int x)
{
	heap[++hsize] = x;
	int now = hsize;
	while (heap[now] < heap[now / 2] && now>1) { swap(heap[now], heap[now / 2]); now /= 2; }
}
void hdelete()
{
	swap(heap[1], heap[hsize--]);
	int now = 1;
	while (now * 2 <= hsize)
	{
		int t = 2 * now;
		if (t + 1 <= hsize && heap[t + 1] < heap[t])t++;
		if (heap[t] > heap[now])break;
		swap(heap[t], heap[now]);
		now = t;
	}
}
int main()
{
	int n;
	n = fread();
	for (int i = 0; i < n; i++)
	{
		int op;
		op = fread();
		switch (op)
		{
		case 1:
		{int q = fread();
		hadd(q);
		break; }
		case 2:
			printf("%d\n", hsize == 0 ? 0 : heap[1]);
			break;
		case 3:
			hdelete();
		}
	}
	return 0;
}