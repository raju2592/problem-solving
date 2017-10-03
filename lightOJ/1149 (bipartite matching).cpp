#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > gr;
int n,m;
int a[105],b[105];
int lft[105],rght[105];
int v[105];

bool dfs(int u)
{
    if(v[u]) return false;
    v[u]=true;
    for(int i=0;i<gr[u].size();i++)
    {
        int x=gr[u][i];
        if(lft[x]==-1 || dfs(lft[x]))
        {
            lft[x]=u;
            rght[u]=x;
            return true;
        }
    }
    return false;
}
int bpm()
{
    int i,j,k;
    memset(lft,-1,sizeof(lft));
    memset(rght,-1,sizeof(rght));
    bool path_found;
    while(1)
    {
        path_found=false;
        memset(v,0,sizeof(v));
        for(i=1;i<=n;i++)
        {
            if(!v[i] && rght[i]==-1) path_found|=dfs(i);
        }
        if(!path_found) break;
    }
    int cnt=0;
    for(i=1;i<=m;i++) if(lft[i]!=-1) cnt++;
    return cnt;
}
int main()
{
    int t,cs=0,i,j,k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;i++) cin>>a[i];
        cin>>m;
        for(i=1;i<=m;i++) cin>>b[i];
        gr.clear();
        gr.resize(n+1);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++) if(b[j]%a[i]==0) gr[i].push_back(j);
        }
        printf("Case %d: %d\n",++cs,bpm());
    }
    return 0;
}
