#include<cstdio>
#include<vector>
#include<cmath>
#define ll long long
#define MAX 10000000
using namespace std;

int p[1000005];
vector<int> pr;
//int sd[1000005];

void sieve()
{
    int i,j,k,x,y;
    k=sqrt(MAX);
    for(i=2;i<=k;i++)
    {
        x=i/32;
        y=i%32;
        if(!(p[x]&(1<<y)))
        {
            //sd[i]=i;
            pr.push_back(i);
            for(j=i;i*j<=MAX;j++)
            {
                x=(i*j)/32;
                y=(i*j)%32;
                //p[i*j]=0;
                p[x]|=(1<<y);
                //sd[i*j]=i;
                //if(i*j<1000001 && !sd[i*j]) sd[i*j]=i;
            }
        }
    }
    for(;i<=MAX;i++)
    {
        x=i/32;
        y=i%32;
        if(!(p[x]&(1<<y))) pr.push_back(i);
    }
}

int main()
{
    ll i,j,k,t,n,ans,rt;
    scanf("%lld",&t);
    sieve();
    //for(i=0;i<50;i++) printf("%d ",pr[i]);
    for(ll c=1;c<=t;c++)
    {
        scanf("%lld",&n);
        ans=1;
        rt=sqrt(n);
        for(i=0;i<pr.size() && pr[i]<=rt;i++)
        {
            k=0;
            while(n%pr[i]==0)
            {
                k++;
                n/=pr[i];
            }
            ans*=2*k+1;
            rt=sqrt(n);
            //if(n<=1000000) break;
        }
        if(n>1) ans*=3;
        printf("Case %lld: %lld\n",c,++ans/2);
    }
    return 0;
}
