#include<stdio.h>
#include<string.h>
#define ll long long
ll max(ll i,ll j){return i>j?i:j;}
ll convert(char *arr,ll lft,ll rt)
{
    ll ret=0,i=rt,pow=1;
    {
        while(i>=lft)
        {
            ret+=pow*(arr[i]-'0');
            pow*=10;
            i--;
        }
    }
    return ret;
}
int main()
{
    ll i,l,j,m,k,t,dp[500];
    char str[505];
    scanf("%lld\n",&t);
    while(t--)
    {
        gets(str);
        l=strlen(str);
        dp[l-1]=str[l-1]-'0';
        dp[l]=0;
        for(i=l-2;i>=0;i--)
        {
            dp[i]=-100;
            k=(i+9)<l-1?i+9:l-1;
            for(j=i;j<=k;j++)
            {
                m=convert(str,i,j);
                if(m<=2147483647 && m+dp[j+1]>dp[i]) dp[i]=m+dp[j+1];
            }
        }
        printf("%lld\n",dp[0]);
    }
    return 0;
}
