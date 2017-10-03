#include<cstdio>
#include<iostream>
#include<vector>
#include<utility>
#include<map>
#define pb push_back
#define mp make_pair
using namespace std;

vector<vector<int> > gr;
vector<int> d,v;
map<pair<int,int>,int> brdg;

int min (int i,int j){return i<j?i:j;}

int dfs(int n)
{
    int i,j,k;
    int low=d[n];
    for(i=0;i<gr[n].size();i++)
    {
        if(n!=0 && d[gr[n][i]]==d[n]-1) continue;
        if(d[gr[n][i]]==0)
        {
            d[gr[n][i]]=d[n]+1;
            k=dfs(gr[n][i]);
            if(k>d[n])
            {
                //cout<<n<<" "<<gr[n][i]<<endl;
                //gr[n][i].second=1;
                brdg[mp(n,gr[n][i])]=1;
                brdg[mp(gr[n][i],n)]=1;
            }
            else low=min(low,k);
        }
        else low=min(low,d[gr[n][i]]);
    }
    return low;
}
int dfs2(int n)
{
    int i,ret;
    v[n]=1;
    ret=0;
    for(i=0;i<gr[n].size();i++)
    {
        if(brdg[mp(n,gr[n][i])] || brdg[mp(gr[n][i],n)]) //if bridge then count
        {
            ret++;
            continue;
        }
        if(!v[gr[n][i]]) ret+=dfs2(gr[n][i]);
    }
    return ret;
}
int main()
{
    int t,n,m,cs,i,j,k;
    scanf("%d",&t);
    cs=0;
    while(t--)
    {
        scanf("%d %d",&n,&m);
        brdg.clear();
        gr.clear();
        d.clear();
        gr.resize(n);
        d.resize(n);
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&j,&k);
            gr[j].pb(k);
            gr[k].pb(j);
        }
        d[0]=1;
        dfs(0);
        v.clear();
        v.resize(n);
        int ans=0;
        for(i=0;i<n;i++)
        {
            if(!v[i])
            {
                k=dfs2(i);
                if(k==1) ans++;
            }
        }
        //if(ans) ans--;
        printf("Case %d: %d\n",++cs,ans/2+ans%2);
    }
    return 0;
}
