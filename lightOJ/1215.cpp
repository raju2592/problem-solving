#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#define MAX 1000000
#define Int long long
using namespace std;
int max(int i,int j){return i>j?i:j;}
Int p[1000005];
vector<Int> pr;

void sieve()
{
    Int i,j,k;
    for(i=1;i<=MAX;i++) p[i]=1;
    k=sqrt(MAX);
    for(i=2;i<=k;i++)
    {
        if(p[i])
        {
            pr.push_back(i);
            for(j=i;i*j<=MAX;j++) p[i*j]=0;
        }
    }
    for(;i<=MAX;i++) if(p[i]) pr.push_back(i);
}

Int gcd(Int a,Int b)
{
    if(a%b==0) return b;
    return gcd(b,a%b);
}
Int lcm(Int a,Int b)
{
    return a/gcd(a,b)*b;
}
int main()
{
    Int t,i,j,k,a,b,L,val,cnt,ans;
    sieve();
    cin>>t;
    for(Int c=1;c<=t;c++)
    {
        cin>>a>>b>>L;
        if(L%lcm(a,b))
        {
            printf("Case %lld: impossible\n",c);
            continue;
        }
        ans=1;
        for(i=0;i<pr.size();i++)
        {
            cnt=0;
            val=1;
            while(L%pr[i]==0)
            {
                cnt++;
                L/=pr[i];
                val*=pr[i];
            }
            j=k=0;
            while(a%pr[i]==0)
            {
                j++;
                a/=pr[i];
            }
            while(b%pr[i]==0)
            {
                k++;
                b/=pr[i];
            }
            if(cnt>max(j,k)) ans*=val;
        }
        if(L>1 && a%L && b%L) ans*=L;
        printf("Case %lld: %lld\n",c,ans);
    }
    return 0;
}
