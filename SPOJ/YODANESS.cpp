#include<iostream>
#include<map>
#include<string>
#include<cstring>
#include<sstream>
#include<cstdio>
#define ll long
using namespace std;
ll n;
ll read(ll * bit,ll idx)
{
    ll sum=0;
    while(idx>0)
    {
        sum+=bit[idx];
        idx-=(idx & -idx);
    }
    return sum;
}
void updt(ll *bit, ll idx)
{
	while(idx<=n)
	{
		bit[idx]++;
		idx+=(idx & -idx);
	}
}
int main()
{
    ll t,i,j,k,bit[30005];
    string s,s1;
    map<string,ll> mp;
    cin>>t;
    while(t--)
    {
        scanf("%lld\n",&n);
        k=0;
        getline(cin,s1);
        for(i=0;i<n;i++)
        {
            cin>>s;
            k++;
            mp[s]=k;
        }
        memset(bit,0,sizeof(bit));
        ll ans=0;
		stringstream ss(s1);
        for(i=0;i<n;i++)
        {
            ss>>s;
            k=mp[s];
            updt(bit,k);
            ans+=read(bit,n)-read(bit,k);
        }
        cout<<ans<<endl;
    }
    return 0;
}
