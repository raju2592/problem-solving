#include<iostream>
#include<vector>
#define ll long long
using namespace std;
vector<vector<ll> > gr;
vector<ll> v,aft;
bool dfs(ll n)
{
    v[n]=1;
    bool ret;
    for(ll i=0;i<gr[n].size();i++)
    {
        if(v[gr[n][i]]==0)
        {
            ret=dfs(gr[n][i]);
            if(!ret) return ret;
        }
        else if(v[gr[n][i]]==1) return false;
    }
    v[n]=2;
    aft.push_back(n);
    return true;
}
int main()
{
    ll n,m,i,j,k,l;
    while(1)
    {
        cin>>n>>m;
        if(n==0 && m==0) break;
        v.clear();
        gr.clear();
        v.resize(n+1);
        gr.resize(n+1);
        for(i=0;i<m;i++)
        {
            cin>>j>>k;
            gr[j].push_back(k);
        }
        aft.clear();
        bool b=true;
        for(i=1;i<=n;i++) v[i]=0;
        for(i=1;i<=n;i++)
        {
            if(v[i]==0)
            {
                b=dfs(i);
                if(!b) break;
            }
        }
        if(!b) cout<<"IMPOSSIBLE\n";
        else
        {
            i=aft.size()-1;
            while(i>=0)
            {
                cout<<aft[i]<<endl;
                i--;
            }
        }
    }
    return 0;
}
