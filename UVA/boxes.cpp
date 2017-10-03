#include<iostream>
#include<utility>
#include<algorithm>
#include<cstring>
using namespace std;
#define fi first
#define se second
int dp[3005][1005],n;
pair <int,int> arr[1005];
int calc(int cap,int strt)
{
    if(dp[cap][strt]!=-1) return dp[cap][strt];
    if(strt>n) return 0;
    if(cap==0) return 0;
    int ans=0;
    if(cap>=arr[strt].fi) ans=1+calc(min(cap-arr[strt].fi,arr[strt].se),strt+1);
    ans=max(ans,calc(cap,strt+1));
    return dp[cap][strt]=ans;
}
int main()
{
   int i,j,k,ans;
   while(1)
   {
       cin>>n;
       if(n==0) break;
       for(i=1;i<=n;i++) cin>>arr[i].fi>>arr[i].se;
       ans=0;
       memset(dp,-1,sizeof(dp));
       for(i=1;i<=n;i++) ans=max(ans,1+calc(arr[i].se,i+1));
       cout<<ans<<endl;
   }
   return 0;
}
