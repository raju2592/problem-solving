#include<stdio.h>
#include<string.h>

int main()
{

	char arr[35];

	unsigned long int decimel,i,two_k1,len;

	char tmp;

	while(1)
	{

		gets(arr);

		if(strlen(arr)==1 && arr[0]=='0') break;

		decimel=0;

		two_k1=1;

		len=strlen(arr);

		for(i=0;i<len/2;i++)
		{
			tmp=arr[i];

			arr[i]=arr[len-1-i];

			arr[len-1-i]=tmp;

		}



		for(i=0;i<len;i++) arr[i]-=48;

		for(i=0;i<len;i++)
		{
			two_k1=two_k1*2;

			decimel=decimel+arr[i]*(two_k1-1);

		}

		printf("%lu\n",decimel);

	}

	return 0;

}
			



