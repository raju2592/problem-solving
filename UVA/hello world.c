#include<stdio.h>

void main()
{
	int paste,n,line,i;
	for(i=1;;i++)
	{
		scanf("%d",&n);
		if(n<0) break;
		paste=0;
		line=1;
		while(line<n)
		{
			line=line*2;
			paste++;
		}

		printf("Case %d: %d\n",i,paste);

	}

}
