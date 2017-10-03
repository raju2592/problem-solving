#include<stdio.h>
void main()
{
	int n,i,arr[50],f,r;
	while(1)
	{
		scanf("%d",&n);
		if(n==0) break;
		if(n==1) 
		{
			printf("Discarded cards:\nRemaining card: 1\n");
		}
		else
		{

	    	for(i=0;i<n;i++) arr[i]=i+1;
	    	printf("Discarded cards: 1");
		    f=1;;
	    	r=n-1;
	    	i=-1;
		    while((n-f+r+1)%n>1)
			{
		    	if(i==1)
				{
		    		printf(", %d",arr[f]);
		    		f=(f+1)%n;
				}
		    	else if(i==-1)
				{
		    		r=(r+1)%n;
			    	arr[r]=arr[f];
			    	f=(f+1)%n;
				}
		    	i=-i;
			}
		    printf("\nRemaining card: %d\n",arr[f]);
		}
	}
}
