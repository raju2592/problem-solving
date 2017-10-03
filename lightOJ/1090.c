#include<stdio.h>
#define MAX 1000000
#define ll long long
ll two[1000005],five[1000005];

void c2()
{
    ll cnt=1,val=2,i;
    while(val<=MAX)
    {
        for(i=1;val*i<=MAX;i+=2) two[val*i]=cnt;
        val*=2;
        cnt++;
    }
    for(i=2;i<=MAX;i++) two[i]+=two[i-1];

}
void c5()
{
    ll cnt=1,val=5,i;
    while(val<=MAX)
    {
        for(i=1;val*i<=MAX;i++)
        {
            if(i%5==0) continue;
            five[val*i]=cnt;
        }
        val*=5;
        cnt++;
    }
    for(i=2;i<=MAX;i++) five[i]+=five[i-1];
}
int main()
{
    ll i,j,k,l,t,c,ans,x,y,n,r,p,q;
    c2();
    c5();
    scanf("%lld",&t);
    for(c=1;c<=t;c++)
    {
        scanf("%lld %lld %lld %lld",&n,&r,&p,&q);
        ans=0;
        i=0;
        while(p%10==0)
        {
            i++;
            p/=10;
        }
        ans+=i*q;
        x=two[n]-two[r]-two[n-r];
        y=five[n]-five[r]-five[n-r];
        i=j=0;
        while(p%2==0) p/=2,i++;
        while(p%5==0) p/=2,j++;
        x+=i*q;
        y+=j*q;
        ans+=x<y?x:y;
        printf("Case %lld: %lld\n",c,ans);
    }
    return 0;
}
