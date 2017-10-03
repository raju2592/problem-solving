#include<stdio.h>
#include<math.h>
#define max(i,j) i>j?i:j
typedef struct
{
    long a;
    long b;
} pair;
int main()
{
    int n,i,j,k;
    pair rect[1005],dp[1005];
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++) scanf("%ld %ld",&rect[i].a,&rect[i].b);
        dp[n].a=rect[n].b;
        dp[n].b=rect[n].a;
        for(i=n-1;i>=1;i--)
        {
            dp[i].a=max(rect[i].b+abs(rect[i].a-rect[i+1].a)+dp[i+1].a,rect[i].b+abs(rect[i].a-rect[i+1].b)+dp[i+1].b);
            dp[i].b=max(rect[i].a+abs(rect[i].b-rect[i+1].a)+dp[i+1].a,rect[i].a+abs(rect[i].b-rect[i+1].b)+dp[i+1].b);
        }
        printf("%ld\n",max(dp[1].a,dp[1].b));
    }
    return 0;
}
