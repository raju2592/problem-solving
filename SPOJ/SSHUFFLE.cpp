#include<iostream>
#include<cstring>
#define ll long long
using namespace std;
ll dp[65][65][65];
int main()
{
    ll i,j,k,a,t,len1,len2,len3;
    char str1[70],str2[70],str3[70];
    cin>>t;
    while(t--)
    {
        cin>>str1>>str2>>str3;
        len1=strlen(str1),len2=strlen(str2),len3=strlen(str3);
        memset(dp,0,sizeof(dp));
        for(i=0;i<65;i++)
            for(j=0;j<65;j++) dp[i][j][len3]=1;
        for(i=len3-1;i>=0;i--)
        {
            for(j=0;j<=len1;j++)
            {
                for(k=0;k<=len2;k++)
                {
                    dp[j][k][i]=0;
                    for(a=j;a<len1;a++)
                    {
                        if(str3[i]==str1[a]) dp[j][k][i]+=dp[a+1][k][i+1];
                    }
                    for(a=k;a<len2;a++)
                    {
                        if(str3[i]==str2[a]) dp[j][k][i]+=dp[j][a+1][i+1];
                    }
                }
            }
        }
        cout<<dp[0][0][0]<<endl;
    }
    return 0;
}
