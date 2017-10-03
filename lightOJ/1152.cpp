#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

int n,m;
string arr[50];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int lft[450],rit[450];
int v[50][50];
int used[450];
int num[50][50];
int clr[450];
vector<vector<int> > gr;
int cur=0;

int dfs(int u)
{
    if(used[u]) return 0;
    used[u]=1;
    for(int i=0;i<gr[u].size();i++)
    {
        if(lft[gr[u][i]]==-1 || dfs(lft[gr[u][i]]))
        {
            rit[u]=gr[u][i];
            lft[gr[u][i]]=u;
            return 1;
        }
    }
    return 0;
}
int bpm()
{
    int i,j,k;
    memset(lft,-1,sizeof(lft));
    memset(rit,-1,sizeof(rit));
    int found=1;
    while(found)
    {
        found=0;
        memset(used,0,sizeof(used));
        for(i=0;i<gr.size();i++)
        {
            if(rit[i]==-1 && !used[i] && clr[i]==0) found|=dfs(i);
        }
    }
    int cnt=0;
    for(i=1;i<=gr.size();i++) if(lft[i]!=-1) cnt++;
    return cnt;
}
void bfs(int x,int y)
{
    int i,j,k,a,b;
    v[x][y]=1;
    queue<pair<int,int> > q;
    clr[num[x][y]]=cur;
    q.push(mp(x,y));
    while(!q.empty())
    {
        pair<int,int> u=q.front();
        q.pop();
        a=u.first;b=u.second;
        //cout<<a<<" "<<b<<endl;
        for(k=0;k<4;k++)
        {
            if(a+dx[k]<0 || a+dx[k]>=m || b+dy[k]<0 || b+dy[k]>=n) continue;
            if(arr[a+dx[k]][b+dy[k]]!='*') continue;
            int aa=a+dx[k],bb=b+dy[k];
            gr[num[a][b]].pb(num[aa][bb]);
            gr[num[aa][bb]].pb(num[a][b]);
            if(v[a+dx[k]][b+dy[k]]) continue;
            clr[num[aa][bb]]=!clr[num[a][b]];
            v[aa][bb]=1;
            q.push(mp(aa,bb));
        }
    }

}

void build_graph()
{
    int i,j,k;
    memset(v,0,sizeof(v));
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(!v[i][j] && arr[i][j]=='*') bfs(i,j);
        }
    }
}

int main()
{
    int t,cs=0,i,j,k,tot;
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        for(i=0;i<m;i++) cin>>arr[i];
        tot=0;
        memset(num,-1,sizeof(num));
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++) if(arr[i][j]=='*')
            {
                tot++;
                num[i][j]=tot;
            }
        }
        gr.clear();
        gr.resize(tot+1);
        cur=0;
        build_graph();
        /*for(i=1;i<gr.size();i++)
        {
            for(j=0;j<gr[i].size();j++) cout<<gr[i][j]<<" ";
            cout<<endl;
        }*/
        int val=bpm();
        //cout<<val<<endl;
        printf("Case %d: %d\n",++cs,tot-val);
    }
    return 0;
}
