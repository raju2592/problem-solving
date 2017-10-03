#include<stdio.h>
#define INFINITY 29000;
int main()
{
    int t,price,n,bills[105],i,j,k,optimal[2][20005], *prev, *cur, *tem;
    scanf("%d",&t);
    while(t--)
    {
		scanf("%d",&price);
        scanf("%d",&n);
        for(i=1;i<=n;i++) scanf("%d",&bills[i]);
        optimal[0][0]=0;
        optimal[1][0]=0;
        for(i=1;i<20005;i++)
        {
            optimal[0][i]=INFINITY;
            optimal[1][i]=INFINITY;
        }
        prev=optimal[0];
        cur=optimal[1];
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=price+10000;j++)
            {
                cur[j]=prev[j];
                if(j>=bills[i] && prev[j-bills[i]]+1<cur[j])
                {
                    cur[j]=prev[j-bills[i]]+1;
                }
            }
            tem=cur;
            cur=prev;
            prev=tem;
        }
		for(i=price;;i++)
		{
		    if(prev[i]!=29000)
		    {
		        printf("%d %d\n",i,prev[i]);
		        break;
		    }
		}
    }
    return 0;
}
