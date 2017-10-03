#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#define ll long long
using namespace std;
int prime[1000008];
vector<ll> p;
void sieve()
{
    ll i,j,k,max=1000007;
    for(i=0;i<1000008;i++) prime[i]=1;
    k=(ll) ceil(sqrt(max));
    for(i=2;i<=k;i++)
    {
        if(prime[i])
        {
            p.push_back(i);
            for(j=i;j*i<=max;j++) prime[i*j]=0;
        }
    }
    for(;i<=max;i++) if(prime[i]) p.push_back(i);
}
int main()
{
    ll t,i,j,k,ans,n;
    cin>>t;
    sieve();
    for(ll c=1;c<=t;c++)
    {
        cin>>n;
        ans=1;
        k=(ll) floor(sqrt(n));
        for(i=0;i<p.size() && p[i]<=k;i++)
        {
            j=0;
            while(n%p[i]==0)
            {
                j++;
                n/=p[i];
            }
            ans*=(j+1);
            k=(ll) floor(sqrt(n));
        }
        if(n>1) ans*=2;
        printf("Case %lld: %lld\n",c,ans-1);
    }
    return 0;
}
