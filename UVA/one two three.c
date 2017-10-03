#include<stdio.h>
#include<string.h>
void main()
{
	int t,diff,i;
	char num[6], test[4];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",num);
		diff=0;
		if(strlen(num)==5) printf("3\n");
		else
		{
			strcpy(test,"two");
			for(i=0;i<3;i++)
			{
				if(num[i]!=test[i]) diff++;
			}
			if(diff<=1) printf("2\n");
			else printf("1\n");
		}
	}
}
			