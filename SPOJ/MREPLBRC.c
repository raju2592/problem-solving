#include<stdio.h>
#include<string.h>
#define ll long long
#define md 100000
ll dp[205][205];
void print(ll x)
{
    int i=0,j=x;
    while(j>0 && i<5)
    {
        j/=10;
        i++;
    }
    for(i=5-i;i>=1;i--) printf("0");
    printf("%lld",x);
}
int main()
{
    ll i,j,k,a,n;
    char str[250];
    scanf("%lld\n",&n);
    scanf("%s",str);
    memset(dp,0,sizeof(dp));
    int f=0;
    for(i=0;i<n-1;i++)
    {
        if(str[i]=='?' && str[i+1]=='?') dp[i][i+1]=3;
        else if(str[i]==')' || str[i]=='}' || str[i]==']') dp[i][i+1]=0;
        else if(str[i+1]=='(' || str[i+1]=='{' || str[i+1]=='[') dp[i][i+1]=0;
        else dp[i][i+1]=1;
        dp[i+1][i]=1;
    }
    dp[n][n-1]=1;
    for(i=4;i<=n;i+=2)
    {
        for(j=0;j<=n-i;j++)
        {
                if(str[j]=='(')
                {
                    for(k=j+1;k<=j+i-1;k++)
                    {
                        if(str[k]==')' || str[k]=='?')
						{
							dp[j][j+i-1]=dp[j][j+i-1]+dp[j+1][k-1]*dp[k+1][j+i-1];
							if(dp[j][j+i-1]>=md) f=1,dp[j][j+i-1]%=100000;
						}
                    }
                }
                else if(str[j]=='{')
                {
                    for(k=j+1;k<=j+i-1;k++)
                    {
                        if(str[k]=='}' || str[k]=='?')
						{
                            dp[j][j+i-1]=dp[j][j+i-1]+dp[j+1][k-1]*dp[k+1][j+i-1];
							if(dp[j][j+i-1]>=md) f=1,dp[j][j+i-1]%=100000;
						}
                    }
                }
                else if(str[j]=='[')
                {
                    for(k=j+1;k<=j+i-1;k++)
                    {
                        if(str[k]==']' || str[k]=='?')
						{

							dp[j][j+i-1]=dp[j][j+i-1]+dp[j+1][k-1]*dp[k+1][j+i-1];
							if(dp[j][j+i-1]>=md) f=1,dp[j][j+i-1]%=100000;
						}
                    }
                }
                else if(str[j]=='?')
                {
                    for(k=j+1;k<=j+i-1;k++)
                    {
                        if(str[k]==')' || str[k]=='}' || str[k]==']')
						{

							dp[j][j+i-1]=dp[j][j+i-1]+dp[j+1][k-1]*dp[k+1][j+i-1];
							if(dp[j][j+i-1]>=md) f=1,dp[j][j+i-1]%=100000;
						}
                        else if(str[k]=='?')
						{

							dp[j][j+i-1]=dp[j][j+i-1]+3*(dp[j+1][k-1]*dp[k+1][j+i-1]);
							if(dp[j][j+i-1]>=md) f=1,dp[j][j+i-1]%=100000;
						}
                    }
                }

        }
    }
    if(!f) printf("%lld\n",dp[0][n-1]);
    else print(dp[0][n-1]);
    puts("");
    return 0;
}
