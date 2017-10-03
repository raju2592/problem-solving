#include<stdio.h>
#include<string.h>

int main()
{
    char str[5005];
    long long dp[5005];
    int i,j,k,l;
    while(1)
    {
        scanf("%s",str);
        if(str[0]=='0') break;
        l=strlen(str);
        dp[l]=1;
        if(str[l-1]=='0') dp[l-1]=0;
        else dp[l-1]=1;
        for(i=l-2;i>=0;i--)
        {
            dp[i]=0;
            if(str[i]!='0')
            {
                dp[i]+=dp[i+1];
                k=(str[i]-48)*10+str[i+1]-48;
                if(k<=26) dp[i]+=dp[i+2];
            }
        }
        printf("%lld\n",dp[0]);
    }
    return 0;
}
