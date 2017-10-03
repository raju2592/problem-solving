#include<stdio.h>
int main()
{
    int n,i,j,k,bet[10006];
    long int max_sum,current_sum;
    while(1)
    {
        scanf("%d",&n);
        if(n==0) break;
        for(i=1;i<=n;i++) scanf("%d",&bet[i]);
        max_sum=0;
        current_sum=0;
        for(i=1;i<=n;i++)
        {
            current_sum=current_sum+bet[i];
            if(current_sum>max_sum) max_sum=current_sum;
            if(current_sum<0) current_sum=0;
        }
        if(max_sum>0) printf("The maximum winning streak is %ld.\n",max_sum);
		else printf("Losing streak.\n");
    }
	return 0;
}
