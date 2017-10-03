#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;

ll cnt[12];
ll nCr[12][12];
void calc()
{
    nCr[0][0]=nCr[1][0]=nCr[1][1]=1;
    for(ll i=2;i<12;i++)
    {
        nCr[i][0]=nCr[i][i]=1;
        for(ll j=1;j<i;j++) nCr[i][j]=nCr[i-1][j-1]+nCr[i-1][j];
    }
}
ll mmpw(ll b,ll e)
{
    if(e==0) return 1;
    ll x=mmpw(b,e/2);
    x*=x;
    if(e%2) return x*b;
    return x;
}
ll num_of_len(ll x)
{
    if(x==0) return 1;
    return 9*mmpw(10,x-1);
}
ll find(ll a)
{
    if(a==0) return 1;
	ll i;
    string ss="";
    while(a)
    {
        //ss.push_back((char) a%10+'0');
		ss+=(char) (a%10)+'0';
        a/=10;
    }
    reverse(ss.begin(),ss.end());
    ll ret=1;
    for(i=1;i<ss.size();i++) ret+=cnt[i];
    ll zer[12];
    zer[0]=0;
    for(i=1;i<ss.size();i++) zer[i]=zer[i-1]+(ss[i]=='0'?1:0);
    ret+=zer[ss.size()-1];
    for(i=ss.size()-1;i>=0;i--)
    {
        for(ll j=ss[i]-'0'-1;j>=(i==0?1:0);j--)
        {
            ll k=ss.size()-1-i;
            ll x=i==0?0:zer[i-1]+(j==0);
            for(ll p=0;p<=k;p++)
            {
                ret+=(x+p)*num_of_len(k-p)+cnt[k-p];
            }
        }
    }
    return ret;
}
int main()
{
    ll t,cs,i,j,k;
    ll a,b;
    calc();
    cin>>t;
    cs=1;
    cnt[0]=cnt[1]=0;
    for(i=2;i<=10;i++)
    {
        k=i-1;
        for(j=1;j<i-1;j++) k+= j *(nCr[i-1][j]*mmpw(9,i-1-j));
        cnt[i]=k*9;
    }
    while(t--)
    {
        scanf("%lld %lld",&a,&b);//cin>>a>>b;
        //cout<<a<<b<<endl;
        if(!a) cout<<"Case "<<cs++<<": "<<find(b)<<endl;
        else cout<<"Case "<<cs++<<": "<<find(b)-find(a-1)<<endl;
    }
    //cout<<cnt[2]<<endl;
    return 0;
}
