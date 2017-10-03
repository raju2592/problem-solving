#include<stdio.h>
#include<string.h>

int dp[1005][1005];

int max(int i,int j)
{
    return i>j?i:j;
}
int main()
{
    int t,i,j,k,l;
    char str[1005];
    scanf("%d",&t);
    gets(str);
    while(t--)
    {
        gets(str);
        l=strlen(str);
        if(l==0)
        {
            printf("0\n");
            continue;
        }
        memset(dp,0,sizeof(dp));
        for(i=0;i<l;i++) dp[i][i]=1;
        for(i=1;i<l;i++) dp[i][i-1]=0;
        for(i=2;i<=l;i++)
        {
            for(j=0;j<=l-i;j++)
            {
                if(str[j]==str[j+i-1]) dp[j][j+i-1]=2+dp[j+1][j+i-2];
                else dp[j][j+i-1]=max(dp[j+1][j+i-1],dp[j][j+i-2]);
            }
        }
        printf("%d\n",dp[0][l-1]);
    }
    return 0;
}
