#include<stdio.h>
#include<string.h>
int Max(int i,int j){return i>j?i:j;}
int main()
{
    int i,j,k,l,n,m,next[100005];
    char str[100005];
    int dp[100005];
    scanf("%d %d",&n,&m);
    getchar();
    gets(str);
    l=strlen(str);
    k=l;
    for(i=l-1;i>=0;i--)
    {
        if(!(str[i]>='a' && str[i]<='z') && !(str[i]>='A' && str[i]<='Z') && str[i]!=' ') k=i;
        next[i]=k;
    }
    dp[l]=0;
    for(i=l-1;i>=0;i--)
    {
        if(next[i]==l)
        {
            if(i+m>=l) dp[i]=1;
            else dp[i]=1+dp[i+m];
        }
        else
        {
            if(next[i]-i>=m) dp[i]=1+dp[i+m];
            else
            {
                k=Max(n,next[i]-i);
                if(i+k>=l) dp[i]=1;
                else dp[i]=1+dp[i+k];
            }
        }
    }
    printf("%d\n",dp[0]);
    return 0;
}
