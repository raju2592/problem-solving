#include<iostream>
#define ll long long
using namespace std;

ll val[2500000];
ll add[2500000];
ll updt(ll node,ll b,ll e,ll i,ll j,ll v)
{
    if(e<i || b>j) return 0;
    if(b>=i && e<=j)
    {
        val[node]+=(e-b+1)*v;
        add[node*2]+=v;
        add[node*2+1]+=v;
        return (e-b+1)*v;
    }
    ll u1=updt(node*2,b,(b+e)/2,i,j,v);
    ll u2=updt(node*2+1,(b+e)/2+1,e,i,j,v);
    val[node]+=u1+u2;
    return u1+u2;

}
ll read(ll node,ll b,ll e,ll i,ll j)
{
    val[node]+=(e-b+1)*add[node];
    add[node*2]+=add[node];
    add[node*2+1]+=add[node];
    add[node]=0;
    if(e<i || b>j) return -1;
    if(b>=i && e<=j)
    {
        return val[node];
    }
    //return read(node*2,b,(b+e)/2,i,j)+read(node*2+1,(b+e)/2+1,e,i,j)+(j-i+1)*add[node];
	ll p1=read(node*2,b,(b+e)/2,i,j);
	ll p2=read(node*2+1,(b+e)/2+1,e,i,j);
	if(p1==-1) return p2;
	else if(p2==-1) return p1;
	//else return read(node*2,b,(b+e)/2,i,j)+read(node*2+1,(b+e)/2+1,e,i,j)+(j-i+1)*add[node];
	else return p1+p2;
}
int main()
{
    ll n,i,t,p,q,v,c,j,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>c;
        for(i=0;i<2500000;i++)
		{
			val[i]=0;
            add[i]=0;
		}
        while(c--)
        {
            cin>>k;
            if(k==0)
            {
                cin>>p>>q>>v;
                updt(1,1,n,p,q,v);
            }
            else
            {
                cin>>p>>q;
                cout<<read(1,1,n,p,q)<<endl;
            }
        }
    }
    return 0;
}
