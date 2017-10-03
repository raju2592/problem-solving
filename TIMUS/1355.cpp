#include<iostream>
#include<vector>
#include<cmath>
#define MAX 100005
#define ll int
using namespace std;

ll np[100005];
vector<ll> pr;

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
    int i,k,j,t,a,b,ans;
    cin>>t;
    sieve();
    while(t--)
    {
        cin>>a>>b;
        if(b%a) cout<<0<<endl;
        else
        {
            if(b==a) cout<<1<<endl;
            else
            {
                ans=1;
                b/=a;
                k=sqrt(b);
                for(i=0;i<pr.size() && pr[i]<=k;i++)
                {
                    while(b%pr[i]==0)
                    {
                        ans++;
                        b/=pr[i];
                    }
                    k=sqrt(b);
                }
                if(b>1) ans++;
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}
