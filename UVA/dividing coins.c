#include<stdio.h>

long int coins[102],opt[102][25010];
long int subset_sum(long int n,long int weight)
{
	long int optimal,tem;
	if(n==1 && coins[n]<=weight) return coins[n];
	if(n==1 && coins[n]>weight) return 0;
	if(weight<=0) return 0;
	if(opt[n][weight]!=-100) return  opt[n][weight];
	optimal=subset_sum(n-1,weight);
	tem=subset_sum(n-1,weight-coins[n])+coins[n];
	if(tem>optimal && tem<=weight) 
		optimal=tem;
	opt[n][weight]=optimal;
	return optimal;
}
int main()
{
	long int n,i,j,m,sum,optimal;
	scanf("%ld",&n);
	while(n--)
	{
		for(i=0;i<102;i++)
		{
			for(j=0;j<25010;j++) opt[i][j]=-100;
		}
		scanf("%ld",&m);
		for(i=1;i<=m;i++) scanf("%ld",&coins[i]);
		sum=0;
		for(i=1;i<=m;i++) sum+=coins[i];
		optimal=subset_sum(m,sum/2);
		printf("%ld\n",sum-2*optimal);
	}
	return 0;
}