#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<utility>
#define pb push_back
#define mp make_pair
#define MAX 1000
#define mod 1000000007LL
#define ll long long
using namespace std;

ll nCr[1005][1005];
vector<vector<ll> > gr;

void precal()
{
    /*fact[0]=fact[1]=1;
    for(ll i=2;i<=MAX;i++) fact[i]=(fact[i-1]*(ll)i)%mod;*/

    nCr[0][0]=nCr[1][0]=nCr[1][1]=1;
    for(ll i=2;i<=MAX;i++)
    {
        nCr[i][0]=nCr[i][i]=1;
        for(ll j=1;j<i;j++) nCr[i][j]=(nCr[i-1][j]+nCr[i-1][j-1])%mod;
    }
}

pair<ll,ll> dfs(ll n)
{
    vector<ll> cnt;
    ll x=0,y=1,i;
    pair<ll,ll> u;
    for(i=0;i<gr[n].size();i++)
    {
        u=dfs(gr[n][i]);
        cnt.pb(u.first);
        x+=u.first;
        y=(y*u.second)%mod;
    }
    ll p=x;
    for(i=0;i<cnt.size();i++)
    {
        y=(y*nCr[p][cnt[i]])%mod;
        p-=cnt[i];
    }
    return make_pair(x+1,y);
}
int main()
{
    precal();
    ll t,n,i,j,k,ans,cs=1,in[1005],rt;
    cin>>t;
    while(t--)
    {
        cin>>n;
        gr.clear();
        gr.resize(n+1);
        memset(in,0,sizeof(in));
        for(i=1;i<n;i++)
        {
            cin>>j>>k;
            gr[j].pb(k);
            in[k]=1;
        }
        for(i=1;i<=n;i++) if(in[i]==0) rt=i;
        //cout<<rt;
        printf("Case %lld: %lld\n",cs++,dfs(rt).second);
    }
    return 0;
}


















