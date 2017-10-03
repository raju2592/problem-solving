#include<cstdio>
#include<cmath>
#include<iostream>
#define ll long long
using namespace std;

ll mmabs(ll a){return a>0?a:-a;}
int main()
{
    ll t,cs=1,x,y,n,val1,val2;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        val1=val2=sqrt(n);
        if(n%2 && !(val1%2) ) val1--,val2++;
        else if(!(n%2) && val1%2) val1--,val2++;
        //cout<<val1<<val2;
        x=mmabs((n-val1*val1)/2);
        y=mmabs((val2*val2-n)/2);
        //cout<<x<<y;
        printf("Case %lld: %lld\n",cs++,x<y?x:y);
    }
    return 0;
}
