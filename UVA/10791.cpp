#include<iostream>
#include<cmath>
#include<vector>
#define MAX 100002
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;

ll p[100005];
vector<ll> pr;

void sieve()
{
    ll i,j,k;
    for(i=1;i<=MAX;i++) p[i]=1;
    k=sqrt(MAX);
    for(i=2;i<=k;i++)
    {
        if(p[i])
        {
            pr.push_back(i);
            for(j=i;i*j<=MAX;j++) p[i*j]=1;
        }
    }
    for(;i<=MAX;i++) pr.pb(i);
}

int main()
{
    ll i,j,k,n,kase=0,pw;
    ll ans,a,b,cnt;
    sieve();
    while(cin>>n)
    {
        kase++;
        if(n==0) break;
        if(n==1)
        {
            cout<<"Case "<<kase<<": "<<2<<endl;
            continue;
        }
        k=sqrt(n);
        ans=cnt=0;
        for(i=0;i<pr.size() && pr[i]<=k;i++)
        {
            pw=1;
            while(n%pr[i]==0)
            {
                n/=pr[i];
                pw*=pr[i];
            }
            if(pw>1)
            {
                ans+=pw;
                cnt++;
            }
            k=sqrt(n);
        }
        if(n>1)
        {
            ans+=n;
            cnt++;
        }
        if(cnt==1) ans++;
        /*mx=(1<<fact.size())-1;
        bit=fact.size();
        //cout<<mx<<endl;
        ans=x+1;
        for(i=0;i<mx;i++)
        {
            a=b=1;
            for(j=0;j<bit;j++)
            {
                if(i&(1<<j)) a*=fact[j];
                else b*=fact[j];
            }
            ans=min(ans,a+b);
        }*/
        cout<<"Case "<<kase<<": "<<ans<<endl;
        //kase++;
    }
    return 0;
}
