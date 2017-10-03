#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll long long
#define INF 500000
ll max(ll i,ll j) {return i>j?i:j;}
ll dp[1005][55];

int main()
{
    ll t,i,j,k,b,m,n;
    cin>>t;
    for(i=1;i<=50;i++) dp[1][i]=1,dp[0][i]=0;
    for(i=2;i<=1000;i++)
    {
        dp[i][1]=i;
        for(j=2;j<=50;j++)
        {
            dp[i][j]=1+dp[i-1][j-1];
            for(k=i-1;k>=1;k--)
            {
                if(max(1+dp[k-1][j-1],1+dp[i-k][j])<dp[i][j]) dp[i][j]=max(1+dp[k-1][j-1],1+dp[i-k][j]);
            }
        }
    }
    while(t--)
    {
        cin>>n>>b>>m;
        cout<<n<<' '<<dp[m][b]<<endl;
    }
    return 0;
}
