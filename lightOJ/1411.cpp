#include<stdio.h>
#include<string.h>
#define MAX 250000
//using namespace std;
#define ll long long
ll val[850000],lazy_a[850000],lazy_b[850000],lazy_c[850000],d_a[850000],d_b[850000];
void update(ll node,ll b,ll e)
{
    ll n=e-b+1;
    if(lazy_c[node]!=1000006)
    {
        val[node]=n*lazy_c[node];
        if(e!=b)
        {
            lazy_c[node*2]=lazy_c[node];
            lazy_c[node*2+1]=lazy_c[node];
            lazy_a[node*2]=0;
            lazy_a[node*2+1]=0;
            lazy_b[node*2]=0;
            lazy_b[node*2+1]=0;
            d_a[node*2]=d_a[node*2+1]=d_b[node*2]=d_b[node*2+1]=0;
        }
        lazy_c[node]=1000006;
    }
    if(lazy_a[node])
    {
        val[node]+=(n*(2*lazy_a[node]+(n-1)*d_a[node]))/2;
        if(e!=b)
        {
            lazy_a[node*2]+=lazy_a[node];
            d_a[node*2]+=d_a[node];
            lazy_a[node*2+1]+=((b+e)/2+1-b)*d_a[node]+lazy_a[node];
            d_a[node*2+1]+=d_a[node];
        }
        lazy_a[node]=0;
        d_a[node]=0;
    }
    if(lazy_b[node])
    {
        val[node]+=(n*(2*lazy_b[node]+(n-1)*d_b[node]))/2;
        if(e!=b)
        {
            lazy_b[node*2+1]+=lazy_b[node];
            d_b[node*2]+=d_b[node];
            lazy_b[node*2]+=(e-(b+e)/2)*d_b[node]+lazy_b[node];
            d_b[node*2+1]+=d_b[node];
        }
        lazy_b[node]=0;
        d_b[node]=0;

    }
}
ll updt_ab(ll node,ll b,ll e,ll i,ll j,ll t)
{
    ll n=e-b+1;
    update(node,b,e);
    if(e<i || b>j) return val[node];
    if(b>=i && e<=j)
    {
        ll k;
        if(t==0) k=b-i+1;
        else k=j-e+1;
        val[node]+=(n*(2*k+n-1))/2;
        if(b!=e)
        {
            if(t==0) //update a
            {
                lazy_a[node*2]+=k;
                lazy_a[node*2+1]+=(b+e)/2+1-b+k;
                d_a[node*2]++;
                d_a[node*2+1]++;
            }
            else
            {
                lazy_b[node*2+1]+=k;
                lazy_b[node*2]+=e-(b+e)/2+k;
                d_b[node*2]++;
                d_b[node*2+1]++;
            }
        }
        return val[node];
    }
    ll l,r;
    l=updt_ab(node*2,b,(b+e)/2,i,j,t);
    r=updt_ab(node*2+1,(b+e)/2+1,e,i,j,t);
    return val[node]=l+r;
}
ll updt_c(ll node,ll b,ll e,ll i,ll j,ll v)
{
    ll n=e-b+1;
    update(node,b,e);
    if(e<i || b>j)
    {
        return val[node];
    }
    if(b>=i && e<=j)
    {
        lazy_c[node]=1000006;
        val[node]=v*(e-b+1);
        if(e!=b)
        {
            lazy_c[node*2]=v;
            lazy_c[node*2+1]=v;
            lazy_a[node*2]=lazy_a[node*2+1]=lazy_b[node*2]=lazy_b[node*2+1]=0;
            d_a[node*2]=d_a[node*2+1]=d_b[node*2]=d_b[node*2+1]=0;
        }
        return val[node];
    }
    ll l,r;
    l=updt_c(node*2,b,(b+e)/2,i,j,v);
    r=updt_c(node*2+1,(b+e)/2+1,e,i,j,v);
    return val[node]=l+r;
}
ll read(ll node,ll b,ll e,ll i,ll j)
{
    update(node,b,e);
    if(e<i || b>j) return 0;
    if(b>=i && e<=j) return val[node];
    ll l,r;
    l=read(node*2,b,(b+e)/2,i,j);
    r=read(node*2+1,(b+e)/2+1,e,i,j);
    return l+r;
}
int main()
{
    ll t,i,j,k,n;
    char cc;
    scanf("%lld",&t);
    for(ll c=1;c<=t;c++)
    {
        scanf("%lld",&n);
		getchar();
        printf("Case %lld:\n",c);
        /*memset(val,0,sizeof(val));
        memset(lazy_a,0,sizeof(lazy_a));
        memset(lazy_b,0,sizeof(lazy_b));
        memset(lazy_c,-1,sizeof(lazy_c));*/
        for(i=0;i<650000;i++)
        {
            lazy_a[i]=lazy_b[i]=d_a[i]=d_b[i]=val[i]=0;
            lazy_c[i]=1000006;
        }
        while(n--)
        {
            scanf("%c",&cc);
            if(cc=='A')
            {
                scanf("%lld %lld",&j,&k);
				getchar();
                updt_ab(1,1,MAX,j,k,0);
            }
            else if(cc=='B')
            {
                scanf("%lld %lld",&j,&k);
				getchar();
                updt_ab(1,1,MAX,j,k,1);
            }
            else if(cc=='C')
            {
                scanf("%lld %lld %lld",&i,&j,&k);
				getchar();
                updt_c(1,1,MAX,i,j,k);
            }
            else if(cc=='S')
            {
                scanf("%lld %lld",&j,&k);
				getchar();
                printf("%lld\n",read(1,1,MAX,j,k));
            }
        }
    }
    return 0;
}
