#include<vector>
#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
#define MAXN 205
#define pb push_back
#define mp make_pair
#define ll int
#define INF 1000000000
using namespace std;

ll st,node,s,t,c;
ll cf[MAXN][MAXN],flw[MAXN][MAXN];
ll ex[MAXN],cur[MAXN],h[MAXN];
ll inq[MAXN];
vector<vector<pair<ll,ll> > > gr;
vector<vector<ll> > rgr;
ll min(ll a,ll b){return a<b?a:b;}

void push(ll u,ll v)
{
    ll d=min(cf[u][v],ex[u]);
    flw[u][v]+=d;
    flw[v][u]=-flw[u][v];
    ex[u]-=d;
    ex[v]+=d;
    cf[u][v]-=d;
    cf[v][u]+=d;
}
ll max_flow(vector<vector<pair<ll,ll> > > &gr,ll s,ll t)
{
    memset(inq,0,sizeof(inq));
    memset(cf,0,sizeof(cf));
    memset(flw,0,sizeof(flw));
    memset(ex,0,sizeof(ex));
    ll i,j,k,v;
    rgr.clear();
    rgr.resize(node+1);
    for(i=st;i<=node;i++)
    {
        for(j=0;j<gr[i].size();j++)
        {
            v=gr[i][j].first;
            rgr[i].pb(v);
            rgr[v].pb(i);
            cf[i][v]+=gr[i][j].second;
        }
    }
    queue<ll> q;
    for(i=0;i<rgr[s].size();i++)
    {
        v=rgr[s][i];
        if(cf[s][v]>0)
        {
            flw[s][v]=cf[s][v];
            flw[v][s]=-flw[s][v];
            ex[s]-=flw[s][v];
            ex[v]+=flw[s][v];
            cf[s][v]-=flw[s][v];
            cf[v][s]+=flw[s][v];
            if(v!=t && v!=s) q.push(v);
            inq[v]=1;
        }
    }
    memset(h,0,sizeof(h));
    h[s]=node;
    memset(cur,0,sizeof(cur));
    while(!q.empty())
    {
        ll u=q.front();
        q.pop();
        inq[u]=0;
        while(1)
        {
            v=rgr[u][cur[u]];
            if(cf[u][v]==0 || h[u]!=h[v]+1) cur[u]++;
            else
            {
                push(u,v);
                if(ex[v]>0 && v!=s && v!=t && inq[v]==0)
                {
                    q.push(v);
                    inq[v]=1;
                }
                if(ex[u]==0) break;
                else cur[u]++;
            }
            if(cur[u]==rgr[u].size())
            {
                h[u]=h[u]+1;
                cur[u]=0;
            }
        }
    }
    return ex[t];
}

int main()
{
    int t,cs=1,i,j,k,m,n,e[105],c[105],total;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&m,&n);
        node=m+n+1;
        st=0;
        gr.clear();
        gr.resize(node+1);
        total=0;
        for(i=1;i<=m;i++)
        {
            scanf("%d",&e[i]);
            gr[0].pb(mp(i,e[i]));
            total+=e[i];
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d",&c[i]);
            gr[m+i].pb(mp(node,c[i]));
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d",&j);
            while(j--)
            {
                scanf("%d",&k);
                gr[i].pb(mp(k+m,INF));
            }
        }
        printf("Case %d: %d\n",cs++,total-max_flow(gr,0,node));
    }
    return 0;
}
