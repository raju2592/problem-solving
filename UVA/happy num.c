#include<stdio.h>
int happy(long int n);

void main()
{
	int n,i;

	long int N;

	scanf("%d",&n);

	for(i=1;i<=n;i++)
	{
		scanf("%ld",&N);

		if(happy(N)==1) printf("Case #%d: %ld is a Happy number.\n",i,N);

		else printf("Case #%d: %ld is an Unhappy number.\n",i,N);
	}

}

int happy(long int n)
{
		
	int dig,S=0;

	while(n>0)
	{
		dig=n%10;

	   	S=S+dig*dig;

	   	n=n/10;
	}

	

   	if(S/10==0) return S;

   	else return happy(S);

}