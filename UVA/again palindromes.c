#include<stdio.h>
#include<string.h>
#define ll long long
int main()
{
    ll t,i,j,k,l,dp[100][100];
    char str[100];
    scanf("%lld",&t);
    getchar();
    while(t--)
    {
        gets(str);
        l=strlen(str);
        for(i=0;i<l;i++)
        {
            dp[i][i]=1;
            dp[i+1][i]=1;
        }
        for(j=2;j<=l;j++)
        {
            for(i=0;i<=l-j;i++)
            {
                dp[i][i+j-1]=dp[i+1][i+j-1]+1;
                for(k=i+1;k<=i+j-1;k++)
                {
                    if(str[k]==str[i])
                    {
                        dp[i][i+j-1]+=dp[i+1][k-1];
                        if(k!=i+1) dp[i][i+j-1]+=1;
                    }
                }
            }
        }
        printf("%lld\n",dp[0][l-1]);
    }
    return 0;
}
