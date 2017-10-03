#include<stdio.h>
#include<math.h>

void main()
{
	long int n,i,rem,j;
	int found;
	while(scanf("%ld",&n)!=EOF)
	{
		if(n<0) break;
		if(n==0) 
		{
			printf("0 coconuts, no solution\n");
			continue;
		}
		else if(n==3)
		{
			printf("3 coconuts, 2 people and 1 monkey\n");
			continue;
		}

		found=0;
		for(i=sqrt(n-1);i>=2;i--)
		{
			if((n-1)%i==0)
			{
				j=0;
				rem=n;
				while(j<i)
				{
					if((rem-1)%i==0) 
					{
						rem=rem-(rem-1)/i-1;
						j++;
					}
					else break;
				}
				if(j==i)
				{
					if(rem%i==0)
					{
						found=1;
						printf("%ld coconuts, %ld people and 1 monkey\n",n,i);
						break;
					}
				}

					
			}
			
		}
		if(found==0) printf("%ld coconuts, no solution\n",n);
	}
}
