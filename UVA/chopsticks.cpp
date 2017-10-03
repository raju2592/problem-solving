#include<iostream>
#include<vector>
#include<cstdio>
#define INF 92233729000000

using namespace std;
int main()
{
    int t,i,j,n,k,ct[5005],temp;
    vector<vector<long long> > dp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&k,&n);
        dp.resize(k+10);
        for(i=0;i<dp.size();i++)
        {
            dp[i].resize(n+5);
            dp[i].resize(n+5);
        }
        for(i=0;i<n;i++) scanf("%d",&ct[i]);
        dp[1][n-3]=(ct[n-2]-ct[n-3])*(ct[n-2]-ct[n-3]);
        for(i=2;i<dp.size();i++) dp[i][n-3]=INF;
        for(i=n-4;i>=0;i--)
        {
            for(j=1;j<k+9;j++)
            {
                if(3*j>n-i) dp[j][i]=INF;
                else
                {
                    dp[j][i]=dp[j][i+1];
                    temp=dp[j-1][i+2]+(ct[i+1]-ct[i])*(ct[i+1]-ct[i]);
                    if(temp<dp[j][i]) dp[j][i]=temp;
                }
            }
        }
        printf("%lld\n",dp[k+8][0]);

    }
    return 0;
}
