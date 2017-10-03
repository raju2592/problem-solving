#include<iostream>
#define ll long long
using namespace std;

void Extended_Euclid(ll a,ll b,ll &d,ll &x,ll &y)
{
    ll x1,y1;
    if(b==0)
    {
        d=a;
        x=1;
        y=0;
        return;
    }
    Extended_Euclid(b,a%b,d,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return;

}
ll MOD(ll a,ll b)
{
    return (a%b+b)%b;
}
int main()
{
    ll i,j,k,m,n,b,t,d,d1,x,y,arr[200],sol[200];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;i++) cin>>arr[i];
        cin>>b>>m;
        arr[n+1]=m;
        Extended_Euclid(arr[1],arr[2],d,x,y);
        sol[1]=MOD(x,m);
        sol[2]=MOD(y,m);
        for(i=3;i<=n+1;i++)
        {
            Extended_Euclid(d,arr[i],d1,x,y);
            for(j=1;j<i;j++) sol[j]=MOD(sol[j]*x,m);
            sol[i]=y;
            d=d1;
        }
        if(b%d) cout<<"NO\n";
        else
        {
            for(i=1;i<=n;i++) cout<<MOD(sol[i]*(b/d),m)<<' ';
            cout<<"\n";
        }
    }
    return 0;
}
