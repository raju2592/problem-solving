#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<stack>
#define ll long long
#define pb push_back
#define MAX 1000003
using namespace std;

ll a,b;
ll np[1000005];
vector<ll> pr;
map<ll,ll> v;
vector<ll> fact;
vector<ll> nums;
void sieve()
{
    ll i,j,k;
    k=sqrt(MAX);
    for(i=2;i<=k;i++)
    {
        if(!np[i])
        {
            pr.push_back(i);
            for(j=i;i*j<=MAX;j++) np[i*j]=1;
        }
    }
    for(;i<=MAX;i++) if(!np[i]) pr.push_back(i);
}

int main()
{
    ll t,c,i,j,k,x,ans;
    sieve();
    //for(int i=0;i<50;i++) printf("%d ",pr[i]);
    scanf("%lld",&t);
    for(c=1;c<=t;c++)
    {
        scanf("%lld %lld",&a,&b);
        v.clear();
        fact.clear();
        nums.clear();
        k=sqrt(a);
        x=a;
        for(i=0;i<pr.size() && pr[i]<=k;i++)
        {
            if(x%pr[i]==0) fact.push_back(pr[i]);
            while(x%pr[i]==0) x/=pr[i];
            k=sqrt(x);
        }
        if(x>1) fact.push_back(x);
        nums.push_back(a);
        v[a]=1;
        i=0;
        ans=0;
        if(b==1) ans++;
        while(i!=nums.size())
        {

            for(j=0;j<fact.size();j++)
            {
                //cout<<nums[i]/fact[j]<<" "<<v[nums[i]/fact[j]]<<endl;
                if(nums[i]%fact[j]==0 && nums[i]/fact[j]>=b && v[nums[i]/fact[j]]==0)
                {
                    if(nums[i]/fact[j]<=a/b) ans++;
                    nums.push_back(nums[i]/fact[j]);
                    v[nums[i]/fact[j]]=1;

                }
            }
            i++;
        }
        printf("Case %lld: %lld\n",c,ans/2);
    }
    return 0;
}
