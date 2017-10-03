#include<stdio.h>

int main()
{
    int t,n,i,j,k,cs=1,arr[250][250],adj;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++) scanf("%d",&arr[i][j]);
        }
        if(cs++!=1) puts("");
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                adj=1;
                for(k=1;k<=n;k++)
                {
                    if(k==i || k==j) continue;
                    if(arr[i][k]+arr[k][j]==arr[i][j]) adj=0;
                }
                if(adj) printf("%d %d\n",i,j);
            }
        }
    }
    return 0;
}
