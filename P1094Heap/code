#include<iostream>
using namespace std;
const int MAXN=10000;
int heap[4*MAXN];
int cnt=0;
void add(int x)
{
    heap[++cnt] = x;
    int now = cnt;
    while(heap[now/2]>now&&now>1){
        swap(heap[now], heap[now / 2]);
        now /= 2;
    }
}
void del()
{
    swap(heap[1],heap[cnt--]);
    int now = 1;
    while(now*2<=cnt)
    {
        int t = now * 2;
        if(heap[now*2+1]>heap[now*2]&&now*2+1<=cnt){t++;}
        if(heap[now]<=heap[t]){break;}
        swap(heap[now], heap[t]);
        now = t;
    }
}
int main()
{
    FILE *fpRead=fopen("input.txt","r");
    FILE *fpWrite=fopen("output.txt","w");
    if(fpRead== NULL){  
        return 0;  
    } 
    int n;
    fscanf(fpRead,"%d", &n);
    for (int i = 1; i <= n;i++)
    {
        int m;
        fscanf(fpRead,"%d", &m);
        add(m);
    }
    long long sum = 0;
    while(cnt>1)
    {
        int a = heap[1];
        del();
        int b=heap[1];
        del();
        sum += (a + b);
        add(a + b);
        fprintf(fpWrite, "%lld ", sum); 
    }
    fprintf(fpWrite,"%lld",sum); 
    return 0;
}
