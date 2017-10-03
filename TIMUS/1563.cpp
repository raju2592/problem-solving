#include<iostream>
#include<vector>
#include<utility>
#include<cstring>
#define pb push_back
#define mp make_pair
using namespace std;

int arr[50000+5],n,k;
int ch[2][50000+5];
vector<vector<pair<int,int> > > gr;
vector<int> p;
int ans=-1,val;
vector<int> out;
int calc(int u)
{
    int first=0,second=0;
    for(int i=0;i<gr[u].size();i++)
    {
        if(gr[u][i].first==p[u]) continue;
        p[gr[u][i].first]=u;
        int xx=gr[u][i].second+calc(gr[u][i].first);
        if(xx>=first) second=first,first=xx,ch[1][u]=ch[0][u],ch[0][u]=gr[u][i].first;
        else if(xx>second) second=xx,ch[1][u]=gr[u][i].first;
    }
    if(first+second+arr[u]>=ans) ans=first+second+arr[u],val=u;
    return first+arr[u];
}

void fun(int fl,int u)
{
    if(ch[0][u]!=-1 && fl!=2) fun(1,ch[0][u]);
    out.pb(u);
    if(fl==0)
    {
        if(ch[1][u]!=-1) fun(2,ch[1][u]);
    }
    else if(fl==2)
    {
        if(ch[0][u]!=-1) fun(2,ch[0][u]);
    }
}
int main()
{
    int i,j,k,l;
    cin>>n>>k;
    gr.resize(n+1);
    for(i=1;i<=n;i++) cin>>arr[i];
    while(k--)
    {
        cin>>i>>j>>l;
        gr[j].pb(mp(i,l));
        gr[i].pb(mp(j,l));
    }
    memset(ch,-1,sizeof(ch));
    p.resize(n+1);
    for(i=1;i<=n;i++) p[i]=-1;
    for(i=1;i<=n;i++) if(p[i]==-1) calc(i);
	//cout<<gr[1][0].first;
    cout<<ans<<endl;
    fun(0,val);
    cout<<out.size()<<endl;
    for(i=0;i<out.size();i++) cout<<out[i]<<" ";
    return 0;
}
