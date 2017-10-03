#include<iostream>
#include<utility>
#include<cstring>
#include<cstdio>
#include<vector>
#define pb push_back
#define mp make_pair
#define INF 20000000
using namespace std;

vector<vector<int> > gr;
int p[10004],mn[2][10004],ch[2][10004];
void print(int n);
void findpath(int n,vector<int> &path,int x);
pair<int,int> calc(int n)
{
    //v[n]=1;
    pair<int,int> first=make_pair(INF,0),second=make_pair(INF,0),tmp;
    int val=1,fst=-1,snd=-1;
    for(int i=0;i<gr[n].size();i++)
    {
        if(p[n]!=gr[n][i])
        {
            p[gr[n][i]]=n;
            tmp=calc(gr[n][i]);
            val+=tmp.second;
            if(tmp.first-tmp.second<=first.first-first.second)
            {
                second=first;
                first=tmp;
                snd=fst;
                fst=gr[n][i];
            }
            else if(tmp.first-tmp.second<second.first-second.second) second=tmp,snd=gr[n][i];
        }
    }
    int ans=val;
    ch[0][n]=0;
    if(first.first!=INF && val-1-first.second+first.first<ans) ch[0][n]=1,ans=val-1-first.second+first.first;
    if(second.first!=INF && val-1-first.second-second.second+first.first+second.first-1<ans)
        ch[0][n]=2,ans=val-1-first.second-second.second+first.first+second.first-1;
    mn[0][n]=fst;
    mn[1][n]=snd;
    if(first.first==INF)
    {
        ch[1][n]=n;
        return make_pair(val,val);
    }
    int val2;
    if(val-1-first.second+first.first<val)
    {
        val2=val-1-first.second+first.first;
        ch[1][n]=fst;
    }
    else
    {
        val2=val;
        ch[1][n]=n;
    }
    return make_pair(val2,ans);
}
void findpath(int n,vector<int> &path,int x)
{
    for(int i=0;i<gr[n].size();i++) if(p[n]!=gr[n][i] && gr[n][i]!=ch[1][n]) print(gr[n][i]);
    if(ch[1][n]==n)
    {
        path.pb(n);
        return;
    }
    if(x==1) path.pb(n);
    findpath(ch[1][n],path,x);
    if(x==0) path.pb(n);
}
void print(int n)
{
	int i;
    if(ch[0][n]==0)
    {
        cout<<n<<endl;
        for(i=0;i<gr[n].size();i++) if(p[n]!=gr[n][i]) print(gr[n][i]);
    }
    else if(ch[0][n]==1)
    {
        vector<int> path;
        findpath(mn[0][n],path,0);
        path.push_back(n);
        //cout<<path[0];
        printf("%d",path[0]);
        for(i=1;i<path.size();i++) printf(" %d",path[i]);//cout<<" "<<path[i];
        //cout<<endl;
        printf("\n");
        for(i=0;i<gr[n].size();i++) if(p[n]!=gr[n][i] && gr[n][i]!=mn[0][n]) print(gr[n][i]);
    }
    else if(ch[0][n]==2)
    {
        vector<int> path;
        findpath(mn[0][n],path,0);
        path.push_back(n);
        findpath(mn[1][n],path,1);
        cout<<path[0];
        for(i=1;i<path.size();i++) cout<<" "<<path[i];
        cout<<endl;
        for(i=0;i<gr[n].size();i++) if(p[n]!=gr[n][i] && gr[n][i]!=mn[0][n] && gr[n][i]!=mn[1][n]) print(gr[n][i]);
    }
}
int main()
{
    int t,i,j,k,n;
    //cin>>t;
    scanf("%d",&t);
    pair<int,int> val;
    while(t--)
    {
        //cin>>n;
        scanf("%d",&n);
        gr.clear();
        gr.resize(n+1);
        for(i=1;i<n;i++)
        {
            //cin>>j>>k;
            scanf("%d %d",&j,&k);
            gr[j].pb(k);
            gr[k].pb(j);
        }
        memset(p,-1,sizeof(p));
        val=calc(1);
        //cout<<val.second<<endl;
        printf("%d\n",val.second);
        print(1);
    }
    return 0;
}
