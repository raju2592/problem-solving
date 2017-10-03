#include<stdio.h>
#define ll long long
#define mod 1000000007

ll dp[300][55],nCr[55][55];

void calc()
{
    ll i,j,k;
    nCr[0][0]=nCr[1][0]=nCr[1][1]=1;
    for(i=2;i<=52;i++)
    {
        nCr[i][0]=nCr[i][i]=1;
        for(j=1;j<i;j++) nCr[i][j]=(nCr[i-1][j]+nCr[i-1][j-1])%mod;
    }

    dp[0][0]=1;
    for(i=1;i<=50;i++) dp[0][i]=0;
    for(i=1;i<=200;i++)
    {
        dp[i][0]=0;
        for(j=1;j<=50;j++) dp[i][j]=(j*(dp[i-1][j-1]+dp[i-1][j]))%mod;
    }
}

ll bigmod(ll b,ll p,ll m)
{
    ll x;
    if(p==0) return 1;
    x=bigmod(b,p/2,m);
    if(p%2) return ((x*(ll)x)%m*(ll)b)%m;
    else return (x*x)%m;
}
int main()
{
    ll t,cs=1,i,j,k,m,n,evn,x,y,ans;
    calc();
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld %lld",&n,&m,&k);
        x=((m+1)*(n+1))/2;
        y=(m+1)*(n+1)-x;
        ans=0;
        for(i=0;i<=k;i++)
        {
            ans=(ans+((nCr[k][i]*dp[x][i])%mod*bigmod(k-i,y,mod)%mod))%mod;
        }
        printf("Case %lld: %lld\n",cs++,ans);
    }
    return 0;
}
