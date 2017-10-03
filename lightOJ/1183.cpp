#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define ll long
int val[300005],lazy[300005];
int gcd(int a,int b)
{
    if(a%b==0) return b;
    else return gcd(b,a%b);
}
int updt(int node,int b,int e,int i,int j,int v)
{
	if(lazy[node]!=-1)
    {
        val[node]=lazy[node]*(e-b+1);
		if(e!=b)
		{
		    lazy[node*2]=lazy[node];
            lazy[node*2+1]=lazy[node];
		}
		lazy[node]=-1;
    }
    if(e<i || b>j)
    {
        return val[node];
    }
    if(b>=i && e<=j)
    {
        lazy[node]=-1;
        val[node]=v*(e-b+1);
        if(e!=b)
        {
            lazy[node*2]=v;
            lazy[node*2+1]=v;
        }
        return val[node];
    }
    int l,r;
    l=updt(node*2,b,(b+e)/2,i,j,v);
    r=updt(node*2+1,(b+e)/2+1,e,i,j,v);
    return val[node]=l+r;
}
int read(int node,int b,int e,int i,int j)
{
    if(lazy[node]!=-1)
    {
        val[node]=lazy[node]*(e-b+1);
        if(e!=b)
        {
            lazy[node*2]=lazy[node];
            lazy[node*2+1]=lazy[node];
        }
        lazy[node]=-1;
    }
    if(e<i || b>j) return 0;
    if(b>=i && e<=j) return val[node];
    int l,r;
    l=read(node*2,b,(b+e)/2,i,j);
    r=read(node*2+1,(b+e)/2+1,e,i,j);
    return l+r;
}

int main()
{
    int t,i,j,k,n,q,v;
    scanf("%d",&t);
    for(int c=1;c<=t;c++)
    {
        scanf("%d%d",&n,&q);
        printf("Case %d:\n",c);
        memset(val,0,sizeof(val));
        memset(lazy,-1,sizeof(lazy));
        while(q--)
        {
            scanf("%d",&k);
            if(k==1)
            {
                scanf("%d%d%d",&i,&j,&v);
                updt(1,0,n-1,i,j,v);
            }
            else
            {
                scanf("%d%d",&i,&j);
                //printf("%d\n",read(1,0,n-1,i,j));
                k=read(1,0,n-1,i,j);
				//cout<<k<<endl;
                v=gcd(k,j-i+1);
                if(v!=j-i+1) printf("%d/%d\n",k/v,(j-i+1)/v);
                else printf("%d\n",k/v);
            }
        }
    }
    return 0;
}
