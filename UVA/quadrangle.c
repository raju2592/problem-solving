#include<stdio.h>

void main()
{

	int n,arr[4],i,j,k,key;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&arr[0],&arr[1],&arr[2],&arr[3]);
		for(j=1;j<4;j++)
		{
			key=arr[j];
			k=j-1;

			while(arr[k]>key&& k>=0)
			{
				arr[k+1]=arr[k];
				k--;
			}

			arr[k+1]=key;

		}

		if(arr[1]==arr[2] && arr[2]==arr[3] && arr[3]==arr[0])
			printf("square\n");

		else if(arr[0]==arr[1] && arr[2]==arr[3])
			printf("rectangle\n");

		else if(arr[0]+arr[1]+arr[2]>arr[3])
			printf("quadrangle\n");

		else printf("banana\n");

	}

			
}
