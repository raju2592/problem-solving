#include<stdio.h>
#include<math.h>
void main()
{
	int s;
	long long int d,n;
	double k;
	while(scanf("%d %lld",&s,&d)!=EOF)
	{
		k=(1-2*s+sqrt((2*s-1)*(2*s-1)+8*d))/2;
		n=ceil(k);
		printf("%lld\n",s+n-1);
	}
}

