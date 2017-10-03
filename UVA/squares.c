/*greedy method of choosing the largest square closer to N will not work

  examle:
  149=12^2+2^2+1^2=7^2+10^2;

*/

#include<stdio.h>
#include<math.h>
#define INF 15000;

int min_sqr[10002];
int square(int N)
{
    double tmp;
    int i,ans=INF;
    if(min_sqr[N]!=15000)
	{
		return min_sqr[N];
	}
    tmp=sqrt(N);
    if(floor(tmp)==ceil(tmp))
    {
        min_sqr[N]=1;
        return min_sqr[N];
    }
    for(i=N/2;i>=1;i--)
    {
        if(square(i)+square(N-i)<ans) ans=min_sqr[i]+min_sqr[N-i];
    }
    min_sqr[N]=ans;
    return ans;
}
int main()
{
	int N,t,i;
	for(i=0;i<10002;i++) min_sqr[i]=INF;
	scanf("%d",&t);
	while(t--)
	{
        scanf("%d",&N);
        printf("%d\n",square(N));
	}
    return 0;
}
