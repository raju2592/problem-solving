#include<iostream>
#include<vector>
#include<set>
#define ll long long
#define ii pair<ll,ll>
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define INF 2000000000
#include<cstdio>
using namespace std;
vector<vector<ii > > gr;
ll n,m,s,t;
ll dijkstra()
{
    ll i,u,v;
    vector<ll> d;
    d.resize(n);
    for(i=0;i<d.size();i++) d[i]=INF;
    d[s]=0;
    set< ii > pq;
    pq.insert(mp(0,s));
    while(!pq.empty())
    {
        u=pq.begin()->sc;
        if(u==t) return d[u];
        pq.erase(pq.begin());
        for(i=0;i<gr[u].size();i++)
        {
            v=gr[u][i].fs;
            if(d[v]>d[u]+gr[u][i].sc)
            {
                pq.erase(mp(d[v],v));
                d[v]=d[u]+gr[u][i].sc;
                pq.insert(mp(d[v],v));
            }
        }
    }
    return -1;
}
int main()
{
    ll i,j,k,l,K;
    cin>>K;
    for(ll c=1;c<=K;c++)
    {
        cin>>n>>m>>s>>t;
        gr.clear();
        gr.resize(n);
        for(i=0;i<m;i++)
        {
            cin>>j>>k>>l;
            gr[j].pb(mp(k,l));
            gr[k].pb(mp(j,l));
        }
        l=dijkstra();
        if(l!=-1) printf("Case #%lld: %lld\n",c,l);
        else printf("Case #%lld: unreachable\n",c);
    }
    return 0;
}
