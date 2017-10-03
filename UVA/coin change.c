#include<stdio.h>

long long int dp[6][7499];
int coins[]={0,50,25,10,5,1};
long long int coinchange(int c,int w)
{
    int i,j,k,rem;
    long long int ans;
    if(dp[c][w]!=-100) return dp[c][w];
    if(w==0) return 1;
    if(c==5) return 1;
    rem=w;
    ans=0;
    for(i=0;;i++)
    {
        ans+=coinchange(c+1,rem);
        rem-=coins[c];
        if(rem<0) break;
    }
    dp[c][w]=ans;
    return dp[c][w];
}
int main()
{
    int n,i,j;
    for(i=0;i<6;i++)
        for(j=0;j<7499;j++) dp[i][j]=-100;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%lld\n",coinchange(1,n));
    }
    return 0;
}
