#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<iostream>
#define ll long long
using namespace std;
ll max(ll i,ll j){return i>j?i:j;}
vector<vector<pair<ll,ll> > > tr;
vector<vector<pair<ll,ll> > > far_thr;
vector<ll> faar;
vector<ll> v;
vector<ll> p;
void bfs(ll n)
{
    v[n]=1;
    p[n]=-1;
    ll i,u;
    queue<ll> q;
    q.push(n);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(i=0;i<tr[u].size();i++)
        {
            if(v[tr[u][i].first]==0)
            {
                p[tr[u][i].first]=u;
                v[tr[u][i].first]=1;
                q.push(tr[u][i].first);
            }
        }
    }
}
void count(ll n)
{
    ll i=0;
    for(i=0;i<tr[n].size();i++)
    {
        if(tr[n][i].first==p[n]) continue;
        count(tr[n][i].first);
        far_thr[n].push_back(make_pair(faar[tr[n][i].first],tr[n][i].second));
    }
    if(far_thr[n].empty()) faar[n]=0;
    else
    {
        faar[n]=0;
        for(i=0;i<far_thr[n].size();i++) faar[n]=max(faar[n],far_thr[n][i].first+far_thr[n][i].second);
    }
}
bool cmp(pair<ll,ll> a,pair<ll,ll> b)
{
    if(a.first+a.second>b.first+b.second) return true;
    else return false;
}
int main()
{
    ll t,i,j,k,l,n;
    scanf("%lld",&t);
    for(ll c=1;c<=t;c++)
    {
        scanf("%lld",&n);
        tr.clear();
        tr.resize(n);
        for(i=1;i<n;i++)
        {
            scanf("%lld %lld %lld",&j,&k,&l);
            tr[j].push_back(make_pair(k,l));
            tr[k].push_back(make_pair(j,l));
        }
        p.clear();
        v.clear();
        faar.clear();
        far_thr.clear();
        v.resize(n);
        p.resize(n);
        for(i=0;i<n;i++) v[i]=0;
        bfs(0);
		//for(i=0;i<n;i++) cout<<p[i]<<' ';
		//cout<<endl;
        far_thr.resize(n);
        faar.resize(n);
        count(0);
		//for(i=0;i<n;i++) cout<<faar[i]<<' ';
		//cout<<endl;
		//for(i=0;i<far_thr[0].size();i++) cout<<far_thr[0][i].first<<' '<<far_thr[0][i].second<<endl;
        ll mx=-100;
        for(i=0;i<n;i++)
        {
            if(far_thr[i].size()==0) continue;
            if(far_thr[i].size()==1) mx=max(mx,far_thr[i][0].first+far_thr[i][0].second);
            else
            {
                sort(far_thr[i].begin(),far_thr[i].end(),cmp);
                mx=max(mx,far_thr[i][0].first+far_thr[i][0].second+far_thr[i][1].first+far_thr[i][1].second);
            }
        }
        printf("Case %lld: %lld\n",c,mx);
    }
    return 0;
}































