#include<stdio.h>
#include<string.h>
#define ll long long

ll mx[2005],dp[2005][2005];
ll acr[2005][2005];

ll max(ll a,ll b){return a>b?a:b;}
int main()
{
    ll t,h,f,i,j,k,a,c;
    scanf("%lld",&c);
    while(c--)
    {
        scanf("%lld %lld %lld",&t,&h,&f);
        memset(acr,0,sizeof(acr));
        for(i=1;i<=t;i++)
        {
            scanf("%lld",&a);
            while(a--)
            {
                scanf("%lld",&j);
                acr[i][j]++;
            }
        }
        mx[h]=-1;
        for(i=1;i<=t;i++)
        {
            dp[i][h]=acr[i][h];
            mx[h]=max(mx[h],dp[i][h]);
        }
        for(i=h-1;i>=0;i--)
        {
            mx[i]=-1;
            for(j=1;j<=t;j++)
            {
                dp[j][i]=dp[j][i+1]+acr[j][i];
                if(i+f<=h) dp[j][i]=max(dp[j][i],mx[i+f]+acr[j][i]);
                mx[i]=max(mx[i],dp[j][i]);
            }
        }
        printf("%lld\n",mx[0]);
    }
    return 0;
}
