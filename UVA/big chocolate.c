#include<stdio.h>
int main()
{
	long int m,n;
	while(scanf("%ld %ld",&n,&m)!=EOF)
	{
		printf("%ld\n",n*m-1);
	}
	return 0;
}