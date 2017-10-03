#include<stdio.h>
#include<string.h>
#include<math.h>
#define ll long long
ll p[1000005];
ll bit[1000005];
void sieve()
     {
       ll i,j,k;
       p[0]=0;
       p[1]=0;
       for(i=2;i<=1000000;i++) p[i] = 1;
       k=(ll)sqrt(1000000)+1;
       for(i=2;i<=k;i++)
         if (p[i])
           for(j=i;j*i<=1000000;j++) p[i*j] = 0;
     }
void updt(ll n,ll up)
{
    while(n<=1000000)
    {
        bit[n]+=up;
        n+=n&-n;
    }
}
ll read(ll n)
{
	ll sum=0;
    if(n==0) return 0;
    while(n>0)
    {
        sum+=bit[n];
        n-=n&-n;
    }
    return sum;
}
ll sum(ll n)
{
    ll ret=0;
    while(n!=0)
    {
        ret+=n%10;
        n/=10;
    }
    return ret;
}
int main()
{
    ll t,i,j,k,l,m,n;
    sieve();
    memset(bit,0,sizeof(bit));
    for(i=1;i<=1000000;i++)
    {
        if(p[i])
        {
            j=sum(i);
            if(p[j]) updt(i,1);
        }
    }
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&j,&k);
        printf("%lld\n",read(k)-read(j-1));
    }
    return 0;
}
