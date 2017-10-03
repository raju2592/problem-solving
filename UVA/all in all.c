#include<stdio.h>
#include<string.h>

void main()
{
	char str1[1000000],str2[1000000];
	int completed,i,j;
	while(scanf("%s %s",str1,str2)!=EOF)
	{
	    completed=0;
	    for(i=0;i<strlen(str2);i++)
	    {
	        if(str2[i]==str1[0])
	        {
	            completed=1;
	            for(j=i+1;j<strlen(str2) && completed<strlen(str1);j++)
	            {
					if(str2[j]==str1[completed]) completed++;

	            }
				/*if(completed<strlen(str1)) completed=0;*/
				break;

	        }

	    }
		if(completed<strlen(str1)) printf("No\n");
		else printf("Yes\n");
	}
}
