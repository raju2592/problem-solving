#include<stdio.h>
#define INF 9999999999999999
#define min(i,j) i<j?i:j
typedef struct
{
    int p;
    int w;
} coin;

int main()
{
    int t,e,f,n,i,j,k;
    coin arr[502];
    long long dp[10005];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&e,&f);
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d %d",&arr[i].p,&arr[i].w);
        dp[0]=0;
        for(i=1;i<=f-e;i++)
        {
            dp[i]=INF;
            for(j=0;j<n;j++)
            {
                if(arr[j].w<=i) dp[i]=min(dp[i],arr[j].p+dp[i-arr[j].w]);
            }
        }
        if(dp[f-e]==INF) printf("This is impossible.\n");
        else printf("The minimum amount of money in the piggy-bank is %lld.\n",dp[f-e]);
    }
    return 0;
}
