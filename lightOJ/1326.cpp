#include<iostream>
#include<cstdio>
using namespace std;
#define mod 10056
#define ll long long
int nCr[1005][1005];
void calc_ncr()
{
    int i,j;
    nCr[1][0]=nCr[1][1]=1;
    for(i=2;i<=1000;i++)
    {
        nCr[i][0]=1;
        for(j=1;j<=i;j++) nCr[i][j]=(nCr[i-1][j]+nCr[i-1][j-1])%mod;
    }
}
int main()
{
    int t,i,c,j,k,n;
    cin>>t;
    calc_ncr();
    int dp[1005];
    dp[1]=dp[0]=1;
    for(i=2;i<=1000;i++)
    {
        dp[i]=0;
        for(j=1;j<=i;j++) dp[i]=(dp[i]+nCr[i][j]*dp[i-j])%mod;
    }
    for(i=1;i<=t;i++)
    {
        cin>>n;
        printf("Case %d: %d\n",i,dp[n]);
    }
    return 0;
}
