#include<cstdio>
#include<cstring>
#include<vector>
#include<utility>
#define mp make_pair
#define pb push_back
#define INF 250000000
using namespace std;

pair<int,int> edge[2505];
vector<vector<pair<int,int> > > gr;
int d1[2505],d2[2505],a[2505],b[2505];
int mxd,mxv;
int ex,diam;
int v[2505];

int dfs(int n)
{
    v[n]=1;
    int i,j,k;
    d1[n]=d2[n]=0;
    for(i=0;i<gr[n].size();i++)
    {
        if(!v[gr[n][i].first] && gr[n][i].second!=ex)
        {
            k=dfs(gr[n][i].first)+1;
            if(k>d1[n])
            {
                d2[n]=d1[n];
                d1[n]=k;
                b[n]=a[n];
                a[n]=gr[n][i].first;
            }
            else if(k>d2[n]) d2[n]=k,b[n]=gr[n][i].first;
        }
    }
    diam=max(diam,d1[n]+d2[n]);
    return d1[n];
}

void dfs2(int n,int par)
{
    v[n]=1;
    int x=d1[n],y=d2[n],d,c,nwpar;
    if(par>=x)
    {
        d=par;
        c=0;
        nwpar=par+1;
    }
    else
    {
        d=d1[n];
        c=a[n];
        nwpar=max(d2[n],par)+1;
    }
    if(d<mxd)
    {
        mxd=d;
        mxv=n;
    }
    for(int i=0;i<gr[n].size();i++)
    {
        if(!v[gr[n][i].first] && gr[n][i].second!=ex)
        {
            if(gr[n][i].first!=c) dfs2(gr[n][i].first,d+1);
            else dfs2(gr[n][i].first,nwpar);
        }
    }
}
int main()
{
    int t,i,j,k,n,x,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        gr.clear();
        gr.resize(n+1);
        x=0;
        for(i=1;i<n;i++)
        {
            x++;
            scanf("%d %d",&j,&k);
            gr[j].pb(mp(k,x));
            gr[k].pb(mp(j,x));
            edge[x].first=j;
            edge[x].second=k;
        }
        int mndiam=INF,curdiam,p,q,del,nw1,nw2;
        for(i=1;i<n;i++)
        {
            ex=i;
            curdiam=0;
            memset(v,0,sizeof(v));
            diam=-1;
            dfs(edge[i].first);
            curdiam=max(diam,curdiam);
            diam=-1;
            dfs(edge[i].second);
            curdiam=max(diam,curdiam);
            memset(v,0,sizeof(v));
            mxd=INF;
            dfs2(edge[i].first,0);
            p=1+mxd;
            x=mxv;
            mxd=INF;
            dfs2(edge[i].second,0);
            p+=mxd;
            y=mxv;
            curdiam=max(curdiam,p);
            if(curdiam<mndiam)
            {
                mndiam=curdiam;
                del=i;
                nw1=x;
                nw2=y;
            }
        }
        printf("%d\n",mndiam);
        printf("%d %d\n",edge[del].first,edge[del].second);
        printf("%d %d\n",nw1,nw2);
    }
    return 0;
}
