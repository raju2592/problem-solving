#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	char num[11],num_max[11],num_min[11];
	int mini,i,k,key;
	long long int  max,min,diff;
	while(scanf("%s",num)!=EOF)
	{
		strcpy(num_max,num);
		strcpy(num_min,num);
		mini=0;
		for(i=1;i<strlen(num_min);i++)
		{
			if( num_min[i]!='0' && num_min[i]<num_min[mini])
			{
				mini=i;
			}
		}
		i=num_min[0];
		num_min[0]=num_min[mini];
		num_min[mini]=i;
		for(i=1;i<strlen(num_max);i++)
		{
			key=num_max[i];
			k=i-1;

			while(num_max[k]<key && k>=0)
			{
				num_max[k+1]=num_max[k];
				k--;
			}

			num_max[k+1]=key;

		}

		for(i=2;i<strlen(num_min);i++)
		{
			key=num_min[i];
			k=i-1;

			while(num_min[k]>key && k>=1)
			{
				num_min[k+1]=num_min[k];
				k--;
			}

			num_min[k+1]=key;

		}
		max=atof(num_max);
		min=atof(num_min);
		diff=max-min;
		printf("%s - %s = %lld = 9 * %lld\n",num_max,num_min,diff,diff/9);
	}
}





