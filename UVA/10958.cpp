#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#define MAX 1000005
#define ll long //long
using namespace std;

ll p[1000005];
vector<ll> pr;

void sieve()
{
    ll i,j,k;
    for(j=1;j<=MAX;j++) p[j]=1;
    k=sqrt(MAX);
    for(i=2;i<=k;i++)
    {
        if(p[i])
        {
            pr.push_back(i);
            for(j=i;i*j<=MAX;j++) p[i*j]=0;
        }
    }
    for(;i<=MAX;i++) pr.push_back(i);
}

int main()
{
    ll i,j,k,kase=1,m,n,p,a,ab,ans,cnt;
    sieve();
	//for(i=0;i<10;i++) cout<<pr[i];
    while(cin>>m>>n>>p)
    {
		if(m==0 && n==0 && p==0) break;
        ab=p*p*m*n;
        a=p*m;
        if(ab<0) ab=-ab;
        k=sqrt(ab);
        ans=1;
        for(i=0;i<pr.size() && pr[i]<=k;i++)
        {
            cnt=0;
            while(ab%pr[i]==0)
            {
                cnt++;
                ab/=pr[i];
            }
            ans*=(cnt+1);
			k=sqrt(ab);
        }
        if(ab>1) ans*=2;
		ans*=2;
        ans--;
        printf("Case %lld: %lld\n",kase,ans);
        kase++;
    }
    return 0;
}
