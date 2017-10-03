#include<stdio.h>

int f91(int n)
{
	int tmp;

	if(n>=101) return n-10;

	else
	{
		tmp=f91(n+11);

		return f91(tmp);

	}

}

void main()
{
	unsigned long int n;

	while(1)
	{
		scanf("%lu",&n);

		if(n==0) break;

		printf("f91(%lu) = %d\n",n,f91(n));

	}

}

