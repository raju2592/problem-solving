#include<stdio.h>
#define ll long long
int main()
{
    ll c,i,j,k,t,q,n,arr[100005];
    ll ans,curdiff;
    scanf("%lld",&t);
    for(c=1;c<=t;c++)
    {
        scanf("%lld %lld",&n,&q);
        for(i=0;i<n;i++) scanf("%lld",&arr[i]);
        ans=curdiff=0;
        for(i=1;i<n;i++)
        {
            curdiff+=(i)*(arr[i-1]-arr[i]);
            ans+=curdiff;
        }
        printf("Case %lld:\n",c);
        while(q--)
        {
            scanf("%lld",&i);
            if(i) printf("%lld\n",ans);
            else
            {
                scanf("%lld %lld",&j,&k);
                ans+=(arr[j]-k)*(j);
                ans+=(k-arr[j])*(n-1-j);
                arr[j]=k;
            }
        }
    }
    return 0;
}
