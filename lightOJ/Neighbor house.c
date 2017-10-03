#include<stdio.h>

typedef struct
{
    int r;
    int g;
    int b;
} house;
long long min(long long i,long long j)
{
    return i<j?i:j;
}
int main()
{
    int t,n,i,j,k,c;
    long long dp[2][3],*prev,*cur,*tm,ans;
    house arr[22];
    scanf("%d",&t);
    for(c=1;c<=t;c++)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++) scanf("%d %d %d",&arr[i].r,&arr[i].g,&arr[i].b);
        prev=dp[0];
        cur=dp[1];
        prev[0]=arr[1].r;
        prev[1]=arr[1].g;
        prev[2]=arr[1].b;
        for(i=2;i<=n;i++)
        {
            cur[0]=arr[i].r+min(prev[1],prev[2]);
            cur[1]=arr[i].g+min(prev[0],prev[2]);
            cur[2]=arr[i].b+min(prev[0],prev[1]);
            tm=cur;
            cur=prev;
            prev=tm;
        }
        ans=min(prev[0],prev[1]);
        ans=min(ans,prev[2]);
        printf("Case %d: %lld\n",c,ans);
    }
    return 0;
}
