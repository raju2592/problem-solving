#include<stdio.h>
int main()
{
	long int n,k;
	while(scanf("%ld %ld",&n,&k)!=EOF)
	{
		if(n%(k-1)==0) printf("%ld\n",n+n/(k-1)-1);
		else printf("%ld\n",n+n/(k-1));
	}
	return 0;
}
