
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 205;
const double eps=1e-8;
typedef double TYPE;

struct point
{
	TYPE x;
	TYPE y;
	point() :x(0), y(0) {}
	point(TYPE _x, TYPE _y) :x(_x), y(_y) {}
	point operator+(point p)
	{
		return point(x+p.x,y+p.y);
	}
	point operator-(point p)
	{
		return point(x - p.x, y - p.y);
	}
	TYPE operator *(const point& p)
	{
		return x * p.x + y * p.y;
	}
	point operator*(TYPE s)
	{
		return point(x*s,y*s);
	}
	TYPE operator ^(const point& p)
	{
		return x * p.y - y * p.x;
	}

};

double dis(point p)
{
	return sqrt(p.x*p.x+p.y*p.y);
}
struct line
{
	point a;
	point b;
	line() {}
	line(point _a, point _b) :a(_a), b(_b) {}
	double len()
	{
		return dis(a-b);
	}
	bool operator<(line p)
	{
		return (a.x<p.a.x);
	}
};
point P[MAXN];
line L[MAXN];
int T;
int judge(line s,line p)
{
	point a=s.a,b=s.b,c=p.a,d=p.b;
	if(((a-c)^(a-d))==((b-c)^(b-d)))
	{
		if(!((a-c)^(a-d)))return 0;
		else return 1;
	}
	else return 2;
}
point inter(line s,line p)
{
	point a=s.a,b=s.b,c=p.a,d=p.b;
	double p0=(d-a)^(c-a);
	double p1=(d-b)^(c-b);
	point x=a+(b-a)*(p1-p0);
	return x;
}
int main()
{
	cin>>T;
	printf("INTERSECTING LINES OUTPUT\n");
	while(T--)
	{
		double x11,y11,x22,y22;
		scanf("%lf%lf%lf%lf",&x11,&y11,&x22,&y22);
		line L1(point(x11,y11),point(x22,y22));
		scanf("%lf%lf%lf%lf",&x11,&y11,&x22,&y22);
		line L2(point(x11,y11),point(x22,y22));
		switch(judge(L1,L2))
		{
			case 0:
			printf("LINE");
			break;
			case 1:
			printf("NONE");
			break;
			case 2:
			point x=inter(L1,L2);
			printf("POINT %.2lf %.2lf",x.x,x.y);
			break;
		}
	}
	return 0;
}