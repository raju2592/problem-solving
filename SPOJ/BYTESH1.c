#include<stdio.h>

int main()
{
    int t,ext[3],ans[3],cur_ext,cur_ans;
    long n,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%ld",&n);
        ext[0]=0;
        ext[1]=1;
        ext[2]=2;
        ans[0]=1;
        ans[1]=1;
        ans[2]=2;
        if(n==1) printf("1\n");
        else if(n==2) printf("2\n");
        else
        {
            for(i=3;i<=n;i++)
            {
                cur_ext=(ans[2]+ext[2])%10000;
                cur_ans=(ans[2]+ans[1]+2*ans[0]+2*ext[0])%10000;
                ans[0]=ans[1];
                ans[1]=ans[2];
                ans[2]=cur_ans;
                ext[0]=ext[1];
                ext[1]=ext[2];
                ext[2]=cur_ext;
            }
            printf("%d\n",ans[2]);
        }
    }
    return 0;
}
