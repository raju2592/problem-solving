#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int max(int i,int j){return i>j?i:j;}
int ind[20][20],n;
int dp[18][70000];
int calc(int st,int mask)
{
    if(dp[st][mask]!=-1) return dp[st][mask];
    if(st==n) return 0;
    int i,j,k;
    dp[st][mask]=-1;
    int tmp;
    for(i=0;i<n;i++)
    {
        tmp=0;
        if(!(1<<i & mask))
        {
            tmp+=ind[st][i];
            tmp+=calc(st+1,mask | (1<<i));
        }
        dp[st][mask]=max(dp[st][mask],tmp);
    }
    return dp[st][mask];
}
int main()
{
    int i,j,k,t,c;
    cin>>t;
    for(c=1;c<=t;c++)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++) cin>>ind[i][j];
        }
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %d\n",c,calc(0,0));
    }
    return 0;
}
