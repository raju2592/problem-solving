#include<iostream>
#include<algorithm>
#define ll long
#define INF 1000000000
using namespace std;
ll min(ll i,ll j) {return i<j?i:j;}
ll dp[505][505];
int main()
{
    ll n,i,j,k,l;
    int arr[505];
    cin>>n>>k;
    for(i=1;i<=n;i++) cin>>arr[i];
    ll tz=0,to=0;
    for(i=n;i>=1;i--)
    {
        if(arr[i]==1) to++;
        else tz++;
        dp[i][1]=tz*to;
    }
    for(i=2;i<=k;i++)
    {
        for(j=1;j<=n-i+1;j++)
        {
            dp[j][i]=INF;
            ll os=0,zs=0;
            for(l=j;l<n-i+2;l++)
            {
                if(arr[l]==1) os++;
                else zs++;
                dp[j][i]=min(dp[j][i],os*zs+dp[l+1][i-1]);
            }
        }
    }
    cout<<dp[1][k];
    return 0;
}
