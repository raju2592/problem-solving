#include<stdio.h>
#define NOT_COMPUTED -100

long long int dp[52][52];

long long int BC(int n,int k,int m)
{
    int i;
    long long int ans=0;
    if(k>n) return 0;
    if(k*m<n) return 0;
	if(k==1 && m<n) return 0;
	else if(k==1 && m>=n) return 1;
    if(dp[n][k]!=NOT_COMPUTED) return dp[n][k];
    for(i=1;i<=m && i<n;i++)
    {
        dp[n-i][k-1]=BC(n-i,k-1,m);
        ans+=dp[n-i][k-1];
    }
    dp[n][k]=ans;
    return ans;
}
int main()
{
	int n,k,m,i,j;
	while(scanf("%d %d %d",&n,&k,&m)!=EOF)
	{
		for(i=0;i<53;i++)
			for(j=0;j<53;j++) dp[i][j]=NOT_COMPUTED;

        printf("%lld\n",BC(n,k,m));
	}
	return 0;
}
