#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<utility>
#include<sstream>
#include<fstream>
#define ll long long
#define ull unsigned ll
#define pb push_back
#define mkp make_pair
using namespace std;

ll Min(ll i,ll j){return i<j?i:j;}
ll Max(ll i,ll j){return i>j?i:j;}
ll BigMod(ll B,ll P,ll M){ll R=1; while(P>0){if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return (ll)R;} /// (B^P)%M

int main()
{
    ll a,b,c,d,e,i,j,k,l,m,n,dp[100000];
    while(cin>>n>>k)
    {
        dp[0]=1;
        dp[1]=k-1;
        for(i=2;i<=n;i++) 
		{
			dp[i]=(k-1)*(dp[i-1]+dp[i-2]);
		}
        cout<<dp[n]<<endl;
    }
    return 0;
}
