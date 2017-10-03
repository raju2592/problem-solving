#include<stdio.h>
#include<string.h>
void main()
{
	char num[1001];
	int sum,i,j;
	while(1)
	{
		scanf("%s",num);
		if(strlen(num)==1 && num[0]=='0') break;
		j=strlen(num)-1;
		i=0;
		sum=0;
		while(j-i>=0)
		{
			if(i%2==0) sum+=num[j-i]-48;
			else sum+=(num[j-i]-48)*10;
			i++;
		}
		if(sum%11==0) printf("%s is a multiple of 11.\n",num);
		else printf("%s is not a multiple of 11.\n",num);
	}
}

