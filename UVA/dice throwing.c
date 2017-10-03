#include<stdio.h>

unsigned long long GCD(unsigned long long a,unsigned long long b)
{
    if(a%b==0) return b;
    else return GCD(b,a%b);
}
int main()
{
    unsigned long long  all,for_x,gcd,dp[26][910];
    int n,x,i,j,k;
    for(i=0;i<26;i++)
        for(j=0;j<910;j++) dp[i][j]=0;
    for(i=1;i<=6;i++) dp[i][i]=1;
    for(i=1;i<=6;i++) dp[1][i]=1;
    for(i=2;i<=6;i++)
    {
        for(j=2;j<i;j++)
        {
            for(k=1;k<i;k++) dp[j][i]+=dp[j-1][i-k];
        }
    }
    for(i=2;i<26;i++)
    {
        for(j=7;j<910;j++)
        {
            for(k=1;k<=6;k++) dp[i][j]+=dp[i-1][j-k];
        }
    }
    while(1)
    {
        scanf("%d %d",&n,&x);
        if(n==0 && x==0) break;
        all=0;
        for_x=0;
        if(x==0)
        {
            printf("1\n");
            continue;
        }
        for(i=n;i<=n*6;i++) all+=dp[n][i];
        for(i=x;i<=n*6;i++) for_x+=dp[n][i];
        if(for_x==0) printf("0\n");
        else if(all==for_x) printf("1\n");
        else
        {
            gcd=GCD(all,for_x);
            all/=gcd;
            for_x/=gcd;
            printf("%llu/%llu\n",for_x,all);
        }
    }
    return 0;
}
