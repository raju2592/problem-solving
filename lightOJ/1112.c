#include<stdio.h>
#include<string.h>
int n,q,arr[100005],tree[300000];
int build(int node,int b,int e)
{
    if(b==e) return tree[node]=arr[b];
    int l,r;
    l=build(node*2,b,(b+e)/2);
    r=build(node*2+1,(b+e)/2+1,e);
    return tree[node]=l+r;
}
int update(int node,int b,int e,int i,int j,int v)
{
    if(b>j || e<i) return tree[node];
    if(b>=i && e<=j)
    {
        tree[node]+=v;
        arr[i]+=v;
        return tree[node];
    }
    int l,r;
    l=update(node*2,b,(b+e)/2,i,j,v);
    r=update(node*2+1,(b+e)/2+1,e,i,j,v);
    return tree[node]=l+r;
}
int read(int node,int b,int e,int i,int j)
{
    if(b>j || e<i) return 0;
    if(b>=i && e<=j) return tree[node];
    int l,r;
    l=read(node*2,b,(b+e)/2,i,j);
    r=read(node*2+1,(b+e)/2+1,e,i,j);
    return l+r;
}
int main()
{
    int i,j,k,t,c;
    scanf("%d",&t);
    for(c=1;c<=t;c++)
    {
        scanf("%d %d",&n,&q);
        for(i=0;i<n;i++) scanf("%d",arr+i);
        memset(tree,0,sizeof(tree));
        build(1,0,n-1);
        printf("Case %d:\n",c);
        while(q--)
        {
            scanf("%d",&k);
            if(k==1)
            {
                scanf("%d",&i);
                printf("%d\n",arr[i]);
                update(1,0,n-1,i,i,-arr[i]);
            }
            if(k==2)
            {
                scanf("%d %d",&i,&j);
                update(1,0,n-1,i,i,j);
            }
            if(k==3)
            {
                scanf("%d %d",&i,&j);
                printf("%d\n",read(1,0,n-1,i,j));
            }
        }
    }
    return 0;
}
