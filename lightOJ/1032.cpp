#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;
vector<ll> bits;
ll find_bit(ll n)
{
    while(n)
    {
        bits.push_back(n%2);
        n/=2;
    }
    reverse(bits.begin(),bits.end());
    return bits.size();
}
int main()
{
    ll t,i,j,k,n,l,c,ans,endone;
    ll dp[40];
    cin>>t;
    for(c=1;c<=t;c++)
    {
        cin>>n;
        bits.clear();
        l=find_bit(n);
        dp[0]=dp[1]=0;
        ans=0;
        endone=1;
        for(i=2;i<l;i++)
        {
            dp[i]=2*dp[i-1]+endone; // endone contains how many number of length i-1 contain 1 at end;
            if(i>2) endone*=2;
            ans+=dp[i];
        }
        ll prev=1;
        ll p_ans=0,tmp;
        for(i=1;i<l;i++)
        {
            if(bits[i]==1)
            {
                k=l-i-1;
                for(j=0;j<=k;j++) ans+=dp[j];
                ans+=(ll) pow(2,k)*p_ans;
                if(prev==1)
                {
                    ans++;
                    p_ans++;
                }
            }
            prev=bits[i];
        }
        printf("Case %lld: %lld\n",c,ans);
    }
    return 0;
}
