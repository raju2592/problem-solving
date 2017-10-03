#include<stdio.h>
#include<string.h>
//using namespace std;
struct myclass
{
    int zero,one,two;
};
int upd[300005];
myclass tree[300005];
void build(int node,int b,int e)
{
    tree[node].zero=e-b+1;
    tree[node].one=0;
    tree[node].two=0;
    if(b==e) return;
    build(node*2,b,(b+e)/2);
    build(node*2+1,(b+e)/2+1,e);
}
void up(int node,int b,int e)
{
    if(upd[node]==1)
    {
        int k=tree[node].one;
        tree[node].one=tree[node].zero;
        int i=tree[node].two;
        tree[node].two=k;
        tree[node].zero=i;
    }
    else if(upd[node]==2)
    {
        int k=tree[node].two;
        tree[node].two=tree[node].zero;
        int i=tree[node].one;
        tree[node].one=k;
        tree[node].zero=i;
    }
    if(b!=e)
    {
        upd[node*2]=(upd[node*2]+upd[node])%3;
        upd[node*2+1]=(upd[node*2+1]+upd[node])%3;
    }
    upd[node]=0;
}
myclass update(int node,int b,int e,int i,int j)
{
    up(node,b,e);
    if(b>j || e<i) return tree[node];
    if(b>=i && e<=j)
    {
        int k=tree[node].one;
        tree[node].one=tree[node].zero;
        int i=tree[node].two;
        tree[node].two=k;
        tree[node].zero=i;
        if(b!=e)
        {
            upd[node*2]=(upd[node*2]+1)%3;
            upd[node*2+1]=(upd[node*2+1]+1)%3;
        }
        upd[node]=0;
        return tree[node];
    }
    myclass l,r;
    l=update(node*2,b,(b+e)/2,i,j);
    r=update(node*2+1,(b+e)/2+1,e,i,j);
    tree[node].zero=l.zero+r.zero;
    tree[node].one=l.one+r.one;
    tree[node].two=l.two+r.two;
    return tree[node];
}
int read(int node,int b,int e,int i,int j)
{
    up(node,b,e);
    if(b>j || e<i) return 0;
    if(b>=i && e<=j) return tree[node].zero;
    int l,r;
    l=read(node*2,b,(b+e)/2,i,j);
    r=read(node*2+1,(b+e)/2+1,e,i,j);
    return l+r;
}
int main()
{
    int n,i,j,k,q,t,c;
    scanf("%d",&t);
    for(c=1;c<=t;c++)
    {
        printf("Case %d:\n",c);
        //memset(tree,0,sizeof(tree));
        scanf("%d %d",&n,&q);
        build(1,0,n-1);
        memset(upd,0,sizeof(upd));
        while(q--)
        {
            scanf("%d %d %d",&k,&i,&j);
            if(k==0) update(1,0,n-1,i,j);
            else printf("%d\n",read(1,0,n-1,i,j));
        }
    }
    return 0;
}
