#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#define MAX 65
#define ll unsigned long long
using namespace std;

int p[69];
vector<ll> out;
map<ll,int> v;
void sieve()
{
    int i,j,k;
    k=sqrt(MAX);
    for(i=2;i<=MAX;i++) p[i]=1;
    for(i=2;i<=k;i++)
    {
        if(p[i])
        {
            for(j=i;i*j<=MAX;j++) p[i*j]=0;
        }
    }
}
int main()
{
    ll i,j,k;
    ll mx= -1LL,pw;
    //cout<<mx<<endl;
    sieve();
    out.push_back(1);
    for(i=2;i<=100000;i++)
    {
        pw=i;
        for(j=2;j<64;j++)
        {
            if(mx/pw>=i) pw*=i;
            else break;
            if(p[j]) continue;
            if(!v[pw])
            {
                out.push_back(pw);
                v[pw]=1;
            }
        }
    }
    sort(out.begin(),out.end());
    for(i=0;i<out.size();i++)  printf("%llu\n",out[i]);
    return 0;
}
