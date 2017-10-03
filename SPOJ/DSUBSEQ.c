#include<stdio.h>
#include<string.h>
#define m 1000000007

long mod(long a,long b)
{
    return ((a%b)+b)%b;
}
int main()
{
    long i,j,k,t,c;
    char str[100005];
    long total,dp[26];
    scanf("%ld",&t);
    gets(str);
    for(c=1;c<=t;c++)
    {
        gets(str);
        if(!strcmp(str,""))
        {
            printf("1\n");
            continue;
        }
        total=2;
        memset(dp,0,sizeof(dp));
        dp[str[0]-65]=1;
        k=strlen(str);
        for(i=1;i<k;i++)
        {
            j=mod(dp[str[i]-65],m);
            dp[str[i]-65]=mod(total,m);
            total=mod((total*2-j),m);
        }
        printf("%ld\n",mod(total,m));
    }
    return 0;
}
