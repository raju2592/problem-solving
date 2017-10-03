#include<iostream>
#include<vector>
#include<utility>
#define ll long long
using namespace std;
vector<vector<pair<ll,ll> > >gr;
vector<ll> v,mxn;
ll n,m,mx;
ll dfs(ll n)
{
    v[n]=1;
    ll i,ret=1;
    for(i=0;i<gr[n].size();i++)
    {
        if(gr[n][i].second==mx && v[gr[n][i].first]==0) ret+=dfs(gr[n][i].first);
    }
    return ret;
}
int main()
{
    ll i,j,k,l,ans;
    while(1)
    {
        cin>>n>>m;
        if(n==0 && m==0) break;
        gr.clear();
        v.clear();
        gr.resize(n+1);
        v.resize(n+1);
        mx=-9999999999;
        mxn.clear();
        for(i=1;i<=m;i++)
        {
            cin>>j>>k>>l;
            gr[j].push_back(make_pair(k,l));
            gr[k].push_back(make_pair(j,l));
            if(l>mx)
            {
                mx=l;
                mxn.clear();
                mxn.push_back(j);
                mxn.push_back(k);
            }
            else if(l==mx)
            {
                mxn.push_back(j);
                mxn.push_back(k);
            }
        }
        for(i=1;i<=n;i++) v[i]=0;
        i=mxn.size()-1;
        ans=-9999999999;
        while(i>=0)
        {
            if(v[mxn[i]]==0) ans=max(ans,dfs(mxn[i]));
            i--;
        }
        cout<<ans<<endl;
    }
    return 0;
}
