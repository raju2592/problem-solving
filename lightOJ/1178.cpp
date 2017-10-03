#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,cs=1;
    double a,b,c,d;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>d;
        if(a<c) swap(a,c);
        double s=(a-c+b+d)/2;
        double area1=sqrt(s*(s-a+c)*(s-b)*(s-d));
        double h=2*area1/(a-c);
        double area2=c*h;
        printf("Case %d: %.10lf\n",cs++,area1+area2);
    }
    return 0;
}
