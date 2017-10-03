#include<cstdio>
#include<vector>
using namespace std;
#define ll long long
vector<vector<ll> > gr;
ll ans,v,N;
void dfs(ll n,ll d)
{
    for(ll i=0;i<gr[n].size();i++)
    {
        dfs(gr[n][i],d+1);
    }
    ans+=N-v-d-1;
    v++;
}
int main()
{
    ll t,i,j,k;
    scanf("%lld",&t);
    for(ll c=1;c<=t;c++)
    {
        scanf("%lld",&N);
        gr.clear();
        gr.resize(N+1);
        for(i=0;i<N-1;i++)
        {
            scanf("%lld %lld",&j,&k);
            gr[j].push_back(k);
        }
        ans=0;
        v=0;
        dfs(1,0);
        printf("Case %lld: %lld %lld\n",c,N-1,ans);
    }
    return 0;
}
