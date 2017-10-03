#include<cstdio>
#include<cstring>
#include<iostream>
//#include<bits/stdc++.h>
#define ll long long
#define INF 10000000000000LL
using namespace std;

ll n,m;
ll arr[100005];
ll last[20],cnt[20][100005],total[20],exclude[20][20];
ll dp[1<<16];
ll min(ll a,ll b){return a<b?a:b;}
ll calc(ll mask)
{
    if(mask==(1<<m)-1) return 0;
    if(dp[mask]!=-1) return dp[mask];
    ll i,j,k,x;
    ll &ret=dp[mask];
    ret=INF;
    //cout<< mask <<"::::::\n";
    for(i=0;i<m;i++)
    {
        if(0==(mask & (1<<i)))
        {
            x=calc(mask | (1<<i));
            //cout<<i<<" "<<x<<" ";
            if(last[i]==0) k=0;
            else
            {
                k=total[i];
                for(j=0;j<m;j++)
                {
                    if(mask & (1<<j)) k-=exclude[i][j];//k-=cnt[j][last[i]-1];
                }
            }
            //cout<<k<<endl;
            ret=min(ret,x+k);
        }
    }
    return ret;
}

int main()
{
    ll t,cs=1,i,j,k;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&m);
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&arr[i]);
            arr[i]--;
        }
        memset(cnt,0,sizeof(cnt));
        memset(last,0,sizeof(last));
        memset(total,0,sizeof(total));
        memset(exclude,0,sizeof(exclude));
        for(i=0;i<m;i++)
        {
            cnt[i][0]=0;
            ll prev=0;
            for(j=1;j<=n;j++)
            {
                if(arr[j]==i)
                {
                    prev=j;
                    cnt[i][j]=cnt[i][j-1]+1;
                    total[i]+=j-1-cnt[i][j-1];
                }
                else
                {
                    cnt[i][j]=cnt[i][j-1];
                    exclude[arr[j]][i]+=cnt[i][j-1];
                }
            }
            last[i]=prev;
        }
        //for(i=0;i<m;i++) cout<<total[i]<<" ";
        //cout<<endl;
        /*for(i=0;i<m;i++)
        {
                for(j=0;j<m;j++) cout<<exclude[i][j]<<" ";
                cout<<endl;
        }*/
        memset(dp,-1,sizeof(dp));
        printf("Case %lld: %lld\n",cs++,calc(0));
    }
    return 0;
}
