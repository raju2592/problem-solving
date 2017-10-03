#include<iostream>
#include<cstdio>
#define ll long long
#define mod 1000000007
using namespace std;

ll fact[1005],nCr[1005][1005],dp[1005][1005];

void precal()
{
    ll i,j;
    fact[0]=1;
    for(i=1;i<=1000;i++) fact[i]=(fact[i-1]*i)%mod;

    nCr[0][0]=nCr[1][0]=nCr[1][1]=1;
    for(i=2;i<=1000;i++)
    {
        nCr[i][0]=nCr[i][i]=1;
        for(j=1;j<i;j++) nCr[i][j]=(nCr[i-1][j]+nCr[i-1][j-1])%mod;
    }

    for(i=0;i<=1000;i++) dp[0][i]=fact[i];
    for(i=1;i<=1000;i++)
    {
        for(j=0;j<=1000;j++)
        {
            dp[i][j]=(nCr[i-1][1]*dp[i-2][j+1])%mod;
            if(j) dp[i][j]=(dp[i][j]+(nCr[j][1]*dp[i-1][j])%mod)%mod;
        }
    }
}

int main()
{
    ll t,cs=1,i,j,k,n,m;
    precal();
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        printf("Case %lld: %lld\n",cs++,(nCr[m][k]*dp[m-k][n-m])%mod);
    }
    return 0;
}
