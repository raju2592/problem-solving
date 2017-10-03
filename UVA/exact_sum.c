#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int i,j,k,N;
	long int books[10002],M,sum,price1,price2,min_diff,tem;
	while(scanf("%d\n",&N)!=EOF)
	{
		for(i=1;i<=N;i++) scanf("%ld",&books[i]);
		scanf("%ld",&M);
		price1=0;
		price2=0;
		min_diff=3000000;
		for(i=1;i<=N;i++)
		{
			for(j=i+1;j<=N;j++)
			{
				if(books[i]+books[j]==M)
				{
					tem=abs(books[i]-books[j]);
					if(tem<min_diff)
					{
						min_diff=tem;
						price1=books[i];
						price2=books[j];
					}
				}
			}
		}
		if(price1<=price2) printf("Peter should buy books whose prices are %ld and %ld.\n\n",price1,price2);
		else printf("Peter should buy books whose prices are %ld and %ld.\n\n",price2,price1);
	}
	return 0;
}