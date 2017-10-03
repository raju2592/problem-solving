#include<stdio.h>

int dp[1005][1005];
int n,arr[1005];
int mabs(int x){return x<0?-x:x;}

int main()
{
    int i,j,x,cs=1;
    while(scanf("%d",&n))
    {
        if(n==0) break;
        for(i=1;i<=n;i++) scanf("%d",arr+i);
        for(i=1;i<n;i++)
        {
            dp[i][i+1]=mabs(arr[i]-arr[i+1]);
        }
        for(i=4;i<=n;i+=2)
        {
            for(j=1;j<=n-i+1;j++)
            {
                if(arr[j+1]>=arr[j+i-1]) dp[j][j+i-1]=dp[j+2][j+i-1]+arr[j]-arr[j+1];
                else dp[j][j+i-1]=dp[j+1][j+i-2]+arr[j]-arr[j+i-1];
                if(arr[j]>=arr[j+i-2]) x=dp[j+1][j+i-2]+arr[j+i-1]-arr[j];
                else x=dp[j][j+i-3]+arr[j+i-1]-arr[j+i-2];
                if(x>dp[j][j+i-1]) dp[j][j+i-1]=x;
            }
        }
        printf("In game %d, the greedy strategy might lose by as many as %d points.\n",cs++,dp[1][n]);
    }
    return 0;
}
