#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

ll n,k,arr[100005],sum[100005];
ll dp[15][100005];
ll all,pt;

vector<ll> M,C;


bool bad(ll a,ll b,ll c)
{
    return ((M[a]-M[b])*(C[c]-C[a])<(M[a]-M[c])*(C[b]-C[a]));
}

void add(ll m,ll c)
{
    M.pb(m);C.pb(c);
    while(M.size()>=3 && bad(M.size()-3,M.size()-2,M.size()-1))
    {
        M.erase(M.end()-2);
        C.erase(C.end()-2);
    }
}

ll query(ll x)
{
    if(pt>=M.size()) pt=M.size()-1;
    while(pt<M.size()-1 && M[pt+1]*x+C[pt+1]>M[pt]*x+C[pt]) pt++;
    return M[pt]*x+C[pt];
}

int main()
{
    ll i,j,a,b;
    //cin>>n>>k;
    scanf("%lld %lld",&n,&k);
    for(i=1;i<=n;i++) scanf("%lld",&arr[i]);//cin>>arr[i];
    sum[n]=arr[n];
    for(i=n-1;i>=1;i--) sum[i]=sum[i+1]+arr[i];
    all=0;
    for(i=2;i<=n;i++) all+=(i-1)*arr[i];
    for(i=1;i<=n;i++) dp[1][i]=0;
    for(i=2;i<=k;i++)
    {
        M.clear();
        C.clear();
        pt=0;
        for(a=n;a>=1;a--)
        {
            if(n-a+1<i) dp[i][a]=-1;
            else dp[i][a]=query(-a);
            if(dp[i-1][a]!=-1) add(sum[a],dp[i-1][a]+a*sum[a]);
        }
    }
    //cout<<all-dp[k][1]<<endl;
    printf("%lld\n",all-dp[k][1]);
    return 0;
}
