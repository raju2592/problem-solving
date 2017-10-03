#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void q_sort(int *arr,int l,int r);

void main()
{
	int n,i,*p,*q,j,not_jolly=0;
	while(1)
	{
		not_jolly=0;

		if(scanf("%d",&n)==EOF) break;

		p=(int *) malloc(n*sizeof(int));

		for(i=0;i<n;i++) scanf("%d",&p[i]);

		q=(int *) malloc((n-1)*sizeof(int));

		for(j=0;j<n-1;j++) q[j]=abs(p[j]-p[j+1]);

		q_sort(q,0,n-2);

		for(j=0;j<n-1;j++) 
		{
			if(q[j]!=j+1)
			{
				not_jolly=1;
				break;
			}
		}

		if(not_jolly==1) printf("Not jolly\n");
		else printf("Jolly\n");

		
	}
}

void q_sort(int *arr,int l,int r)
{
	int x,i,j,q,temp;

	if(l<r)
	{
		x=arr[r];

		i=l-1;

		for(j=l;j<r;j++)
		{
			if(arr[j]<=x)
			{
				i++;

				temp=arr[i];

				arr[i]=arr[j];

				arr[j]=temp;

			}

		}

		temp=arr[i+1];

		arr[i+1]=arr[j];

		arr[j]=temp;

		q=i+1;

		q_sort(arr,l,q-1);

		q_sort(arr,q+1,r);

	}
	
}


