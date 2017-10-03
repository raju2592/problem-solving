#include<stdio.h>
#include<string.h>
#define ll long long
ll dp[1005][1005];
ll min(ll i,ll j){return i<j?i:j;}
int main()
{
    ll c,n,i,j,k,l;
    char str[1005];
    scanf("%lld",&n);
    getchar();
    for(c=1;c<=n;c++)
    {
        gets(str);
        l=strlen(str);
        for(i=1;i<l;i++)
        {
            dp[i][i]=0;
            dp[i-1][i]=str[i-1]==str[i]?0:1;
        }
        dp[0][0]=0;
        for(i=3;i<=l;i++)
        {
            for(j=0;j<=l-i;j++)
            {
                dp[j][j+i-1]=dp[j+1][j+i-2];
                dp[j][j+i-1]+=str[j]==str[j+i-1]?0:1;
                dp[j][j+i-1]=min(dp[j][j+i-1],1+dp[j][j+i-2]);
                dp[j][j+i-1]=min(dp[j][j+i-1],1+dp[j+1][j+i-1]);
            }
        }
        printf("Case %lld: %lld\n",c,dp[0][l-1]);
    }
    return 0;
}
