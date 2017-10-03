#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<algorithm>
#define ll long
using namespace std;
vector<vector<pair<ll,double> > > gr;
vector<ll> v;
vector<ll> d,p;
vector<double> prob;
ll n,m,s,t;
void bfs(ll s)
{
    v[s]=1;
    d[s]=0;
    p[s]=-1;
    prob[s]=0;
    queue<ll> q;
    ll u,i;
    q.push(s);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(i=0;i<gr[u].size();i++)
        {
            if(v[gr[u][i].first]==1)
            {
                if(d[gr[u][i].first]==d[u]+1)
                {
                    //prob[gr[u][i]]=min(prob[gr[u][i]],gr[u][i].second+prob[u]-gr[u][i].second*prob[u])
                    double tmp=gr[u][i].second+prob[u]-gr[u][i].second*prob[u];
                    if(tmp<prob[gr[u][i].first])
                    {
                        prob[gr[u][i].first]=tmp;
                        p[gr[u][i].first]=u;
                    }
                }
            }
            else
            {
                v[gr[u][i].first]=1;
                p[gr[u][i].first]=u;
                d[gr[u][i].first]=d[u]+1;
                prob[gr[u][i].first]=gr[u][i].second+prob[u]-gr[u][i].second*prob[u];
                q.push(gr[u][i].first);
            }
        }
    }
}
void print_path(ll n)
{
    if(n==s)
    {
        cout<<n;
        return;
    }
    cout<<n<<' ';
    print_path(p[n]);

}
int main()
{
    ll i,j,k,l;
    cin>>n>>m;
    gr.resize(n+1);
    d.resize(n+1);
    p.resize(n+1);
    v.resize(n+1);
    prob.resize(n+1);
    cin>>t>>s;
    for(i=0;i<m;i++)
    {
        cin>>j>>k>>l;
        gr[j].push_back(make_pair(k,(double) l/100));
        gr[k].push_back(make_pair(j,(double) l/100));
    }
    for(i=1;i<=n;i++) v[i]=0;
    bfs(s);
    cout<<d[t]+1<<' '<<prob[t]<<endl;
    print_path(t);
    cout<<endl;
    return 0;
}
