#include<vector>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<utility>
#define MAXN 205
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;

ll n,s,t,c,st;
ll cf[MAXN][MAXN],flw[MAXN][MAXN];
ll ex[MAXN],cur[MAXN],h[MAXN];
ll inq[MAXN];
vector<vector<pair<ll,ll> > > gr;
vector<vector<ll> > rgr;

ll tc[MAXN],bc[MAXN],place[MAXN];
ll N,m;
ll INF;

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
    rgr.resize(n+1);
    for(i=st;i<=n;i++)
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
    h[s]=n;
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
    ll t,cs=1,i,j,k,c;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&N,&m);
        INF=10;
        for(i=1;i<=N;i++) scanf("%lld",&tc[i]),INF+=tc[i];
        for(i=1;i<=N;i++) scanf("%lld",&bc[i]),INF+=tc[i];
        for(i=1;i<=N;i++) scanf("%lld",&place[i]);
        gr.clear();
        gr.resize(N+2);
        for(i=0;i<m;i++)
        {
            scanf("%lld %lld %lld",&j,&k,&c);
            gr[j].pb(mp(k,c));
            gr[k].pb(mp(j,c));
            INF+=c;
        }
        for(i=1;i<=N;i++)
        {
            if(place[i]==-1)
            {
                gr[0].pb(mp(i,bc[i]));
                gr[i].pb(mp(N+1,INF));
            }
            else if(place[i]==1)
            {
                gr[0].pb(mp(i,INF));
                gr[i].pb(mp(N+1,tc[i]));
            }
            else
            {
                gr[0].pb(mp(i,bc[i]));
                gr[i].pb(mp(N+1,tc[i]));
            }
        }
        st=0;
        n=N+1;
        /*for(i=0;i<=n;i++)
        {
            for(j=0;j<gr[i].size();j++) cout<<gr[i][j].first<<"*"<<gr[i][j].second<<" ";
            cout<<endl;
        }*/
        printf("Case %lld: %lld\n",cs++,max_flow(gr,0,n));
    }
    return 0;
}
