#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,cs=1;
    double ab,ac,bc,rat;
    cin>>t;
    while(t--)
    {
        cin>>ab>>ac>>bc>>rat;
        double r=sqrt(rat/(rat+1));
        printf("Case %d: %.10lf\n",cs++,ab*r);
    }
    return 0;
}
