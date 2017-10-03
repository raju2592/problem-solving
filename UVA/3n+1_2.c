#include<stdio.h>

void main()
{
	unsigned long int num1,num2,i,temp,j,count,swap=0;

	for(;scanf("%lu %lu",&num1,&num2)!=EOF;)
	{
		swap=0;

		if(num1==0 && num2==0) break;

		if(num1>num2)
		{
			temp=num1;

			num1=num2;

			num2=temp;

			swap=1;
		}


		temp=0;

		

	    for(i=num1;i<=num2;i++)
		{
	    	j=i;

	    	count=1;

	    	while(j!=1)

			{
	    		if(j%2==0) j=j/2;

		    	else j=3*j+1;

		    	count++;

			}

	    	if(count>temp)
			{

		    	temp=count;
			}
		}

		if(swap==0) printf("%lu %lu %lu\n",num1,num2,temp);

		else if(swap==1) printf("%lu %lu %lu\n",num2,num1,temp);




	}


}



