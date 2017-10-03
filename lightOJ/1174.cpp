#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;
vector<vector<int> > gr;
vector<int> v,d1,d2,l;
int ans;
int bfs1(int s)
{
    int u,i;
    for(i=0;i<gr.size();i++) l[i]=1,v[i]=0;
    v[s]=1;
    d1[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(i=0;i<gr[u].size();i++)
        {
            if(v[gr[u][i]]==0)
            {
                l[u]=0;
                d1[gr[u][i]]=d1[u]+1;
                v[gr[u][i]]=1;
                q.push(gr[u][i]);
            }
        }
    }
    return d1[u];
}
int bfs2(int s)
{
    int u,i,ret=-1;
    for(i=0;i<gr.size();i++) v[i]=0;
    v[s]=1;
    d2[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        if(l[u]) ans=max(ans,d1[u]+d2[u]);
        for(i=0;i<gr[u].size();i++)
        {
            if(v[gr[u][i]]==0)
            {
                d2[gr[u][i]]=d2[u]+1;
                v[gr[u][i]]=1;
                q.push(gr[u][i]);
            }
        }
    }
    return ret;
}
int main()
{
    int T,s,t,n,m,i,j,k;
    cin>>T;
    for(int c=1;c<=T;c++)
    {
        cin>>n>>m;
        gr.clear();
        gr.resize(n);
        for(i=0;i<m;i++)
        {
            cin>>j>>k;
            gr[j].push_back(k);
            gr[k].push_back(j);
        }
        cin>>s>>t;
        v.clear();
        v.resize(n);
        d1.clear();
        d1.resize(n);
        d2.clear();
        d2.resize(n);
        l.clear();
        l.resize(n);
        ans=0;
        ans+=bfs1(s);
        bfs2(t);
        printf("Case %d: %d\n",c,ans);
    }
    return 0;
}
