#include<iostream>
#include<cstdio>
#include<cmath>
#define ll unsigned long long
using namespace std;
ll phi[5000006];
void sieve()
{
    ll i,j,k,max=5000000;
    //k=(int) ceil(sqrt(max));
    for(i=0;i<5000006;i++) phi[i]=i;
    for(i=2;i<=max;i++)
    {
        if(phi[i]==i)
        {
            phi[i]=i-1;
            for(j=2;i*j<=max;j++)
            {
                phi[i*j]*=(i-1);
                phi[i*j]/=i;
                //prime[i*j]=0;
            }
        }
    }
    //cum[1]=1;
    //for(i=1;i<=10;i++) cout<<phi[i]<<' ';
    for(i=2;i<=max;i++) phi[i]=phi[i]*phi[i]+phi[i-1];
}
int main()
{
    ll i,j,k,n,t;
    scanf("%llu",&t);
    sieve();
    for(ll c=1;c<=t;c++)
    {
        scanf("%llu %llu",&i,&j);
        printf("Case %llu: %llu\n",c,phi[j]-phi[i-1]);
    }
    return 0;
}
