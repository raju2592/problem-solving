#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<utility>
#define ll int
#define ull unsigned ll
#define pb push_back
#define mp make_pair
#define INF 20000000
using namespace std;

ll Min(ll i,ll j){return i<j?i:j;}
ll Max(ll i,ll j){return i>j?i:j;}
ll dp[1005];
ll pal[1005][1005];
int main()
{
    ll a,b,c,t,d,e,i,j,k,l,m,n;
    //cin>>t;
    scanf("%d\n",&t);
    c=1;
    //getchar();
    char s[100005];
    while(c<=t)
    {
        //cin>>s;
        /*dp[s.size-1]=1;
        dp[s.size]=0;*/
        /*for(i=s.size()-2;i>=0;i--)
        {
            for(j=)
        }*/
        gets(s);
		//scanf("%s\n",s);
        l=strlen(s);
        for(i=1;i<l;i++)
        {
            pal[i][i]=1;
            pal[i][i-1]=1;
        }
        pal[0][0]=1;
        for(i=2;i<=l;i++)
        {
            for(j=0;j<=l-i;j++)
            {
                if(s[j]==s[j+i-1] && pal[j+1][j+i-2]) pal[j][j+i-1]=1;
                else pal[j][j+i-1]=0;
            }
        }
        dp[l-1]=1;
        dp[l]=0;
        for(i=l-2;i>=0;i--)
        {
            dp[i]=INF;
            for(j=i;j<l;j++)
            {
                if(pal[i][j]) dp[i]=Min(dp[i],1+dp[j+1]);
            }
        }
        //cout<<dp[0]<<endl;
        printf("Case %d: %d\n",c,dp[0]);
		c++;
    }
    return 0;
}
