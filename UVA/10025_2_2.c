#include<stdio.h>
void main()
{
	int t;
long int k,n,sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%ld",&k);
		if(k<0) k=-k;
		n=0;
		sum=0;
		if(k==0)
		{
			if(t==0) printf("3\n");
			else printf("3\n\n");
			continue;
		}
		while(sum<k || (sum-k)%2!=0)
		{
			n++;
			sum+=n;
		}
		if(t==0) printf("%ld\n",n);
		else printf("%ld\n\n",n);

	}
}




