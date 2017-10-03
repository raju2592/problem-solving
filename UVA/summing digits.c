#include<stdio.h>
#include<string.h>

int get_sum(int n);

void main()
{

	char arr[11];

	int sum,len,i;

	for(;;)
	{
		sum=0;
		gets(arr);

		if(strlen(arr)==1 && arr[0]=='0') break;

		len=strlen(arr);

		for(i=0;i<len;i++) arr[i]-=48;

		for(i=0;i<len;i++) sum+=arr[i];

		if( sum<=9) printf("%d\n",sum);

		else printf("%d\n",get_sum(sum));
	}

}

int get_sum(int n)
{

	int sum=0;

	for(;n!=0;)
	{
		sum=sum+(n%10);

		n=n/10;

	}

	if(sum<=9) return sum;

	else return get_sum(sum);

	
}
