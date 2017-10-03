#include<stdio.h>
#include<stdlib.h>
#define MINUS_INFINITY -100;

int n,c[53],p[53][53],redir[1003];
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




int b_search(int *arr,int l,int r,int n)
{
	int i,j,m;
	i=l;
	j=r;
	while(i<j)
	{
		m=(i+j)/2;
		if(n>arr[m]) i=m+1;
		else j=m;
	}
	if(n==arr[i]) return i;
	else return -1;
}


long int optimal_cut(int strt,int end)
{
	long int pos,cost,left_cost,right_cost,i,temp_cost;
	if(p[redir[strt]][redir[end]]>=0) return p[redir[strt]][redir[end]];
	pos=b_search(c,0,n+1,strt);
	if(c[pos+1]==end)
	{
		p[redir[strt]][redir[end]]=0;
		return 0;
	}
	cost=99999999;
	for(i=pos+1;c[i]<end;i++)
	{
		left_cost=optimal_cut(strt,c[i]);
		right_cost=optimal_cut(c[i],end);
		p[redir[strt]][redir[c[i]]]=left_cost;
		p[redir[c[i]]][redir[end]]=right_cost;
		temp_cost=end-strt+left_cost+right_cost;
		if(temp_cost<cost) cost=temp_cost;
	}
	p[redir[strt]][redir[end]]=cost;
	return cost;


}

int main()
{
	int l,i,j;
	long int ans;
	while(1)
	{
		scanf("%d",&l);
		if(l==0) break;
		scanf("%d",&n);
		c[0]=0;
		for(i=1;i<=n;i++) scanf("%d",&c[i]);
		c[n+1]=l;
		q_sort(c,1,n);
		j=0;
		for(i=0;i<=n+1;i++,j++) redir[c[i]]=j;
		for(i=0;i<=n+1;i++)
		{
			for(j=0;j<=n+1;j++) p[redir[c[i]]][j]=MINUS_INFINITY;
		}
		ans=optimal_cut(0,l);
		printf("The minimum cutting is %ld.\n",ans);

	}

	return 0;
}
