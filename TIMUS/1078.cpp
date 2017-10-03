#include<iostream>
#include<algorithm>
using namespace std;

struct trip
{
    int no,b,e;
};

int dp[505][505],ch[505][505],n;
trip arr[600];

bool cmp(trip a,trip x)
{
    return (a.e-a.b)>(x.e-x.b);
}

void print(int prev,int st)
{
    if(st==n+1) return;
    if(ch[prev][st]==0) print(prev,st+1);
    else
    {
        print(st,st+1);
        cout<<arr[st].no<<" ";
    }
}
int main()
{
    int i,j,k;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i].b>>arr[i].e;
        arr[i].no=i;
    }
    arr[0].b=-2000000;
    arr[0].e=2000000;
    sort(arr+1,arr+n+1,cmp);
    for(i=0;i<=n;i++) dp[i][n+1]=0;
    for(i=n;i>=1;i--)
    {
        for(j=0;j<n;j++)
        {
            dp[j][i]=dp[j][i+1];
            ch[j][i]=0;
            if(arr[i].b>arr[j].b && arr[i].e<arr[j].e)
            {
                //dp[j][i]=max(dp[j][i],1+dp[i][i+1]);
                if(1+dp[i][i+1]>dp[j][i])
                {
                    dp[j][i]=1+dp[i][i+1];
                    ch[j][i]=1;
                }
            }
        }
    }
    cout<<dp[0][1]<<endl;
    print(0,1);
    return 0;
}
