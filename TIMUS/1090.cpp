#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
ll bit[10005],n,k;

void updt(ll id,ll up)
{
    while(id<=n)
    {
        bit[id]+=up;
        id+=id&-id;
    }
}
ll read(ll id)
{
    ll sum=0;
    while(id>0)
    {
        sum+=bit[id];
        id-=id&-id;
    }
    return sum;
}

int main()
{
    ll i,j,k,m,l=-1,tmp,ans=0;
    cin>>n>>k;
    for(i=1;i<=k;i++)
    {
        memset(bit,0,sizeof(bit));
        tmp=0;
        for(j=1;j<=n;j++)
        {
            cin>>m;
            updt(m,1);
            tmp+=read(n)-read(m);
        }
        //ans=max(ans,tmp);
        if(tmp>l)
        {
            l=tmp;
            ans=i;
        }
    }
    cout<<ans;
    return 0;
}
