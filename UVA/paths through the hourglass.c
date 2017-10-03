#include<stdio.h>
int main()
{
    int hg[45][25],N,S,i,j,k,L,f,rem;
    long long int dp[41][21][502],ans;

    while(1)
    {
        scanf("%d %d",&N,&S);
        if(N==0 && S==0) break;
        for(i=0;i<=N-1;i++)
        {
            for(j=0;j<N-i;j++) scanf("%d",&hg[i][j]);
        }
        for(j=2;i<2*N-1;i++,j++)
        {
            for(k=0;k<j;k++) scanf("%d",&hg[i][k]);
        }
        for(i=0;i<41;i++)
        {
            for(j=0;j<21;j++)
            {
                for(k=0;k<502;k++)
                {
                    dp[i][j][k]=0;

                }
            }
        }
        k=2*N-2;
        for(i=0;i<N;i++)
        {
            for(j=0;j<=S;j++)
            {
                if(j!=hg[k][i]) dp[k][i][j]=0;
                else dp[k][i][j] =1;
            }
        }
        for(i=2*N-3,L=N-1;i>=N-1;i--,L--)
        {
            for(j=0;j<L;j++)
            {
                for(k=0;k<=S;k++)
                {
                    if(k>=hg[i][j])
                    {
                        dp[i][j][k]=dp[i+1][j][k-hg[i][j]]+dp[i+1][j+1][k-hg[i][j]];
                    }
                }
            }
        }
        L=2;
        while(i>=0)
        {
            for(j=0;j<L;j++)
            {
                for(k=0;k<=S;k++)
                {
                    if(k>=hg[i][j])
                    {
                        if(j!=0 && j!=L-1)
                        {
                            dp[i][j][k]=dp[i+1][j-1][k-hg[i][j]]+dp[i+1][j][k-hg[i][j]];
                        }
                        else if(j==L-1)
                        {
                            dp[i][j][k]=dp[i+1][j-1][k-hg[i][j]];
                        }
                        else if(j==0)
                        {
                            dp[i][j][k]=dp[i+1][j][k-hg[i][j]];
                        }
                    }
                }
            }
            i--;
			L++;
        }
        f=-1;
        ans=0;
        for(i=0;i<N;i++)
        {
            ans+=dp[0][i][S];
            if(dp[0][i][S]!=0 && f==-1)
            {
                f=i;
            }
        }
        printf("%lld\n",ans);
        if(f!=-1)
        {
            printf("%d ",f);
            rem=S;
            for(i=0,L=N;i<N-1;i++,L--)
            {
                rem=rem-hg[i][f];
                if(f!=0 && f!=L-1)
                {
                    if(dp[i+1][f-1][rem]!=0)
                    {
                        printf("L");
                        f=f-1;
                    }
                    else
                    {
                        printf("R");
                    }
                }
                else if(f==0)
                {
                    printf("R");
                }
                else if(f=L-1)
                {
                    printf("L");
                    f=f-1;
                }
            }
            while(i<=2*N-3)
            {
                rem=rem-hg[i][f];
                if(dp[i+1][f][rem]!=0)
                {
                    printf("L");
                }
                else
                {
                    printf("R");
                    f=f+1;
                }
                i++;
            }
        }
        printf("\n");
    }
    return 0;
}

