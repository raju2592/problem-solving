#include<stdio.h>
#define ull unsigned long long
ull dp[2][55][55];

void calc()
{
    ull i,j,k;
    dp[1][0][1]=1;
    dp[1][1][1]=0;
    dp[0][0][1]=0;
    dp[0][1][1]=1;
    for(i=2;i<=50;i++)
    {
        for(j=0;j<=i;j++)
        {
            dp[0][j][i]=0;
            for(k=1;k<=j;k++) dp[0][j][i]+=dp[1][k-1][i-1];
            dp[1][j][i]=0;
            for(k=j+1;k<=i;k++) dp[1][j][i]+=dp[0][k-1][i-1];
        }
    }
}
int main()
{
    ull t,cs=1,n,m;
    calc();
    scanf("%llu",&t);
    while(t--)
    {
        scanf("%llu %llu",&n,&m);
        if(m==1 && n<3) printf("Case %llu: 1\n",cs++);
        else
        {
            if(m==1) printf("Case %llu: %llu\n",cs++,dp[0][1][n-2]);
            else printf("Case %llu: %llu\n",cs++,dp[0][m-1][n-1]);
        }
    }
    return 0;
}
