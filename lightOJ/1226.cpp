#include<iostream>
#include<algorithm>
#include<cstdio>
#define MAX 1000006
#define mod 1000000007LL
#define ll long long
using namespace std;

ll fact[MAX+10];
ll Min(ll i,ll j){return i<j?i:j;}
void Extended_Euclid(ll a,ll b,ll *d,ll *x,ll *y)
{
    ll x1,y1;
    if(b==0)
    {
        *d=a;
        *x=1;
        *y=0;
        return;
    }
    Extended_Euclid(b,a%b,d,&x1,&y1);
    *x=y1;
    *y=x1-(a/b)*y1;
    return;

}
ll MOD(ll a,ll b)
{
    return (a%b+b)%b;
}
ll nCr(ll n,ll r)
{
    ll a=fact[r];
    ll b=fact[n-r];
    a=(a*(ll)b)%mod;
    ll d,x,y;
    Extended_Euclid(a,mod,&d,&x,&y);
    x=MOD(x,mod);
    ll ret=(fact[n]*(ll)x)%mod;
    return ret;
}
ll bigmod(ll b,ll p,ll m)
{
    if(p==0) return 1;
    ll x=bigmod(b,p/2,m);
    if(p%2) return ((x*(ll)x)%m*(ll)b)%m;
    else return (x*x)%m;
}
void precal()
{
    fact[0]=fact[1]=1;
    for(ll i=2;i<MAX+5;i++) fact[i]=(fact[i-1]*(ll)i)%mod;
}

int main()
{
    ll t,cs=1,n,arr[1005],i,j,k,l,ans;
    cin>>t;
    precal();
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;i++) cin>>arr[i];
        k=0;
        ans=1;
        for(i=1;i<=n;i++)
        {
            ans=(ans*nCr(k+arr[i]-1,k))%mod;
            k+=arr[i];
        }
        printf("Case %lld: %lld\n",cs++,ans);
    }
    return 0;
}
