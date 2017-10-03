#include<stdio.h>
#include<math.h>
int main()
{
	int n,m,nums[1002],sums[27],Case=1,i,j,k,sum,tem;
	while(1)
	{
		scanf("%d",&n);
		if(n==0) break;
		for(i=0;i<n;i++) scanf("%d",&nums[i]);
		scanf("%d",&m);
		for(i=0;i<m;i++) scanf("%d",&sums[i]);
		printf("Case %d:\n",Case);
		for(i=0;i<m;i++)
		{
			sum=nums[0]+nums[1];
			for(j=0;j<n;j++)
			{
				for(k=j+1;k<n;k++)
				{
					tem=nums[j]+nums[k];
					if(abs(sums[i]-tem)<abs(sums[i]-sum)) sum=tem;
				}

			}
			printf("Closest sum to %d is %d.\n",sums[i],sum);
		}
		Case++;

	}
	return 0;
}