#include<stdio.h>
#include<string.h>

int main()
{
    int t,i,j,la,lb,ans;
    char a[20005],b[105];
    int dp[20005];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",a);
        scanf("%s",b);
        la=strlen(a);
        lb=strlen(b);
        ans=-1;
        for(i=0;i<la;i++)
        {
            if(a[i]==b[0])
            {
                dp[i]=1;
                if(lb==1)
                {
                    ans=1;
                    goto pr_ans;
                }
            }
            else dp[i]=0;
        }
        for(i=2;i<=la;i++)
        {
            for(j=0;j<=la-i;j++)
            {
                if(a[j+i-1]==b[dp[j]])
                {
                    dp[j]=dp[j]+1;
                    if(dp[j]==lb)
                    {
                        ans=i;
                        goto pr_ans;
                    }
                }
            }
        }
    pr_ans:
        printf("%d\n",ans);
    }
    return 0;
}
