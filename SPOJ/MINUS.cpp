#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int n,m,arr[140];
int dp[2][10005][105];

int calc(int sign,int sum,int st)
{
    if(dp[sign][sum][st]!=-1) return dp[sign][sum][st];
    int val=sign==1?-sum:sum;
    if(st==n+1)
    {
        if(val==m) return 0;
        else return 2;
    }
    int tmp=val+arr[st],sn=0;
    if(tmp<0) sn=1,tmp=-tmp;
    if(calc(sn,tmp,st+1)<2) return dp[sign][sum][st]=0;
    tmp=val-arr[st],sn=0;
    if(tmp<0) sn=1,tmp=-tmp;
    if(calc(sn,tmp,st+1)<2) return dp[sign][sum][st]=1;
    return dp[sign][sum][st]=2;
}
int main()
{
    int t,i,j,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=n;i++) cin>>arr[i];
        if(n==1)
        {
            cout<<endl;
            continue;
        }
        else if(n==2)
        {
            cout<<1<<endl<<endl;continue;
        }
        memset(dp,-1,sizeof(dp));
        if(arr[1]-arr[2]>=0) calc(0,arr[1]-arr[2],3);
        else calc(1,arr[2]-arr[1],3);
        int pmns=2,sn,val;
        if(arr[1]>=arr[2]) sn=0,val=arr[1]-arr[2];
        else sn=1,val=arr[2]-arr[1];
        vector<int> out;
        for(i=3;i<=n;i++)
        {
            if(dp[sn][val][i]==0)
            {
                out.push_back(pmns);
                if(sn) val=-val+arr[i];
                else val=val+arr[i];
                if(val<0) sn=1,val=-val;
                else sn=0;
            }
            else
            {
                if(sn) val=-val-arr[i];
                else val=val-arr[i];
                if(val<0) sn=1,val=-val;
                else sn=0;
                pmns=i;
            }
        }
        for(i=out.size()-1;i>=0;i--) cout<<out[i]<<endl;
        for(i=1;i+out.size()<n;i++) cout<<1<<endl;
        cout<<endl;
    }
}
