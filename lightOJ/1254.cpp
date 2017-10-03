#include<iostream>
#include<set>
#include<vector>
#include<utility>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define INF 2000000000
typedef unsigned int INT;
using namespace std;
vector<vector<pair<int,int> > > gr;
vector<int> w;
int d[101][1001];
int dijkstra(int c,int s,int t)
{
    int v,x,i,j,k,cost;
    //memset(d,255,sizeof(d));
    //cout<<d[0][2]<<endl;
    for(i=0;i<101;i++)
    {
        for(j=0;j<101;j++) d[i][j]=INF;
    }
    d[0][s]=0;
    set<pair<int,pair<int,int> > > pq;
    pq.insert(mp(0,mp(0,s)));
    //pair<int,pair<int,int> > u;
    pair<int,int> u;
    while(!pq.empty())
    {
        u=pq.begin()->second;
        x=u.first;
        v=u.second;
		/*if(pq.begin()->first<0)
		{
			cout<<x<<' '<<v<<'a';
			break;
		}*/
		//cout<<x<<' '<<v<<' '<<pq.begin()->first<<endl;
        if(v==t) return pq.begin()->first;
        pq.erase(pq.begin());
        //for(i=x;i<=c;i++)
        //{
        if(x<c)
        {
            if(d[x][v]+w[v]<d[x+1][v])
            {
                pq.erase(mp(d[x+1][v],mp(x+1,v)));
                d[x+1][v]=d[x][v]+w[v];
                pq.insert(mp(d[x+1][v],mp(x+1,v)));
            }
        }
        for(j=0;j<gr[v].size();j++)
        {
            if(x>=gr[v][j].sc && d[x][v]<d[x-gr[v][j].sc][gr[v][j].fs])
            {
                pq.erase(mp(d[x-gr[v][j].sc][gr[v][j].fs],mp(x-gr[v][j].sc,gr[v][j].fs)));
                d[x-gr[v][j].sc][gr[v][j].fs]=d[x][v];
                pq.insert(mp(d[x-gr[v][j].sc][gr[v][j].fs],mp(x-gr[v][j].sc,gr[v][j].fs)));
            }
        }
        //}
    }
    return -1;
}
int main()
{
    int i,T,j,k,n,m,q,c,s,t,l;
    //cin>>T;
    scanf("%d",&T);
    for(int K=1;K<=T;K++)
    {
        //cin>>n>>m;
        scanf("%d %d",&n,&m);
        gr.clear();
        gr.resize(n);
        w.clear();
        w.resize(n);
        for(i=0;i<n;i++)
        {
            //cin>>w[i];
            scanf("%d",&w[i]);
        }
        for(i=0;i<m;i++)
        {
            //cin>>j>>k>>l;
            scanf("%d %d %d",&j,&k,&l);
            gr[j].pb(mp(k,l));
            gr[k].pb(mp(j,l));
        }
        //cin>>q;
        scanf("%d",&q);
        printf("Case %d:\n",K);
        while(q--)
        {
            //cin>>c>>s>>t;
            scanf("%d %d %d",&c,&s,&t);
            //cout<<dijkstra(c,s,t)<<endl;
            k=dijkstra(c,s,t);
            if(k!=-1) printf("%d\n",k);//cout<<k<<endl;
            else printf("impossible\n");
        }
    }
    return 0;
}
