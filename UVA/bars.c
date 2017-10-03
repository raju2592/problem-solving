#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int bars[25],dp[25][1005];

int subset_sum(int n,int w)
{
	int optimal,temp;
	if(n==1 && bars[1]<=w) return bars[1];
	if(n==1 && bars[1]>w) return 0;
	if(w<=0) return 0;
	if(dp[n][w]!=-1) return dp[n][w];
	optimal=subset_sum(n-1,w);
	temp=subset_sum(n-1,w-bars[n])+bars[n];
	if(temp<=w && temp>optimal) optimal=temp;
	dp[n][w]=optimal;
	return dp[n][w];
}

int main()
{
	int i,j,t,n,p,can_make;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%d",&p);
		for(i=1;i<=p;i++) scanf("%d",&bars[i]);
		for(i=0;i<25;i++)
			for(j=0;j<1005;j++) dp[i][j]=-1;
		can_make=subset_sum(p,n);
		if(can_make==n) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}