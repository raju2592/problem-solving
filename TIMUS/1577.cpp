#include<iostream>
#include<cstring>
#define mod 1000000007
using namespace std;
int dp[2005][2005];
int ml[2005][2005];
int main()
{
    int i,j,k,len1,len2;
    char str1[2005],str2[2005];
    cin>>str1>>str2;
    len1=strlen(str1);len2=strlen(str2);
    for(i=0;i<len2;i++) dp[len1][i]=1,ml[len1][i]=len2-i;
    for(i=0;i<len1;i++) dp[i][len2]=1,ml[i][len2]=len1-i;
    dp[len1][len2]=1,ml[len1][len2]=0;
    for(i=len1-1;i>=0;i--)
    {
        for(j=len2-1;j>=0;j--)
        {
            if(str1[i]==str2[j])
            {
                dp[i][j]=dp[i+1][j+1];
                ml[i][j]=1+ml[i+1][j+1];
            }
            else
            {
                if(ml[i+1][j]<ml[i][j+1])
                {
                    ml[i][j]=1+ml[i+1][j];
                    dp[i][j]=dp[i+1][j];
                }
                else if(ml[i+1][j]>ml[i][j+1])
                {
                    ml[i][j]=1+ml[i][j+1];
                    dp[i][j]=dp[i][j+1];
                }
                else
                {
                    ml[i][j]=1+ml[i][j+1];
                    dp[i][j]=(dp[i+1][j]+dp[i][j+1])%mod;
                }
            }
        }
    }
    cout<<dp[0][0]<<endl;
    return 0;
}
