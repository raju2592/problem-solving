#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define INF 200000000
using namespace std;

string arr[30];
int n,gc,hc;
int d[30][30];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int num[30][30];
int v[30][30];
int used[55],lft[55],rit[55];
vector<vector<pair<int,int> > > gr;


void bfs(int a,int b)
{
    int i,j,k,x,y;
    queue<pair<int,int> > q;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++) d[i][j]=INF;
    }
    d[a][b]=0;
    memset(v,0,sizeof(v));
    v[a][b]=1;
    q.push(mp(a,b));
    while(!q.empty())
    {
        pair<int,int> pp=q.front();
        q.pop();
        x=pp.first;
        y=pp.second;
        for(k=0;k<4;k++)
        {
            int xx=x+dx[k],yy=y+dy[k];
            if(xx<0 || xx>=n || yy<0|| yy>=n || arr[xx][yy]=='#' || v[xx][yy]) continue;
            d[xx][yy]=d[x][y]+1;
            v[xx][yy]=1;
            q.push(mp(xx,yy));
        }
    }
}

int dfs(int u,int mx)
{
    if(used[u]) return 0;
    used[u]=1;
    for(int i=0;i<gr[u].size();i++)
    {
        if(gr[u][i].second>mx) continue;
        int x=gr[u][i].first;
        if(lft[x]==-1 || dfs(lft[x],mx))
        {
            lft[x]=u;
            rit[u]=x;
            return 1;
        }
    }
    return 0;
}
int bpm(int mx)
{
    int i,j,k;
    memset(lft,-1,sizeof(lft));
    memset(rit,-1,sizeof(rit));
    int fnd=1;
    while(fnd)
    {
        fnd=0;
        memset(used,0,sizeof(used));
        for(i=1;i<=gc;i++)
        {
            if(!used[i] && rit[i]==-1) fnd|=dfs(i,mx);
        }
    }
    int cnt=0;
    for(i=1;i<=hc;i++) if(lft[i]!=-1) cnt++;
    return cnt;
}

int search()
{
    int l=1,r=INF,m;
    while(r-l>1)
    {
        m=(r+l)/2;
        if(bpm(m)==hc) r=m;
        else l=m+1;
    }
    if(bpm(l)==hc) return l;
    return r;
}
int main()
{
    int t,cs=0,i,j,k,a,b;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++) cin>>arr[i];
        gc=hc=0;
        gr.clear();
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(arr[i][j]=='G')
                {
                    gc++;
                    num[i][j]=gc;
                }
                else if(arr[i][j]=='H')
                {
                    hc++;
                    num[i][j]=hc;
                }
            }
        }
        gr.resize(gc+1);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(arr[i][j]=='G')
                {
                    bfs(i,j);
                    for(a=0;a<n;a++)
                    {
                        for(b=0;b<n;b++)
                        {
                            if(arr[a][b]=='H' && d[a][b]<INF)
                                gr[num[i][j]].pb(mp(num[a][b],2*d[a][b]+2));
                        }
                    }
                }
            }
        }
        /*for(i=1;i<=gc;i++)
        {
            for(j=0;j<gr[i].size();j++) cout<<gr[i][j].first<<"*"<<gr[i][j].second<<" ";
            cout<<endl;
        }*/
        printf("Case %d: ",++cs);
        if(bpm(INF)!=hc) printf("Vuter Dol Kupokat\n");
        else printf("%d\n",search());
    }
    return 0;
}
