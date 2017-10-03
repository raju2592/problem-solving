#include<iostream>
#include<utility>
#include<queue>
#include<vector>
#include<cstdio>
#define INF 32767
using namespace std;

char g[110][110];
vector<vector<int> > dist;
vector<vector<int> > v;
int n,m;

void bfs(pair<int,int> s,pair<int,int> d)
{
    int i,j,k,r,c;
    pair<int,int> u;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
          dist[i][j]=INF;
          v[i][j]=0;
        }
    }
    v[s.first][s.second]=1;
    dist[s.first][s.second]=0;
    queue<pair<int,int> > q;
    q.push(s);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        if(u==d) return;
        r=u.first;
        c=u.second;
        if(c+1<n && g[r][c+1]!='p' && v[r][c+1]==0)
        {
            dist[r][c+1]=dist[r][c]+1;
            v[r][c+1]=1;
            q.push(make_pair(r,c+1));
        }
        if(c-1>=0 && g[r][c-1]!='p' && v[r][c-1]==0)
        {
            dist[r][c-1]=dist[r][c]+1;
            v[r][c-1]=1;
            q.push(make_pair(r,c-1));
        }
        if(r+1<m && g[r+1][c]!='p' && v[r+1][c]==0)
        {
            dist[r+1][c]=dist[r][c]+1;
            v[r+1][c]=1;
            q.push(make_pair(r+1,c));
        }
        if(r-1>=0 && g[r-1][c]!='p' && v[r-1][c]==0)
        {
            dist[r-1][c]=dist[r][c]+1;
            v[r-1][c]=1;
            q.push(make_pair(r-1,c));
        }
        if(c+1<n && r+1<m && g[r+1][c+1]!='p' && v[r+1][c+1]==0)
        {
            dist[r+1][c+1]=dist[r][c]+1;
            v[r+1][c+1]=1;
            q.push(make_pair(r+1,c+1));
        }
        if(c+1<n && r-1>=0 && g[r-1][c+1]!='p' && v[r-1][c+1]==0)
        {
            dist[r-1][c+1]=dist[r][c]+1;
            v[r-1][c+1]=1;
            q.push(make_pair(r-1,c+1));
        }
        if(c-1>=0 && r-1>=0 && g[r-1][c-1]!='p' && v[r-1][c-1]==0)
        {
            dist[r-1][c-1]=dist[r][c]+1;
            v[r-1][c-1]=1;
            q.push(make_pair(r-1,c-1));
        }
        if(c-1>=0 && r+1<m && g[r+1][c-1]!='p' && v[r+1][c-1]==0)
        {
            dist[r+1][c-1]=dist[r][c]+1;
            v[r+1][c-1]=1;
            q.push(make_pair(r+1,c-1));
        }
    }
}
int main()
{
    int i,j,k,t,r,c;
    char ch,nu[2];
    pair<int,int> a,b;
    cin>>t;
    while(t--)
    {
        //cin>>m>>n;
        scanf("%d %d\n",&m,&n);
        dist.resize(m);
        v.resize(m);
        for(i=0;i<m;i++)
        {
            dist[i].resize(n);
            v[i].resize(n);
        }
        for(i=0;i<m;i++)
        {
            gets(g[i]);
        }
        for(r=0;r<m;r++)
        {
            for(c=0;c<n;c++)
            {
                if(g[r][c]=='Z')
                {
                    g[r][c]='p';
                    if(c+2<n && r+1<m && g[r+1][c+2]!='A' && g[r+1][c+2]!='B' && g[r+1][c+2]!='Z')
                        g[r+1][c+2]='p';
                    if(c+2<n && r-1>=0 && g[r-1][c+2]!='A' && g[r-1][c+2]!='B' && g[r-1][c+2]!='Z')
                        g[r-1][c+2]='p';
                    if(c-2>=0 && r+1<m && g[r+1][c-2]!='A' && g[r+1][c-2]!='B' && g[r+1][c-2]!='Z')
                        g[r+1][c-2]='p';
                    if(c-2>=0 && r-1>=0 && g[r-1][c-2]!='A' && g[r-1][c-2]!='B' && g[r-1][c-2]!='Z')
                        g[r-1][c-2]='p';
                    if(c+1<n && r+2<m && g[r+2][c+1]!='A' && g[r+2][c+1]!='B' && g[r+2][c+1]!='Z')
                        g[r+2][c+1]='p';
                    if(c+1<n && r-2>=0 && g[r-2][c+1]!='A' && g[r-2][c+1]!='B' && g[r-2][c+1]!='Z')
                        g[r-2][c+1]='p';
                    if(c-1>=0 && r+2<m && g[r+2][c-1]!='A' && g[r+2][c-1]!='B' && g[r+2][c-1]!='Z')
                        g[r+2][c-1]='p';
                    if(c-1>=0 && r-2>=0 && g[r-2][c-1]!='A' && g[r-2][c-1]!='B' && g[r-2][c-1]!='Z')
                        g[r-2][c-1]='p';

                }
                else if(g[r][c]=='A') a=make_pair(r,c);
                else if(g[r][c]=='B') b=make_pair(r,c);
            }
        }
        /*for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++) dist[i][j]=INF;
        }*/
        bfs(a,b);
        if(dist[b.first][b.second]==INF) cout<<"King Peter, you can't go now!"<<endl;
        else cout<<"Minimal possible length of a trip is "<<dist[b.first][b.second]<<endl;
    }
    return 0;
}



