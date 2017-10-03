#include<stdio.h>
int main()
{
    int nums[20];
    int i,j,k,elements,N,c=1;
    long long int max_prod,current_neg_prod,current_pos_prod,temp;
    while(scanf("%d",&N)!=EOF)
    {
        for(i=1;i<=N;i++)
        {
            scanf("%d",&nums[i]);
        }
        elements=i-1;
        max_prod=nums[1];
        if(nums[1]<0)
        {
            current_neg_prod=nums[1];
            current_pos_prod=1;
        }
        else if(nums[1]>0)
        {
            current_pos_prod=nums[1];
            current_neg_prod=1;
        }
        else
        {
            current_neg_prod=1;
            current_pos_prod=1;
        }
        for(i=2;i<=elements;i++)
        {
            if(nums[i]<0)
            {
				temp=current_pos_prod;
                current_pos_prod=current_neg_prod*nums[i];
                if(current_pos_prod>max_prod) max_prod=current_pos_prod;
                if(current_pos_prod<0) current_pos_prod=1;
				current_neg_prod=temp*nums[i];

            }
            else if(nums[i]>0)
            {
                current_pos_prod=current_pos_prod*nums[i];
                if(current_pos_prod>max_prod) max_prod=current_pos_prod;
                current_neg_prod=current_neg_prod*nums[i];
                if(current_neg_prod>1) current_neg_prod=1;
            }
            else if(nums[i]==0)
            {
                if(max_prod<0) max_prod=0;
                current_neg_prod=1;
                current_pos_prod=1;
            }
        }
        if(max_prod>=0) printf("Case #%d: The maximum product is %lld.\n\n",c,max_prod);
        else printf("Case #%d: The maximum product is 0.\n\n",c);
        c++;

    }
    return 0;
}
