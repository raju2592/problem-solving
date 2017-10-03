#include<iostream>
#define ll long
using namespace std;
int main()
{
    ll n,dp[2][50],i;
    cin>>n;
    dp[0][n]=dp[1][n]=1;
    dp[0][n+1]=dp[1][n+1]=1;
    for(i=n-1;i>=2;i--)
    {
        dp[0][i]=dp[1][i+1];
        //if(i+3<=n+1) dp[0][i]+=dp[0][i+3];
        if(i+2<=n+1) dp[0][i]+=dp[1][i+2];
        dp[1][i]=dp[0][i+1];
        //if(i+3<=n+1) dp[1][i]+=dp[1][i+3];
        if(i+2<=n+1) dp[1][i]+=dp[0][i+2];
    }
    //cout<<dp[1][1]+dp[0][1]<<endl;
    ll ans=0;
    ans+=dp[1][2]+dp[0][2];
    //if(3<=n) ans+=dp[1][4]+dp[0][4];
    cout<<ans;
    return 0;
}
