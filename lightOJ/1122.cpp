#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int mmabs(int j)
{
    if(j>=0) return j;
    else return -j;
}
int main()
{
    int t,i,j,k,n,m,c,arr[10];
    int dp[10][15];
    cin>>t;
    for(c=1;c<=t;c++)
    {
        cin>>m>>n;
        for(i=0;i<m;i++) cin>>arr[i];
        for(i=0;i<m;i++) dp[i][1]=1;
        for(i=2;i<=n;i++)
        {
            for(j=0;j<m;j++)
            {
                dp[j][i]=0;
                for(k=0;k<m;k++)
                {
                    if(mmabs(arr[j]-arr[k])<=2) dp[j][i]+=dp[k][i-1];
                }
            }
        }
        int ans=0;
        for(i=0;i<m;i++) ans+=dp[i][n];
        printf("Case %d: %d\n",c,ans);
    }
    return 0;
}
