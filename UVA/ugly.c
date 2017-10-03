#include<stdio.h>

long int min(long int *arr,int *i,int *j,int *k)
{
	long int p,q,r;
	p=2*arr[*i];
	q=3*arr[*j];
	r=5*arr[*k];
	if(p<=q && p<=r)
	{
		(*i)++;
		return p;
	}
	else if(q<p && q<=r)
	{
		(*j)++;
		return q;
	}
	else if(r<p && r<q)
	{
		(*k)++;
		return r;
	}
}


void main()
{
	long int arr[1500],temp;
	int i,j,k,l;
	arr[0]=1;
	i=0;
	j=0;
	k=0;
	l=0;
	while(l<1499)
	{
		temp=min(arr,&i,&j,&k);
		if(temp>arr[l])
		{
			arr[l+1]=temp;
			l++;
		}
	}
	printf("The 1500'th ugly number is %d.\n",arr[1499]);
}
