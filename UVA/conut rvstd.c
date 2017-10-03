//brute force

#include<stdio.h>
#include<math.h>

int check(unsigned long int n,unsigned long int i);

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
		found=0;
		for(i=sqrt((n-1));i>=2;i--)
		{
			j=0;
			rem=n;
			while(j<i)
			{
				if((rem-1)%i==0)
				{
					j++;
					rem=rem-1-(rem-1)/i;
				}
				else 
				{
					rem=-1;
					break;
				}
			}
			if(rem!=-1)
			{
				if(rem%i==0)
				{
					printf("%ld coconuts, %ld people and 1 monkey\n",n,i);
				    found=1;
				    break;
				}
			}
			
		}
		if(found==0) printf("%ld coconuts, no solution\n",n);
	}
}

/*int check(unsigned long int n,unsigned long int i)
{
	if(j==i) return n;
	else
	{
		if((n-1)%i==0)
		{
			j++;
			check(((n-1)*(i-1))/i,i);
		}
		else return -1;
	}

	
}*/
			
