#include<cstdio>
#include<cmath>
#include<vector>
#include<map>
#include<iostream>
#include<utility>
using namespace std;
int prime[500];
vector<int> p;
vector<int> fact;
void sieve()
{
    int i,j,k,max=125;
    for(i=0;i<125;i++) prime[i]=1;
    k=(int) ceil(sqrt(125));
    for(i=2;i<=k;i++)
    {
        if(prime[i])
        {
            p.push_back(i);
            for(j=i;i*j<=max;j++) prime[i*j]=0;
        }
    }
    for(;i<=max;i++) if(prime[i]) p.push_back(i);
}
int main()
{
    int c,t,i,j,k,n,m;
    scanf("%d",&t);
    sieve();
    for(c=1;c<=t;c++)
    {
        scanf("%d",&n);
        fact.clear();
        fact.resize(p.size());
        for(i=0;i<fact.size();i++) fact[i]=0;
        for(i=2;i<=n;i++)
        {
            m=i;
            for(j=0;j<p.size();j++)
            {
                while(m%p[j]==0)
                {
                    fact[j]++;
                    m/=p[j];
                }
            }
        }
        printf("Case %d: %d = ",c,n);
        for(i=0;i<p.size();i++)
        {
            if(fact[i]!=0)
            {
                printf("%d (%d)",p[i],fact[i]);
                break;
            }
        }
        for(++i;i<p.size();i++)
        {
            if(fact[i]!=0)
            {
                printf(" * %d (%d)",p[i],fact[i]);
            }
        }
        puts("");
    }
    return 0;
}
