#include<iostream>
#include<vector>
using namespace std;
#define ll long
vector<vector<ll> > gr,rev;
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
    for(ll i=0;i<rev[n].size();i++)
    {
        if(v[rev[n][i]]==0) visit2(rev[n][i]);
    }
}
bool dfs2()
{
    ll i,j;
    for(i=1;i<rev.size();i++) v[i]=0;
    i=aft.size()-1,j=0;
    while(i>=0)
    {
		//cout<<aft[i]<<endl;
        if(v[aft[i]]==0)
        {
            j++;
            if(j>1) return false;
            visit2(aft[i]);
        }
        i--;
    }
    return true;
}
int main()
{
    ll n,m,i,j,k,l;
    while(cin>>n>>m)
    {
        gr.clear();
        gr.resize(n+1);
        rev.clear();
        rev.resize(n+1);
        if(n==0 && m==0) break;
        for(i=0;i<m;i++)
        {
            cin>>j>>k>>l;
            gr[j].push_back(k);
            rev[k].push_back(j);
            if(l==2)
            {
                gr[k].push_back(j);
                rev[j].push_back(k);
            }
        }
        v.clear();
        v.resize(n+1);
        aft.clear();
        dfs1();
        //for(i=0;i<aft.size();i++) cout<<aft[i]<<' ';
        //cout<<endl;
        bool cc=dfs2();
        if(cc) cout<<1<<endl;
        else cout<<0<<endl;
    }
    return 0;
}
