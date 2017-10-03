#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
#define front 0
#define back 1
#define left 2
#define right 3
#define top 4
#define bottom 5
class cubes
{
public:
    int f[6];
};

int dp[105][505],ch[105][505];
cubes arr[505];
int n;
int getop(int i)
{
    if(i==0) return 1;
    if(i==1) return 0;
    if(i==2) return 3;
    if(i==3) return 2;
    if(i==4) return 5;
    if(i==5) return 4;
}
int calc(int pc,int st)
{
    if(dp[pc][st]!=-1) return dp[pc][st];
    if(st==n) return 0;
    int &ans=dp[pc][st],i,j,k;
    if(pc==0)
    {
        ans=calc(0,st+1);
        ch[pc][st]=6;
        for(i=0;i<6;i++)
        {
            j=1+calc(arr[st].f[i],st+1);
            if(j>ans)
            {
                ans=j;
                ch[pc][st]=getop(i);
            }
        }
    }
    else
    {
        ans=calc(pc,st+1);
        ch[pc][st]=6;
        for(i=0;i<6;i++)
        {
            if(arr[st].f[i]==pc)
            {
                j=1+calc(arr[st].f[getop(i)],st+1);
                if(j>ans)
                {
                    ans=j;
                    ch[pc][st]=i;
                }
            }
        }
    }
    return ans;
}
void print(int i)
{
    if(i==0) cout<<"front";
    else if(i==1) cout<<"back";
    else if(i==2) cout<<"left";
    else if(i==3) cout<<"right";
    else if(i==4) cout<<"top";
    else if(i==5) cout<<"bottom";
}
void print_ans(int pc,int st)
{
    if(st==n) return;
    if(ch[pc][st]==6) print_ans(pc,st+1);
    else
    {
        cout<<st+1<<' ';
        print(ch[pc][st]);
        cout<<endl;
        print_ans(arr[st].f[getop(ch[pc][st])],st+1);
    }
}
int main()
{
    int i,j,k,c;
    for(c=1;;c++)
    {
        cin>>n;
        if(n==0) break;
        for(i=0;i<n;i++)
        {
            for(j=0;j<6;j++) cin>>arr[i].f[j];
        }
        memset(dp,-1,sizeof(dp));
        memset(ch,6,sizeof(ch));
        //cout<<calc(0,0);
        //cout<<dp[0][0];
        if(c!=1) cout<<endl;
        printf("Case #%d\n",c);
        cout<<calc(0,0)<<endl;
        print_ans(0,0);
    }
    return 0;
}
