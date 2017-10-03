#include<iostream>
#include<cstdio>
#include<cmath>
#define eps 1e-9
#define pi acos(-1)
using namespace std;

int main()
{
    double a,b,c,r,theta,s;
    int t,ox,oy,ax,ay,bx,by;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        cin>>ox>>oy>>ax>>ay>>bx>>by;
        ax-=ox;
        bx-=ox;
        ay-=oy;
        by-=oy;
        a=atan2((double)ay,(double)ax);
        b=atan2((double)by,(double)bx);
        r=sqrt(ax*ax+ay*ay);
        theta=a-b;
        theta=abs(theta);
        if(theta>pi) theta=2*pi-theta;
        s=r*theta;
        printf("Case %d: %.10lf\n",k,s);
    }
    return 0;
}
