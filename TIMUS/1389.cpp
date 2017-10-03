#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
vector<vector<pair<int,int> > > tr;
vector<int> p;
int dp[2][100005];
pair<int,int> ch[2][100005];
int calc(int f,int n)
{
    int tot;
    if(dp[f][n]!=-1) return dp[f][n];
    tot=0;
    int i,j,k;
    for(i=0;i<tr[n].size();i++)
    {
        if(tr[n][i].first!=p[n])
        {
            p[tr[n][i].first]=n;
            tot+=calc(0,tr[n][i].first);
        }
    }
    ch[f][n]=make_pair(0,0);
    dp[f][n]=tot;
    if(f==1)
    {
        return dp[f][n];
    }
    else
    {
        for(i=0;i<tr[n].size();i++)
        {
            if(tr[n][i].first!=p[n] && tot-calc(0,tr[n][i].first)+calc(1,tr[n][i].first)+1>dp[f][n])
            {
                dp[f][n]=tot-calc(0,tr[n][i].first)+calc(1,tr[n][i].first)+1;
                if(tr[n][i].second) ch[f][n]=make_pair(tr[n][i].first,1);
                else ch[f][n]=make_pair(tr[n][i].first,0);
            }
        }
        return dp[f][n];
    }
}
void print(int f,int n)
{
    for(int i=0;i<tr[n].size();i++)
    {
        if(tr[n][i].first==p[n]) continue;
        if(ch[f][n].first==tr[n][i].first)
        {
            if(tr[n][i].second) cout<<n<<' '<<tr[n][i].first<<endl;
            else cout<<tr[n][i].first<<' '<<n<<endl;
            print(1,tr[n][i].first);
        }
        else print(0,tr[n][i].first);
    }
}
int main()
{
    int i,j,k,m,n;
    cin>>n>>m;
    tr.resize(n+1);
    while(m--)
    {
        cin>>j>>k;
        tr[j].push_back(make_pair(k,1));
        tr[k].push_back(make_pair(j,0));
    }
    p.resize(n+1);
    for(i=1;i<=n;i++) p[i]=-1;
    memset(dp,-1,sizeof(dp));
    calc(0,1);
    cout<<dp[0][1]<<endl;
    print(0,1);
    return 0;
}
