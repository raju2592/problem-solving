#include<iostream>
#include<cstring>
#define ll long long
using namespace std;

ll dp[4][4][100006];
ll n;

ll calc(ll a,ll b,ll len)
{
    if(a>=4 || b>=4) return 0;
    ll &ret=dp[a][b][len];
    if(ret!=-1) return ret;
    if(len==0) return 1;
    ret=0;
    if(a+1<4)
    {
        int x=a+1,y=b-1>0?b-1:0;
        ret+=calc(x,y,len-1);
    }
    if(b+1<4)
    {
        int y=b+1,x=a-1>0?a-1:0;
        ret+=calc(x,y,len-1);
    }
    return ret;
}

int main()
{
    ll i,j,k,l;
    while(cin>>n)
    {
        k=0,l=0;
        memset(dp,-1,sizeof(dp));
        while(k<n)
        {
            n-=k;
            l++;
            k=calc(0,0,l);
            //cout<<k<<endl;
        }
        //cout<<l<<endl;
        ll a=0,b=0;
        while(l)
        {
            //cout<<a<<" "<<b<<" ";
            int x=a+1,y=b-1>0?b-1:0;
            k=calc(x,y,l-1);
            if(k>=n)
            {
                a=x;
                b=y;
                cout<<'a';

            }
            else
            {
                n-=k;
                int y=b+1,x=a-1>0?a-1:0;
                a=x;
                b=y;
                cout<<'b';
            }
            l--;
            //cout<<endl;
        }
        cout<<endl<<endl;
    }
}
