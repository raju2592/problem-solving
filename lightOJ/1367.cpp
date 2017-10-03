#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<utility>
#define MAXN 205
#define pb push_back
#define mp make_pair
#define ll long  //long
#define ii pair<ll,ll>
#define ff first
#define ss second
using namespace std;

ll st,node,s,t,c;
ll cf[MAXN][MAXN],flw[MAXN][MAXN];
ll ex[MAXN],cur[MAXN],h[MAXN];
ll inq[MAXN];
vector<vector<ll> > rgr;
vector<vector< pair< ll,ii > > > gr;
vector<vector< ii > > nwgr;

int n,m;
int dmnd[205];
int out[40005];


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
    int t,cs=1,i,j,k,l,c,flow,expa,expb;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        memset(dmnd,0,sizeof(dmnd));
        memset(out,0,sizeof(out));
        gr.clear();
        gr.resize(n+1);
        for(i=1;i<=m;i++)
        {
            scanf("%d %d %d %d",&j,&k,&l,&c);
            out[i]=l;
            gr[j].pb(mp(k,mp(c-l,i)));
            dmnd[j]+=l;
            dmnd[k]-=l;
        }
        printf("Case %d: ",cs++);
        st=0;
        node=n+1;
        nwgr.clear();
        nwgr.resize(node+1);
        expa=expb=0;
        for(i=1;i<=n;i++)
        {
            if(dmnd[i]<0) nwgr[0].pb(mp(i,-dmnd[i])),expa+=-dmnd[i];
            else if(dmnd[i]>0) nwgr[i].pb(mp(node,dmnd[i])),expb+=dmnd[i];
        }
        //cout<<expa<<" "<<expb;
        if(expa!=expb)
        {
            puts("no");
            continue;
        }
        //for(i=1;i<=n;i++) cout<<dmnd[i]<<endl;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<gr[i].size();j++)
            {
                int x=gr[i][j].ff;
                int y=gr[i][j].ss.ff;
                nwgr[i].pb(mp(x,y));
            }
        }
        /*for(i=0;i<=node;i++)
        {
            for(j=0;j<nwgr[i].size();j++) cout<<nwgr[i][j].first<<"*"<<nwgr[i][j].second<<" ";
            cout<<endl;
        }*/
        nwgr[n].pb(mp(1,expa+10));
        flow=max_flow(nwgr,0,node);
        //cout<<flow<<"ff\n";
        //for(i=1;i<=m;i++) cout<<out[i]<<endl;
        if(flow!=expa) puts("no");
        else
        {
            puts("yes");
            for(i=1;i<=n;i++)
            {
                for(j=0;j<gr[i].size();j++)
                {
                    int x=gr[i][j].ff;
                    int y=gr[i][j].ss.ss;
                    if(flw[i][x]>0) out[y]+=flw[i][x];
					//cout<<y;
                }
            }
            for(i=1;i<=m;i++) printf("%d\n",out[i]);
        }
    }
    return 0;
}
