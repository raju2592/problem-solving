#include<stdio.h>

typedef struct
{
    int row;
    int col;
    int key;
} elem;

void q_sort(elem *arr,int l,int r)
{
	int i,j,q;
	elem x,temp;
	if(l<r)
	{
		x=arr[r];
		i=l-1;
		for(j=l;j<r;j++)
		{
			if(arr[j].key<=x.key)
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
    int i,j,k,R,C,t,mat[101][101],dp[101][101],lp,lowest,r,c;
    char name[50];
    elem arr[10005];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s %d %d",name,&R,&C);
        k=0;
        if(R==0 || C==0)
        {
            printf("%s :0\n",name);
            continue;
        }
        for(i=0;i<R;i++)
        {
            for(j=0;j<C;j++)
            {
                scanf("%d",&mat[i][j]);
                arr[k].key=mat[i][j];
                arr[k].row=i;
                arr[k].col=j;
                k++;
            }
        }
        q_sort(arr,0,R*C-1);
        lowest=arr[0].key;
        lp=1;
        i=0;
        while(arr[i].key==lowest)
        {
            dp[arr[i].row][arr[i].col]=1;
            i++;
        }
        while(i<R*C)
        {
            r=arr[i].row;
            c=arr[i].col;
            dp[r][c]=1;
            if(r-1>=0 && mat[r-1][c]<mat[r][c]) dp[r][c]=dp[r-1][c]+1;
            if(r+1<R && mat[r+1][c]<mat[r][c] && dp[r+1][c]+1>dp[r][c]) dp[r][c]=dp[r+1][c]+1;
            if(c-1>=0 && mat[r][c-1]<mat[r][c] && dp[r][c-1]+1>dp[r][c]) dp[r][c]=dp[r][c-1]+1;
            if(c+1<C && mat[r][c+1]<mat[r][c] && dp[r][c+1]+1>dp[r][c]) dp[r][c]=dp[r][c+1]+1;
            if(dp[r][c]>lp) lp=dp[r][c];
            i++;
        }
        printf("%s: %d\n",name,lp);

    }
    return 0;
}
