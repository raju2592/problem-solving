#include<stdio.h>
int main()
{
	int m,n,t,i,j,big,small,found_ans,ans,time;
	while(scanf("%d %d %d",&m,&n,&t)!=EOF)
	{
		big=m>n?m:n;
		small=m<n?m:n;
		if(big!=small)
		{
			found_ans=0;
			for(i=0;i<=t && found_ans==0;i++)
			{
				time=t-i;
				for(j=0;time>=0;j++)
				{
					if(time%small==0) 
					{
						found_ans=1;
						ans=j+time/small;
						break;
					}
					time-=big;
				}
			}
			if(i==1) printf("%d\n",ans);
			else printf("%d %d\n",ans,i-1);
		}
		else
		{
			if(t%m==0) printf("%d\n",t/m);
			else printf("%d %d\n",t/m,t%m);
		}
	}
	return 0;
}