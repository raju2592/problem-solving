#include<iostream>
#include<cstring>
#define ll long
using namespace std;
ll dp[120][120],ch[120][120];
char str[120];
void print_ans(ll i,ll j)
{
    if(j-i<0) return;
    if(ch[i][j]==105 || ch[i][j]==106)
    {
        cout<<"()";
        print_ans(i+1,j);
    }
    else if(ch[i][j]==107 || ch[i][j]==108)
    {
        cout<<"[]";
        print_ans(i+1,j);
    }
    else
    {
        if(str[i]=='(')
        {
            cout<<'(';
            print_ans(i+1,ch[i][j]-1);
            cout<<')';
            print_ans(ch[i][j]+1,j);
        }
        if(str[i]=='[')
        {
            cout<<'[';
            print_ans(i+1,ch[i][j]-1);
            cout<<']';
            print_ans(ch[i][j]+1,j);
        }
    }
}
int main()
{
    cin>>str;
    ll l=strlen(str),i,j,k;
    for(i=0;i<=l;i++)
    {
        if(str[i]=='(') dp[i][i]=2,ch[i][i]=105;
        else if(str[i]==')') dp[i][i]=2,ch[i][i]=106;
        else if(str[i]=='[') dp[i][i]=2,ch[i][i]=107;
        else dp[i][i]=2,ch[i][i]=108;
        if(i!=0) dp[i][i-1]=0;
    }
    for(k=2;k<=l;k++)
    {
        for(i=0;i<=l-k;i++)
        {
            dp[i][i+k-1]=2+dp[i+1][i+k-1];
            if(str[i]=='(') ch[i][i+k-1]=105;
            else if(str[i]==')') ch[i][i+k-1]=106;
            else if(str[i]=='[') ch[i][i+k-1]=107;
            else ch[i][i+k-1]=108;
            if(str[i]=='(')
            {
                for(j=i+1;j<=i+k-1;j++)
                {
                    if(str[j]==')' && 2+dp[i+1][j-1]+dp[j+1][i+k-1]<dp[i][i+k-1])
                    {
                        dp[i][i+k-1]=2+dp[i+1][j-1]+dp[j+1][i+k-1];
                        ch[i][i+k-1]=j;
                    }
                }
            }
            else if(str[i]=='[')
            {
                for(j=i+1;j<=i+k-1;j++)
                {
                    if(str[j]==']' && 2+dp[i+1][j-1]+dp[j+1][i+k-1]<dp[i][i+k-1])
                    {
                        dp[i][i+k-1]=2+dp[i+1][j-1]+dp[j+1][i+k-1];
                        ch[i][i+k-1]=j;
                    }
                }
            }
        }
    }
    //cout<<dp[0][l-1];
    print_ans(0,l-1);
	cout<<endl;
    return 0;
}
