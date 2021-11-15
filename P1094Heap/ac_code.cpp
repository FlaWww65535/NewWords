#include<iostream>
using namespace std;
const long long MAXN = 10000;
long long heap[4*MAXN];
long long cnt = 0;
void add(int x)
{
    heap[++cnt] = x;
    long long now = cnt;
    while (heap[now / 2] > heap[now] && now != 1) {
        swap(heap[now], heap[now / 2]);
        now /= 2;
    }
}
void del()
{
    swap(heap[1], heap[cnt--]);
    long long now = 1;
    while (now * 2 <= cnt)
    {
        long long t = now * 2;
        if (heap[now * 2 + 1] < heap[now * 2] && (now * 2 + 1) <= cnt) { t++; }
        if (heap[now] <= heap[t]) { break; }
        swap(heap[now], heap[t]);
        now = t;
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        long long m;
        cin >> m;
        add(m);
    }
    long long sum = 0;
    while (cnt > 1)
    {
        int a = heap[1];
        del();
        int b = heap[1];
        del();
        sum += a + b;
        add(a + b);
    }

    cout << sum;
    return 0;
}
