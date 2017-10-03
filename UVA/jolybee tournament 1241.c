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

	int T,N,M,arr[1050],temp_M,i,j,w_o_mat,found_odd,temp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&N,&M);
		for(i=0;i<M;i++) scanf("%d",&arr[i]);
		q_sort(arr,0,M-1);
		temp_M=M;
		w_o_mat=0;
		for(i=1;i<=N;i++)
		{
			if(temp_M==0) break;
			temp=0;
			found_odd=0;
			for(j=0;j<temp_M;j++)
			{
				if(found_odd==0 && arr[j]%2==0) w_o_mat++;
				else if(found_odd==0 && arr[j]%2==1) found_odd=1;
				else if(found_odd==1 && arr[j]%2==0 && arr[j]-arr[j-1]!=1)
				{
					found_odd=0;
					w_o_mat=w_o_mat+2;
				}
				else if(found_odd==1 && arr[j]%2==0 && arr[j]-arr[j-1]==1)
				{
					found_odd=0;
					arr[temp]=arr[j]/2;
					temp++;
				}

				else if(found_odd==1 && arr[j]%2==1) w_o_mat++;
			}
			if(found_odd==1) w_o_mat++;
			temp_M=temp;
		}
		printf("%d\n",w_o_mat);

	}
	return 0;
}

