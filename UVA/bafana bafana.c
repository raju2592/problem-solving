#include<stdio.h>

void main()
{

	int T,i;

	int N,K,P,ans;

	scanf("%d",&T);

	for(i=1;i<=T;i++)
	{
		scanf("%d %d %d",&N,&K,&P);

		ans=K+P%N;

		if(ans>N) ans=ans%N; 

		printf("Case %d: %d\n",i,ans);
	}

}
