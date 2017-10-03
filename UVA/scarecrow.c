#include<stdio.h>
int main()
{
    int t,n,i,j,count;
    char fld[105];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        scanf("%s",fld);
        count=0;
        for(j=n-1;j>=0;j--)
        {
            if(fld[j]=='.')
            {
                count++;
                j-=2;
            }
        }
        printf("Case %d: %d\n",i,count);
    }
    return 0;
}
