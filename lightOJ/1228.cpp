#include<stdio.h>
#include<string.h>
#define ll long long

ll n,k,q,r;
ll dp[1<<12][20][20];
ll enm[15][15];

ll min(ll a,ll b){return a<b?a:b;}


int main()
{
    ll t,cs=1,i,j,p,a,b,tot;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld %lld",&n,&k,&q);
        memset(enm,0,sizeof(enm));
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&j);
            while(j--)
            {
                scanf("%lld",&p);
                enm[i-1][p-1]=1;
            }
        }
        memset(dp,-1,sizeof(dp));
        printf("Case %lld:\n",cs++);
        for(i=0;i<n+1;i++)
        {
            for(j=0;j<n;j++) dp[(1<<n)-1][i][j]=1;
        }
        for(i=(1<<n)-2;i>=0;i--)
        {
            for(j=0;j<n+1;j++)
            {
                for(a=0;a<n;a++)
                {
                    dp[i][j][a]=0;
                    for(b=0;b<n;b++)
                    {
                        if((i & (1<<b))==0)
                        {
                            if(enm[b][j] && a) dp[i][j][a]+=dp[i | (1<<b)][b][a-1];
                            else if(!enm[b][j]) dp[i][j][a]+=dp[i | (1<<b)][b][a];
                        }
                    }
                }
            }
        }
        while(q--)
        {
            scanf("%lld",&r);
            if(!k) p=n-1;
            else p=min(n-1,r/k);
            printf("%lld\n",dp[0][n][p]);
        }
    }
    return 0;
}
