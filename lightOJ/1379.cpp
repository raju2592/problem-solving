#include<cstdio>
#include<algorithm>
#include<set>
#include<utility>
#include<vector>
#include<iostream>
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define INF 700000000
using namespace std;

vector<vector<pair<int,int> > > gr,gr_rev;
vector<int> d_s,d_t;
vector<pair<int,pair<int,int> > > edge;

void dijkstra(vector<vector<pair<int,int> > > &gr,vector<int> &d,int s)
{
    int i,j,k;
    for(i=1;i<gr.size();i++) d[i]=INF;
    d[s]=0;
    set<pair<int,int> > pq;
    pq.insert(mp(0,s));
    int u;
    while(!pq.empty())
    {
        u=pq.begin()->sc;
        pq.erase(pq.begin());
        for(i=0;i<gr[u].size();i++)
        {
            if(d[u]+gr[u][i].sc<d[gr[u][i].fs])
            {
                pq.erase(mp(d[gr[u][i].fs],gr[u][i].fs));
                d[gr[u][i].fs]=d[u]+gr[u][i].sc;
                pq.insert(mp(d[gr[u][i].fs],gr[u][i].fs));
            }
        }
    }
}
bool cmp(pair<int,pair<int,int> > a,pair<int,pair<int,int> > b)
{
    return a.fs>b.fs;
}
int main()
{
    int i,j,k,l,n,m,c,s,t,p,T;
    scanf("%d",&T);
    for(c=1;c<=T;c++)
    {
        scanf("%d %d %d %d %d",&n,&m,&s,&t,&p);
        gr.clear();
        gr_rev.clear();
        gr.resize(n+1);
        gr_rev.resize(n+1);
        edge.clear();
        for(i=1;i<=m;i++)
        {
            scanf("%d %d %d",&j,&k,&l);
            edge.pb(mp(l,mp(j,k)));
            gr[j].pb(mp(k,l));
            gr_rev[k].pb(mp(j,l));
        }
        d_s.clear();
        d_t.clear();
        d_s.resize(n+1);
        d_t.resize(n+1);
        dijkstra(gr,d_s,s);
        dijkstra(gr_rev,d_t,t);
        sort(edge.begin(),edge.end(),cmp);
        /*for(i=1;i<=n;i++) cout<<d_s[i];
        cout<<endl;
        for(i=1;i<=n;i++) cout<<d_t[i];
        cout<<endl;*/
		//for(i=0;i<edge.size();i++) cout<<edge[i].fs<<' '<<edge[i].second.fs<<' '<<edge[i].second.second<<endl;
        int ans=-1;
        for(i=0;i<edge.size();i++)
        {
            if(d_s[edge[i].sc.fs]+d_t[edge[i].sc.sc]+edge[i].fs<=p)
            {
                ans=edge[i].fs;
                break;
            }
        }
        printf("Case %d: %d\n",c,ans);
    }
    return 0;
}
