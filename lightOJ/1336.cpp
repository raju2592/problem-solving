#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;

int main()
{
    ll t,n,i,j,k,cs=0,oddsig;
    cin>>t;
    while(t--)
    {
        cin>>n;
        oddsig=0;
        for(i=1;i*i<=n;i+=2)
        {
            oddsig++;
            j=i*i;
            while(j*2<=n)
            {
                oddsig++;
                j*=2;
            }
        }
        printf("Case %lld: %lld\n",++cs,n-oddsig);
    }
    return 0;
}
