#include<stdio.h>
#define ll long long
#define MAX 2000000000
struct quad
{
    ll sum;
    ll fb; //from begining
    ll fe; //from end
    ll val;
};

ll n,m;
ll arr[50005];
quad tree[210000];

ll Max(ll i,ll j){return i>j?i:j;}

quad build(ll node,ll b,ll e)
{
    if(b==e)
    {
        tree[node].sum=tree[node].fb=tree[node].fe=tree[node].val=arr[b];
        return tree[node];
    }
    quad p=build(node*2,b,(b+e)/2);
    quad q=build(node*2+1,(b+e)/2+1,e);
    tree[node].sum=p.sum+q.sum;
    tree[node].fb=Max(p.fb,p.sum+q.fb);
    tree[node].fe=Max(q.fe,q.sum+p.fe);
    tree[node].val=Max(Max(p.val,q.val),p.fe+q.fb);
    return tree[node];
}

quad find(ll node,ll b,ll e,ll i,ll j)
{
    quad ret,p,q;
    ret.sum=ret.fb=ret.fe=ret.val=MAX;
    if(b>j || e<i) return ret;
    if(b>=i && e<=j)
    {
        ret.sum=tree[node].sum;
        ret.val=tree[node].val;
        ret.fb=tree[node].fb;
        ret.fe=tree[node].fe;
        return ret;
    }
    p=find(node*2,b,(b+e)/2,i,j);
    q=find(node*2+1,(b+e)/2+1,e,i,j);
    if(p.sum==MAX)
    {
        ret.sum=q.sum;
        ret.val=q.val;
        ret.fb=MAX;
        ret.fe=q.fe;
    }
    else if(q.sum==MAX)
    {
        ret.sum=p.sum;
        ret.val=p.val;
        ret.fe=MAX;
        ret.fb=p.fb;
    }
    else
    {
        ret.sum=p.sum+q.sum;
        ret.val=Max(Max(p.val,q.val),p.fe+q.fb);
        if(p.fb==MAX) ret.fb=MAX;
        else ret.fb=Max(p.fb,p.sum+q.fb);
        if(q.fe==MAX) ret.fe=MAX;
        else ret.fe=Max(q.fe,q.sum+p.fe);
    }
    return ret;
}

ll read(ll i,ll j)
{
    quad p=find(1,1,n,i,j);
    return p.val;
}
int main()
{
    ll i,j,k;
    scanf("%lld",&n);
    for(i=1;i<=n;i++) scanf("%lld",&arr[i]);
    build(1,1,n);
    scanf("%lld",&m);
    while(m--)
    {
        scanf("%lld %lld",&j,&k);
        printf("%lld\n",read(j,k));
    }
    return 0;
}
