#include<stdio.h>
#define ll long long
#define NO_UP 200000

ll sum[300000],sum_up[2][300000],sqr[300000],sqr_up[2][300000];
ll n,q;
void update_node_sum(int node,int b,int e)
{
    if(sum_up[0][node]!=NO_UP)
    {
        sum[node]=(e-b+1)*sum_up[0][node];
        if(b!=e)
        {
            sum_up[1][node*2]=sum_up[1][node*2+1]=0;
            sum_up[0][node*2]=sum_up[0][node*2+1]=sum_up[0][node];
        }
        sum_up[0][node]=NO_UP;
    }
    if(sum_up[1][node])
    {
        sum[node]+=(e-b+1)*sum_up[1][node];
        if(b!=e)
        {
            sum_up[1][node*2]+=sum_up[1][node];
            sum_up[1][node*2+1]+=sum_up[1][node];
        }
        sum_up[1][node]=0;
    }
}
ll sum_updt(int typ,int node,int b,int e,int i,int j,int x)
{
    update_node_sum(node,b,e);
    if(e<i || b>j) return sum[node];
    if(b>=i && e<=j)
    {
        if(typ==0)
        {
            sum[node]=(e-b+1)*x;
            if(b!=e)
            {
                sum_up[0][node*2]=sum_up[0][node*2+1]=x;
                sum_up[1][node*2]=sum_up[1][node*2+1]=0;
            }
            return sum[node];
        }
        else
        {
            sum[node]+=(e-b+1)*x;
            if(b!=e)
            {
                sum_up[1][node*2]+=x;
                sum_up[1][node*2+1]+=x;
            }
            return sum[node];
        }
    }
    ll l,r;
    l=sum_updt(typ,node*2,b,(b+e)/2,i,j,x);
    r=sum_updt(typ,node*2+1,(b+e)/2+1,e,i,j,x);
    return sum[node]=l+r;
}

ll sum_read(int node,int b,int e,int i,int j)
{
    update_node_sum(node,b,e);
    if(e<i || b>j) return 0;
    if(b>=i && e<=j) return sum[node];
    ll l,r;
    l=sum_read(node*2,b,(b+e)/2,i,j);
    r=sum_read(node*2+1,(b+e)/2+1,e,i,j);
    return l+r;
}
void update_node_sqr(int node,int b,int e)
{
    if(sqr_up[0][node]!=NO_UP)
    {
        sqr[node]=(e-b+1)*sqr_up[0][node]*sqr_up[0][node];
        if(b!=e)
        {
            sqr_up[1][node*2]=sqr_up[1][node*2+1]=0;
            sqr_up[0][node*2]=sqr_up[0][node*2+1]=sqr_up[0][node];
        }
        sqr_up[0][node]=NO_UP;
    }
    if(sqr_up[1][node])
    {
        sqr[node]+=(e-b+1)*sqr_up[1][node]*sqr_up[1][node]+2*sum_read(1,1,n,b,e)*sqr_up[1][node];
        if(b!=e)
        {
            sqr_up[1][node*2]+=sqr_up[1][node];
            sqr_up[1][node*2+1]+=sqr_up[1][node];
        }
        sqr_up[1][node]=0;
    }
}

ll sqr_updt(int typ,int node,int b,int e,int i,int j,int x)
{
    update_node_sqr(node,b,e);
    if(e<i || b>j) return sqr[node];
    if(b>=i && e<=j)
    {
        if(typ==0)
        {
            sqr[node]=(e-b+1)*x*x;
            if(b!=e)
            {
                sqr_up[0][node*2]=sqr_up[0][node*2+1]=x;
                sqr_up[1][node*2]=sqr_up[1][node*2+1]=0;
            }
            //sum_updt(typ,node,b,e,i,j,x);
            return sqr[node];
        }
        else
        {
            sqr[node]+=(e-b+1)*x*x+2*sum_read(1,1,n,b,e)*x;
            if(b!=e)
            {
                sqr_up[1][node*2]+=x;
                sqr_up[1][node*2+1]+=x;
            }
            //sum_updt(typ,node,b,e,i,j,x);
            return sqr[node];
        }
    }
    ll l,r;
    l=sqr_updt(typ,node*2,b,(b+e)/2,i,j,x);
    r=sqr_updt(typ,node*2+1,(b+e)/2+1,e,i,j,x);
    //sum_updt(typ,node,b,e,i,j,x);
    return sqr[node]=l+r;
}

ll sqr_read(int node,int b,int e,int i,int j)
{
    update_node_sqr(node,b,e);
    if(e<i || b>j) return 0;
    if(b>=i && e<=j) return sqr[node];
    ll l,r;
    l=sqr_read(node*2,b,(b+e)/2,i,j);
    r=sqr_read(node*2+1,(b+e)/2+1,e,i,j);
    return l+r;
}

int main()
{
    ll i,j,k,t,a,b,c,cc;
    scanf("%lld",&t);
    for(cc=1;cc<=t;cc++)
    {
        scanf("%lld %lld",&n,&q);
        for(i=1;i<300000;i++)
        {
            sum[i]=sqr[i]=0;
            sum_up[0][i]=sqr_up[0][i]=NO_UP;
            sum_up[1][i]=sqr_up[1][i]=0;
        }
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&j);
            sqr_updt(0,1,1,n,i,i,j);
            sum_updt(0,1,1,n,i,i,j);
        }
        printf("Case %lld:\n",cc);
        while(q--)
        {
            scanf("%lld",&j);
            if(j==2)
            {
                scanf("%lld %lld",&a,&b);
                printf("%lld\n",sqr_read(1,1,n,a,b));
            }
            else
            {
                scanf("%lld %lld %lld",&a,&b,&c);
                sqr_updt(j,1,1,n,a,b,c);
                sum_updt(j,1,1,n,a,b,c);
            }
        }
    }
    return 0;
}
