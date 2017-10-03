#include<iostream>
#include<cstring>
using namespace std;
#define mod 1000000000
#define ll long long
int bit[25][20000+5];
ll tot[25];
ll n;
void updt(ll k,ll ind,ll up)
{
    while(ind<=n)
    {
        bit[k][ind]=(bit[k][ind]+up)%mod;
        ind+=(ind & -ind);
    }
}
ll read(ll k,ll ind)
{
    ll sum=0;
    while(ind>0)
    {
        sum=(sum+bit[k][ind])%mod;
        ind-=(ind & -ind);
    }
	return sum;
}
ll MOD(ll a,ll b)
{
    return (a%b+b)%b;
}
int main()
{
    ll i,k,j,x;
    cin>>n>>k;
    memset(bit,0,sizeof(bit));
    memset(tot,0,sizeof(0));
    ll ans=0;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        updt(1,x,1);
        for(j=2;j<k;j++) updt(j,x,MOD(read(j-1,n)-read(j-1,x),mod));
        ans=(ans+MOD(read(k-1,n)-read(k-1,x),mod))%mod;
    }
    cout<<ans<<endl;
	return 0;
}
