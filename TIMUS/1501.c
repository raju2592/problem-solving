#include<stdio.h>
#include<string.h>
int dp[1005][1005],n;
char str1[1005],str2[1005];
int calc(int first,int second)
{
    int i;
    if(dp[first][second]!=0) return dp[first][second];
    if(first==n && second==n) return 5;
    if(first==n)
    {
        for(i=second;i<n-1;i+=2) if(str2[i]==str2[i+1]) return dp[first][second]=4;
        return dp[first][second]=2;
    }
    if(second==n)
    {
        for(i=first;i<n-1;i+=2) if(str1[i]==str1[i+1]) return dp[first][second]=4;
        return dp[first][second]=1;
    }
    if(str1[first]!=str2[second])
    {
        if(calc(first+1,second+1)!=4) return dp[first][second]=1;
    }
    if(first+1<n && str1[first]!=str1[first+1])
    {
        if(calc(first+2,second)!=4) return dp[first][second]=2;
    }
    if(second+1<n && str2[second]!=str2[second+1])
    {
        if(calc(first,second+2)!=4) return dp[first][second]=3;
    }
    return dp[first][second]=4;
}
void print(int first,int second)
{
    int i;
    if(first==n && second==1) return;
    if(first==n)
    {
        for(i=second;i<n;i++) printf("2");
        return;
    }
    if(second==n)
    {
        for(i=first;i<n;i++) printf("1");
        return;
    }
    if(dp[first][second]==1)
    {
        printf("12");
        print(first+1,second+1);
    }
    else if(dp[first][second]==2)
    {
        printf("11");
        print(first+2,second);
    }
    else
    {
        printf("22");
        print(first,second+2);
    }

}
int main()
{
    scanf("%d\n",&n);
    scanf("%s%s",str1,str2);
    calc(0,0);
    if(dp[0][0]==4) printf("Impossible\n");
    else print(0,0);
    putchar('\n');
    return 0;
}





























