#include<stdio.h>

void main()
{
	int t,a,b,i,n,ans;

	scanf("%d",&t);

	for(i=1;i<=t;i++)
	{
		scanf("%d",&a);

		scanf("%d",&b);

		if(a%2==0) a=a+1;

		if(b%2==0) b=b-1;

		n=(b-a)/2+1;

		ans=(n*(2*a+(n-1)*2))/2;

		printf("Case %d: %d\n",i,ans);
	}

}





		

