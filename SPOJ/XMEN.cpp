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
#define pb push_back
#define mp make_pair
#define ll int
using namespace std;


int val[400005];
int pos[100005][3];
pair<int,int> arr[100005];

ll Min(ll i,ll j){return i<j?i:j;}
ll Max(ll i,ll j){return i>j?i:j;}

int update(int node,int b,int e,int i,int v)
{
    if(b>i || e<i) return val[node];
    if(b==e) return val[node]=v;
    int l=update(node*2,b,(b+e)/2,i,v);
    int r=update(node*2+1,(b+e)/2+1,e,i,v);
    return val[node]=Max(l,r);
}

int read(int node,int b,int e,int i,int j)
{
    if(j==0) return 0;
    if(b>j || e<i) return -1;
    if(b>=i && e<=j) return val[node];
    int l=read(node*2,b,(b+e)/2,i,j);
    int r=read(node*2+1,(b+e)/2+1,e,i,j);
    return Max(l,r);
}
int main()
{
    int t,n,i,j,k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>j;
            pos[j][0]=i;
        }
        for(i=1;i<=n;i++)
        {
            cin>>j;
            pos[j][1]=i;
        }
        for(i=1;i<=n;i++) arr[i]=mp(pos[i][0],pos[i][1]);
        sort(arr+1,arr+n+1);
        memset(val,0,sizeof(val));
        for(i=1;i<=n;i++)
        {

            int x=read(1,1,n,1,arr[i].second-1);
            //cout<<arr[i].second<<" "<<x<<endl;
            update(1,1,n,arr[i].second,x+1);
        }
        cout<<read(1,1,n,1,n)<<endl;
    }
    return 0;
}
