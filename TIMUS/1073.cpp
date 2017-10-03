#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

int main()
{
    ll n,i,j,k;
    cin>>n;
    vector<ll> sq;
    for(i=1;i*i<=n;i++) sq.push_back(i*i);
    ll dp[60005];
    dp[1]=1;
    dp[0]=0;
    for(i=2;i<=n;i++)
    {
        dp[i]=6000000;
        for(j=0;j<sq.size() && sq[j]<=i;j++) dp[i]=min(dp[i],dp[i-sq[j]]+1);
    }
    cout<<dp[n];
    return 0;
}
