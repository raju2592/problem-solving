#include<stdio.h>
int main()
{
    int i,j,m,n,mat[12][102],choice[12][102],optim_row,next;
    long long dp[12][102];
    while(scanf("%d %d",&m,&n)!=EOF)
    {
        for(i=0;i<m;i++)
            for(j=0;j<n;j++) scanf("%d",&mat[i][j]);
        for(i=0;i<m;i++)
        {
            dp[i][n-1]=mat[i][n-1];
            choice[i][n-1]=-1;
        }
        for(i=n-2;i>=0;i--)
        {
            for(j=0;j<m;j++)
            {
                dp[j][i]=dp[j][i+1];
                choice[j][i]=j;
                if(dp[(j+1)%m][i+1]<dp[j][i])
                {
                    dp[j][i]=dp[(j+1)%m][i+1];
                    choice[j][i]=(j+1)%m;
                }
                else if(dp[(j+1)%m][i+1]==dp[j][i] && (j+1)%m<choice[j][i])
                {
                    dp[j][i]=dp[(j+1)%m][i+1];
                    choice[j][i]=(j+1)%m;
                }
                if(dp[(j-1+m)%m][i+1]<dp[j][i])
                {
                    dp[j][i]=dp[(j-1+m)%m][i+1];
                    choice[j][i]=(j-1+m)%m;
                }
                else if(dp[(j-1+m)%m][i+1]==dp[j][i] && (j-1+m)%m<choice[j][i])
                {
                    dp[j][i]=dp[(j-1+m)%m][i+1];
                    choice[j][i]=(j-1+m)%m;
                }
                dp[j][i]+=mat[j][i];
            }
        }
        optim_row=0;
        for(i=1;i<m;i++)
        {
            if(dp[i][0]<dp[optim_row][0]) optim_row=i;
        }
        printf("%d",optim_row+1);
        next=choice[optim_row][0];
        i=1;
        while(next!=-1)
        {
            printf(" %d",next+1);
            next=choice[next][i];
            i++;
        }
        printf("\n");
        printf("%lld\n",dp[optim_row][0]);

    }
    return 0;
}
