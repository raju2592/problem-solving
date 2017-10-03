#include<iostream>
#include<set>
#include<vector>
#include<utility>
#include<cstdio>
#include<map>
#include<cstring>
#define pb push_back
#define mp make_pair
#define INF 2000000000
using namespace std;
int min(int i,int j){return i<j?i:j;}
vector<vector<pair<pair<int,int>,int> > > gr;

int dis[14][10005];
int main()
{
    int i,j,k,n,m,t,d,l,u,v,p;
    pair<int,int> x;
    scanf("%d",&t);
    for(int c=1;c<=t;c++)
    {
        scanf("%d %d %d %d",&n,&m,&p,&d);
		gr.clear();
        gr.resize(n+1);
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&j,&k,&l);
            gr[j].pb(mp(mp(k,l),0));
        }
        for(i=0;i<p;i++)
        {
            scanf("%d %d %d",&j,&k,&l);
            gr[j].pb(mp(mp(k,l),1));
        }
        for(i=0;i<14;i++)
            for(j=0;j<10004;j++) dis[i][j]=INF;
        set<pair<int,pair<int,int> > > pq;
        for(i=0;i<=d;i++)
        {
            dis[i][0]=0;
            pq.insert(mp(0,mp(i,0)));
        }
        while(!pq.empty())
        {
            x=pq.begin()->second;
            pq.erase(pq.begin());
            u=x.first;
            v=x.second;
            for(i=0;i<gr[v].size();i++)
            {
                if(gr[v][i].second==1 && u==d) continue;
                if(dis[u+gr[v][i].second][gr[v][i].first.first]>dis[u][v]+gr[v][i].first.second)
                {
                    pq.erase(mp(dis[u+gr[v][i].second][gr[v][i].first.first],mp(u+gr[v][i].second,gr[v][i].first.first)));
                    dis[u+gr[v][i].second][gr[v][i].first.first]=dis[u][v]+gr[v][i].first.second;
                    pq.insert(mp(dis[u+gr[v][i].second][gr[v][i].first.first],mp(u+gr[v][i].second,gr[v][i].first.first)));
                }
            }
        }
        int ans=INF;
        for(i=0;i<=d;i++) ans=min(ans,dis[d][n-1]);
        if(ans!=INF) printf("Case %d: %d\n",c,ans);
        else printf("Case %d: Impossible\n",c);
    }
    return 0;
}
