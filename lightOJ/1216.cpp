#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
#define pi acos(-1)
int main()
{
    int a,b,c,d,t,r1,r2,h,p;
    cin>>t;
    double R1,ans;
    for(c=1;c<=t;c++)
    {
        cin>>r1>>r2>>h>>p;
        R1=r1-(double) ((r1-r2)*(h-p))/h;
        ans= (double) (pi*p*(R1*R1+R1*r2+r2*r2))/3;
        printf("Case %d: %.10lf\n",c,ans);
    }
    return 0;
}
