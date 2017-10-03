#include<iostream>
#include<algorithm>
#include<cstdio>
#define mod 1000000007
#define ll long long
using namespace std;

int main()
{
    ll t,cs=1,n,i,j,k;
    ll a[1005],b[1005],c[1005];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;i++) cin>>a[i];
        for(i=1;i<=n;i++) cin>>b[i];
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        ll cur=1;
        for(i=1;i<=n;i++)
        {
            while(a[cur]<=b[i] && cur<=n) cur++;
            c[i]=cur-1;
        }
        ll ans=1;
        for(i=1;i<=n;i++)
        {
            ans=(ans*(c[i]-i+1))%mod;
        }
        printf("Case %lld: %lld\n",cs++,ans);
    }
    return 0;
}
