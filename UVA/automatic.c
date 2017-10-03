#include<stdio.h>
#include<math.h>
void main()
{
	int t,n;
	long int ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=abs(315*n+36962)/10;
		printf("%d\n",ans%10);
	}
}