#include<iostream>
#include<cstring>
#define ll long 
using namespace std;
ll mod(ll a,ll b)
{
    return (a%b+b)%b;
}
int main()
{
    ll t,n,k,i,j,x;
    cin>>t;
    ll dp[2][105],*cur,*prev,*tmp;
    while(t--)
    {
        cin>>n>>k;
        prev=dp[0];
        cur=dp[1];
        memset(dp,0,sizeof(dp));
        prev[0]=1;
        for(i=0;i<n;i++)
        {
            cin>>x;
            ll m1=mod(x,k),m2=mod(-x,k);
            for(j=0;j<k;j++)
            {
                //if(prev[k+j-m1]) cur[j]=1;
                if(prev[mod(j-m1,k)]) cur[j]=1;
                else if(i!=0)
                    if(prev[mod(j-m2,k)]) cur[j]=1;
					else cur[j]=0;
				else cur[j]=0;
            }
            tmp=cur;
            cur=prev;
            prev=tmp;
        }
        if(prev[0]==1) cout<<"Divisible\n";
        else cout<<"Not divisible\n";
    }
    return 0;
}
