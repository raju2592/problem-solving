#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main()
{
	long int N,i;
    long long int *arr,a;
	long double n;

	scanf("%ld",&N);

	arr=(long long int *) malloc(N*sizeof(long long int));

	for(i=0;i<N;i++) scanf("%lld",&arr[i]);
	for(i=0;i<N;i++)
	{
		a=(arr[i]-1)*2;
		n=(1+sqrt(1+4*a))/2;


        if(ceil(n)==floor(n)) printf("1 ");
        else printf("0 ");

	}

}


