#include<stdio.h>

void main()
{
	unsigned long long int n,i;
	while(1)
	{
		scanf("%llu",&n);
		if(n==0) break;
		for(i=0;i<10;i++)
		{
			if((n-i)%9==0)
			{
				if(i==0) printf("%llu %llu\n",(n/9)*10-1,(n/9)*10);
				else
					printf("%llu\n",((n-i)/9)*10+i);
				break;
			}
		}
	}
}

