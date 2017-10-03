#include<bits/stdc++.h>
using namespace std;

const double pi=acos(-1);

int main()
{
    int t,cs=1;
    double r1,r2,r3;
    cin>>t;
    while(t--)
    {
        cin>>r1>>r2>>r3;
        double a=r1+r2,b=r1+r3,c=r2+r3;
        double s=(a+b+c)/2;
        double area=sqrt(s*(s-a)*(s-b)*(s-c));
        double angle1=acos((a*a+b*b-c*c)/(2*a*b));
        double angle2=acos((a*a+c*c-b*b)/(2*a*c));
        double angle3=acos((c*c+b*b-a*a)/(2*c*b));
        area-=r1*r1*angle1/2+r2*r2*angle2/2+r3*r3*angle3/2;
        printf("Case %d: %.10lf\n",cs++,area);
    }
    return 0;
}
