#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<set>
#include<utility>
#include<sstream>
#include<fstream>
#define ll long long
#define ull unsigned ll
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define INF 2000000000
using namespace std;

ll Min(ll i,ll j){return i<j?i:j;}
ll Max(ll i,ll j){return i>j?i:j;}
ll BigMod(ll B,ll P,ll M){ll R=1; while(P>0){if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return (ll)R;} /// (B^P)%M
vector<vector<pair<ll,ll> > > gr;
vector<ll> d[2];
int main()
{
    ll i,j,k,n,m,s,t,dd;
    cin>>n>>m;
    gr.resize(n+1);
    for(i=1;i<=m;i++)
    {
        cin>>j>>k;
        gr[j].pb(mp(k,0));
        gr[k].pb(mp(j,1));
    }
    cin>>s>>t;
    set<pair<ll,pair<ll,ll> > > pq;
    pair<ll,ll> u;
    d[0].resize(n+1);
    d[1].resize(n+1);
    for(i=1;i<=n;i++) d[0][i]=d[1][i]=INF;
    pq.insert(mp(0,mp(s,0)));
    pq.insert(mp(0,mp(s,1)));
    d[0][s]=d[1][s]=0;
    while(!pq.empty())
    {
        u=pq.begin()->sc;
        pq.erase(pq.begin());
        for(i=0;i<gr[u.fs].size();i++)
        {
            if(u.sc==gr[u.fs][i].sc) dd=0;
            else dd=1;
            if(d[u.sc][u.fs]+dd<d[gr[u.fs][i].sc][gr[u.fs][i].fs])
            {
                pq.erase(mp(d[gr[u.fs][i].sc][gr[u.fs][i].fs],gr[u.fs][i]));
                d[gr[u.fs][i].sc][gr[u.fs][i].fs]=d[u.sc][u.fs]+dd;
                pq.insert(mp(d[gr[u.fs][i].sc][gr[u.fs][i].fs],gr[u.fs][i]));
            }
        }
    }
    cout<<min(d[0][t],d[1][t])<<endl;
    return 0;
}














