#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

vector<vector<int> > gr;
vector<pair<int,int> > vm,vf;
int male,female;
int lft[505],rit[505];
int v[505];

int dfs(int u)
{
    if(v[u]) return 0;
    v[u]=1;
    for(int i=0;i<gr[u].size();i++)
    {
        int x=gr[u][i];
        if(lft[x]==-1 || dfs(lft[x]))
        {
            lft[x]=u;
            rit[u]=x;
            return 1;
        }
    }
    return 0;
}
int bpm()
{
    int i,j,k,x;
    memset(lft,-1,sizeof(lft));
    memset(rit,-1,sizeof(rit));
    int fnd=1;
    while(fnd)
    {
        fnd=0;
        memset(v,0,sizeof(v));
        for(i=1;i<=male;i++)
        {
            if(rit[i]==-1 && !v[i]) fnd|=dfs(i);
        }
    }
    int cnt=0;
    for(i=1;i<=female;i++) if(lft[i]!=-1) cnt++;
    return cnt;
}

void build_graph()
{
    for(int i=0;i<male;i++)
    {
        for(int j=0;j<female;j++)
            if(vm[i].first==vf[j].second || vm[i].second==vf[j].first)
                gr[i+1].pb(j+1);
    }
}
int get(string ss)
{
    int ret=0;
    for(int i=1;i<ss.size();i++) ret=ret*10+ss[i]-'0';
    return ret;
}
int main()
{
    int t,cs=0,i,j,k,n,m,v;
    string a,b;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>v;
        vm.clear();
        vf.clear();
        for(i=0;i<v;i++)
        {
            cin>>a>>b;
            j=get(a);k=get(b);
            if(a[0]=='M') vm.pb(mp(j,k));
            else vf.pb(mp(j,k));
        }
        male=vm.size();
        female=vf.size();
        gr.clear();
        gr.resize(male+1);
        build_graph();
        printf("Case %d: %d\n",++cs,v-bpm());
    }
    return 0;
}
