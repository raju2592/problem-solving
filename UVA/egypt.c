#include<stdio.h>

void main()
{
	int arr[3],i,j,key;

	while(1)
	{
		scanf("%d %d %d",&arr[0],&arr[1],&arr[2]);
		if(arr[1]==0 && arr[2]==0 && arr[0]==0)
			break;
		for(i=1;i<3;i++)
		{
			key=arr[i];
			j=i-1;
			while(arr[j]>key && j>=0)
			{
				arr[j+1]=arr[j];
				j--;
			}
			arr[j+1]=key;
		}

		if(arr[0]*arr[0]+arr[1]*arr[1]==arr[2]*arr[2])
			printf("right\n");

		else printf("wrong\n");
	}

}