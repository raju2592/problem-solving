#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
long long dp[2][140][140];
int main()
{
    int t,i,j,k;
    string s,my;
    cin>>t;
    getchar();
    while(t--)
    {
        getline(cin,s);
        my="";
        for(i=0;i<s.size();i++)
        {
            if(s[i]=='T') my.push_back('1');
            else if(s[i]=='F') my.push_back('0');
            else if(s[i]=='a')
            {
                my.push_back('&');
                i+=2;
            }
            else if(s[i]=='o')
            {
                my.push_back('|');
                i+=1;
            }
            else if(s[i]=='x')
            {
                my.push_back('^');
                i+=2;
            }

        }
        //cout<<my<<endl;
        for(i=0;i<my.size();i++)
        {
            dp[0][i][i]=dp[1][i][i]=0;
            if(my[i]=='0') dp[0][i][i]=1;
            else if(my[i]=='1') dp[1][i][i]=1;
            else dp[0][i][i]=dp[1][i][i]=-1;
        }
        for(i=2;i<=my.size();i++)
        {
            //cout<<"dhukse"<<i<<endl;
            for(j=0;j<=s.size()-i;j++)
            {
                if((my[j]!='0' && my[j]!='1') || (my[j+i-1]!='0' && my[j+i-1]!='1'))
                {
                    dp[0][j][j+i-1]=dp[1][j][j+i-1]=-1;
                    continue;
                }
                dp[0][j][j+i-1]=dp[1][j][j+i-1]=0;
                for(k=j+1;k<j+i-1;k++)
                {
                    //cout<<k<<endl;
                    if(my[k]=='&')
                    {
                        dp[0][j][j+i-1]+=dp[0][j][k-1]*dp[1][k+1][j+i-1]+dp[1][j][k-1]*dp[0][k+1][j+i-1]+dp[0][j][k-1]*dp[0][k+1][j+i-1];
                        dp[1][j][j+i-1]+=dp[1][j][k-1]*dp[1][k+1][j+i-1];
                    }
                    else if(my[k]=='|')
                    {
                        //cout<<dp[1][j][k-1]<<' '<<dp[0][k+1][j+i-1];
                        dp[1][j][j+i-1]+=dp[0][j][k-1]*dp[1][k+1][j+i-1]+dp[1][j][k-1]*dp[0][k+1][j+i-1]+dp[1][j][k-1]*dp[1][k+1][j+i-1];
                        dp[0][j][j+i-1]+=dp[0][j][k-1]*dp[0][k+1][j+i-1];
                    }
                    else if(my[k]=='^')
                    {
                        dp[1][j][j+i-1]+=dp[0][j][k-1]*dp[1][k+1][j+i-1]+dp[1][j][k-1]*dp[0][k+1][j+i-1];
                        dp[0][j][j+i-1]+=dp[0][j][k-1]*dp[0][k+1][j+i-1]+dp[1][j][k-1]*dp[1][k+1][j+i-1];
                    }
                }
            }
        }
        cout<<dp[1][0][my.size()-1]<<endl;
    }
    return 0;
}
