#include<iostream>
#include<vector>
#include<cstdio>
#include<set>
#include<utility>
#define ll long long
#define fs first
#define sc second
#define ii pair<ll,ll>
#define mp make_pair
#define pb push_back
#define INF 2000000000
using namespace std;
vector<vector< ii > > gr;
ll n,m;
ll prim(ll s)
{
    vector<ll> d;
    ll i,j,k,ret,u;
    d.resize(n);
    for(i=0;i<n;i++) d[i]=INF;
    d[s]=0;
    set< ii > pq;
    ret=-INF;
    pq.insert(mp(0,s));
    j=0;
    while(!pq.empty())
    {
        ii u=*(pq.begin());
        pq.erase(pq.begin());
        if(j) ret=max(ret,u.fs);
        for(i=0;i<gr[u.sc].size();i++)
        {
            if(d[gr[u.sc][i].fs]>gr[u.sc][i].sc)
            {
                pq.erase(mp(d[gr[u.sc][i].fs],gr[u.sc][i].fs));
                d[gr[u.sc][i].fs]=gr[u.sc][i].sc;
                pq.insert(mp(d[gr[u.sc][i].fs],gr[u.sc][i].fs));
            }
        }
        j++;
    }
    return ret;
}
int main()
{
    ll i,j,t,k,l;
    cin>>t;
    for(ll c=1;c<=t;c++)
    {
        cin>>n>>m;
        gr.clear();
        gr.resize(n);
        for(i=0;i<m;i++)
        {
            cin>>j>>k>>l;
            if(j==k) continue;
            gr[j].pb(mp(k,-l));
            gr[k].pb(mp(j,-l));
        }
        ll out=prim(0);
        printf("Case #%lld: %lld\n",c,-out);
    }
}
