#include<stdio.h>

int main()
{
	int n,p,q,i,j,k,c,eggs[35],w,taken;
	scanf("%d",&c);
	for(i=1;i<=c;i++)
	{
		scanf("%d %d %d",&n,&p,&q);
		for(j=1;j<=n;j++) scanf("%d",&eggs[j]);
		taken=0;
		w=0;
		j=1;
		while(taken<p && taken<n)
		{
			if(w+eggs[j]>q) break;
			else
			{
				w+=eggs[j];
				taken++;
			}
			j++;
		}

		printf("Case %d: %d\n",i,taken);

	}
	return 0;
}