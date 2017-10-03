#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int n,m;
vector<vector<int> > gr;
int lft[1005],rit[1005],v[1005];

int dfs(int u)
{
    if(v[u]) return 0;
    v[u]=1;
    for(int i=0;i<gr[u].size();i++)
    {
        int x=gr[u][i];
        if(lft[x]==-1 || dfs(lft[x]))
        {
            lft[x]=u;
            rit[u]=x;
            return 1;
        }
    }
    return 0;
}
int bpm()
{
    memset(lft,-1,sizeof(lft));
    memset(rit,-1,sizeof(rit));
    int fnd=1;
    while(fnd)
    {
        fnd=0;
        memset(v,0,sizeof(v));
        for(int i=1;i<=n;i++)
        {
            if(rit[i]==-1 && !v[i]) fnd|=dfs(i);
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++) if(rit[i]!=-1) cnt++;
    return cnt;
}
int main()
{
    int t,cs=0,i,j,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        gr.clear();
        gr.resize(n+1);
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&j,&k);
            gr[j].pb(k);
        }
        printf("Case %d: %d\n",++cs,n-bpm());
    }
    return 0;
}
/* Explanation:
    Let, initially all vertices are isolated, so n paths is needed.
    adding an edges decreases no of paths by 1.

    so pathNo=n-edgeAdded
    to minimize vertex disjoint path, we need to find maximum no of edges \n
    so that an node is connected to at most one node (i.e maximum matching in corresponding bp graph)
*/
