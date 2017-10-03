#include<stdio.h>
#include<stdlib.h>
void main()
{
	long int n;
	int m,j,set[10],k,temp,flag;
	char *p;
	while(scanf("%ld %d",&n,&m)!=EOF)
	{
		for(j=0;j<m;j++) scanf("%d",&set[j]);
		p=(char *) malloc((n+1)*sizeof(char));
		flag=0;
		p[0]=0;
		for(j=1;j<=n;j++)
		{
			flag=0;
			for(k=0;k<m;k++)
			{
				temp=j-set[k];
				if(temp==0)
				{
					p[j]=1;
					flag=1;
					break;
				}
				else if(temp>0)
				{
					if(p[temp]==0)
					{
						p[j]=1;
						flag=1;
						break;
					}
				}
			}
			if(flag==0) p[j]=0;
			/*printf("%d %d\n",j,p[j]);*/
		}
		if(p[n]==1) printf("Stan wins\n");
		else printf("Ollie wins\n");


					
		
	}
			
}

