#include<stdio.h>

int self(long int n);
int no_digit(long int n);
int digisum(long int n);

void main()
{
	long int i;

	for(i=1;i<=1000080;i++)
	{
		if(self(i)) printf("%ld\n",i);

	}


}

int self(long int n)
{
	int dig=no_digit(n);

	long int i=n-9*dig;

	if(i<0) i=0;

	for(;i<n;i++)
	{
		if(i+digisum(i)==n) return 0;
	}

	return 1;

}

int no_digit(long int n)
{
	int dig=0;

	while(n>0)
	{
		n=n/10;

		dig++;
	}

	return dig;
}

int digisum(long int n)
{
	int sum=0;

	while(n>0)
	{
		sum=sum+n%10;

		n=n/10;

	}

	return sum;

}


