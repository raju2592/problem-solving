#include<iostream>
#include<vector>
using namespace std;
#define ll long long
vector<ll> tr,upd,times;

//ll tr[100],upd[100],times[100];
void upd_node(ll node,ll b,ll e)
{
    ll k=(e-b+1),p;
    tr[node]+=(k*(2*upd[node]+(k-1)*times[node]))/2;
    if(b!=e)
    {
        upd[node*2]+=upd[node];
        times[node*2]+=times[node];
        p=(b+e)/2+1-b+1;
        upd[node*2+1]+=upd[node]+(p-1)*times[node];
        times[node*2+1]+=times[node];
    }
    upd[node]=times[node]=0;
}
ll update(ll node,ll b,ll e,ll i,ll j)
{
    ll k=e-b+1,p,v;
    upd_node(node,b,e);
    if(j<b || i>e) return tr[node];
    if(b>=i && e<=j)
    {
        v=1+(b-i);
        tr[node]+=(k*(2*v+(k-1)))/2;
        if(b!=e)
        {
            upd[node*2]+=v;
            times[node*2]++;
            p=(b+e)/2+1-i+1;
            upd[node*2+1]+=1+(p-1);
            times[node*2+1]++;
        }
        return tr[node];
    }
    ll l,r;
    l=update(node*2,b,(b+e)/2,i,j);
    r=update(node*2+1,(b+e)/2+1,e,i,j);
    return tr[node]=l+r;
}
ll read(ll node,ll b,ll e,ll i,ll j)
{
    upd_node(node,b,e);
    if(j<b || i>e) return 0;
    if(b>=i && e<=j) return tr[node];
    ll l,r;
    l=read(node*2,b,(b+e)/2,i,j);
    r=read(node*2+1,(b+e)/2+1,e,i,j);
    return l+r;
}
int main()
{
    ll n,i,j,k,q,t,a,b;
    cin>>n>>q;
    tr.resize(4*n,0);
    upd.resize(4*n,0);
    times.resize(4*n,0);
    while(q--)
    {
        cin>>t>>a>>b;
        if(t==0) update(1,1,n,a,b);
        else cout<<read(1,1,n,a,b)<<"\n";
    }
}
