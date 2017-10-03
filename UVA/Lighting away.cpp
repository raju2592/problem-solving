#include<iostream>
#include<vector>
using namespace std;
#define ll long
vector<vector<ll> > gr;//rev;
vector<ll> v;
vector<ll> aft;
void visit1(ll n)
{
    v[n]=1;
    for(ll i=0;i<gr[n].size();i++)
    {
        if(v[gr[n][i]]==0) visit1(gr[n][i]);
    }
    aft.push_back(n);
}
void dfs1()
{
    ll i,j;
    for(i=1;i<gr.size();i++) v[i]=0;
    j=0;
    for(i=1;i<gr.size();i++)
    {
        if(v[i]==0) visit1(i);
    }
}
void visit2(ll n)
{
    v[n]=1;
    for(ll i=0;i<gr[n].size();i++)
    {
        if(v[gr[n][i]]==0) visit2(gr[n][i]);
    }
}
ll dfs2()
{
    ll i,j;
    for(i=1;i<gr.size();i++) v[i]=0;
    i=aft.size()-1,j=0;
    while(i>=0)
    {
		//cout<<aft[i]<<endl;
        if(v[aft[i]]==0)
        {
            j++;
            //if(j>1) return false;
            visit2(aft[i]);
        }
        i--;
    }
    return j;
}
int main()
{
    ll n,m,i,j,k,l,t;
    cin>>t;
    for(ll c=1;c<=t;c++)
    {
        cin>>n>>m;
        gr.clear();
        gr.resize(n+1);
        for(i=0;i<m;i++)
        {
            cin>>j>>k;
            gr[j].push_back(k);
            //rev[k].push_back(j);
        }
        v.clear();
        v.resize(n+1);
        aft.clear();
        dfs1();
        //for(i=0;i<aft.size();i++) cout<<aft[i]<<' ';
        //cout<<endl;
        ll cc=dfs2();
        cout<<"Case "<<c<<": "<<cc<<endl;
    }
    return 0;
}
