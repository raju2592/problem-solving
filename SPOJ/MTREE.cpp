#include<iostream>
#include<vector>
#include<utility>
#define pb push_back
#define mp make_pair
#define ll long long
#define mod 1000000007
using namespace std;

vector<vector<pair<ll,ll> > > gr;
ll v[100005];
ll ans=0;

ll dfs(ll n)
{
    v[n]=1;
    ll sum=0;
    for(ll i=0;i<gr[n].size();i++)
    {
        if(!v[gr[n][i].first])
        {
            ll k=dfs(gr[n][i].first);
            ll x=(k*gr[n][i].second+gr[n][i].second)%mod;
            ans=(ans+sum*x)%mod;
            sum=(sum+x)%mod;
        }
    }
    ans=(ans+sum)%mod;
    return sum;
}

int main()
{
    ll n,i,j,k,l;
    cin>>n;
    gr.resize(n+1);
    for(i=1;i<n;i++)
    {
        cin>>j>>k>>l;
        gr[j].pb(mp(k,l));
        gr[k].pb(mp(j,l));
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}
