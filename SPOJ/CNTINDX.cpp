//#include<bits/stdc++.h>

#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<utility>
#define N 200000
using namespace std;

map<int,int> tree[1000000];
int arr[1000000];
int size;

int update(int node,int b,int e,int i,int v,int f)
{
    if(b>i || e<i) return tree[node][v];
    if(b==e)
    {
        if(!f) return ++tree[node][v];
        return --tree[node][v];
    }
    int l=update(node*2,b,(b+e)/2,i,v,f);
    int r=update(node*2+1,(b+e)/2+1,e,i,v,f);
    return tree[node][v]=l+r;
}

int read(int node,int b,int e,int i,int j,int v)
{
    if(b>j || e<i) return 0;
    if(b>=i && e<=j) return tree[node][v];
    int l=read(node*2,b,(b+e)/2,i,j,v);
    int r=read(node*2+1,(b+e)/2+1,e,i,j,v);
    return l+r;
}
int main()
{
    int q,x,i,j,k;
    //cin>>q;
    scanf("%d",&q);
    size=0;
    while(q--)
    {
        //cin>>i;
        scanf("%d",&i);
        if(i==0)
        {
            //if(size==0) cout<<"invalid\n";
            if(size==0) puts("invalid");
            else
            {
                update(1,1,N,size,arr[size],1);
                size--;
            }
        }
        else if(i==1)
        {
            //cin>>j;
            scanf("%d",&j);
            size++;
            arr[size]=j;
            update(1,1,N,size,j,0);
        }
        else if(i==2)
        {
            //cin>>x>>j>>k;
            scanf("%d%d%d",&x,&j,&k);
            //cout<<read(1,1,N,j,k,x)<<"\n";
            printf("%d\n",read(1,1,N,j,k,x));
        }
    }
    return 0;
}
