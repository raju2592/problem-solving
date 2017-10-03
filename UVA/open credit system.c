#include<stdio.h>
int main()
{
    long int i,j,k,current_diff,max_diff,n,temp;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%ld",&n);
        scanf("%ld",&i);
        scanf("%ld",&j);
        max_diff=current_diff=i-j;
        i=j;
        for(k=3;k<=n;k++)
        {
            scanf("%ld",&j);
			temp=i-j;
			current_diff=temp+current_diff;
			if(temp>current_diff) current_diff=temp;
			if(current_diff>max_diff) max_diff=current_diff;
			i=j;
        }
        printf("%ld\n",max_diff);
    }
    return 0;
}
