#include<stdio.h>
int main()
{
	int t,c;
	unsigned long int n,i,k,r[100006],max_diff,diff[100006];
	scanf("%d",&t);
	for(c=1;c<=t;c++)
	{
		scanf("%lu",&n);
		for(i=0;i<n;i++) scanf("%lu",&r[i]);
		max_diff=r[0];
		diff[0]=r[0];
		for(i=1;i<n;i++)
		{
			diff[i]=r[i]-r[i-1];
			if(diff[i]>max_diff) max_diff=diff[i];
		}
		k=max_diff;
		for(i=0;i<n;i++)
		{
			if(diff[i]==k) k--;
			else if(diff[i]>k) break;
		}
		if(i==n) printf("Case %d: %lu\n",c,max_diff);
		else printf("Case %d: %lu\n",c,max_diff+1);

	}
	return 0;
}