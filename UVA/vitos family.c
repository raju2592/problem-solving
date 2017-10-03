#include<stdio.h>


void q_sort(int *arr,int l,int r)
{
	int x,i,j,q,temp;
	if(l<r)
	{
		x=arr[r];
		i=l-1;
		for(j=l;j<r;j++)
		{
			if(arr[j]<=x)
			{
				i++;
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
		temp=arr[i+1];
		arr[i+1]=arr[j];
		arr[j]=temp;
		q=i+1;
		q_sort(arr,l,q-1);
		q_sort(arr,q+1,r);
	}
}

int main()
{
	int t,r,rel[502],i,left,right;
	long int left_diff,right_diff,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&r);
		for(i=1;i<=r;i++) scanf("%d",&rel[i]);
		q_sort(rel,1,r);
		left=0;
		right=r-1;
		left_diff=0;
		right_diff=0;
		for(i=2;i<=r;i++) right_diff+=rel[i]-rel[1];
		ans=right_diff;
		for(i=2;i<=r;i++)
		{
			left++;
			right--;
			left_diff+=left*(rel[i]-rel[i-1]);
			right_diff-=(right+1)*(rel[i]-rel[i-1]);
			if(left_diff+right_diff<ans) ans=left_diff+right_diff;
		}
		printf("%ld\n",ans);

	}
	return 0;
}