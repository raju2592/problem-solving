#include<stdio.h>
int arr[50],n,k;
long long dp[50][50];

long long dpf(int p,int s)
{
    if(p>2*n-s+1) return 0;
    if(s==2*n)
    {
        if(p==1) return 1;
        else return 0;
    }
    if(dp[p][s]!=-1) return dp[p][s];
    dp[p][s]=dpf(p+1,s+1);
    if(arr[s]==0 && p!=0) dp[p][s]+=dpf(p-1,s+1);
    return dp[p][s];
}
int main()
{
    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        for(i=0;i<50;i++) arr[i]=0;
        for(i=0;i<k;i++)
        {
            scanf("%d",&j);
            arr[j]=1;
        }
        for(i=0;i<50;i++)
            for(j=0;j<50;j++) dp[i][j]=-1;
        if(n==1 && k==1 && arr[1]==1) printf("1\n");
        else if(arr[2*n]==1) printf("0\n");
        else printf("%lld\n",dpf(1,2));
    }
}
