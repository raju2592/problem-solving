#include<bits/stdc++.h>
using namespace std;

int tree[400005];
int n,k;
int dp[100005],arr[100005];
int INF;

int update(int node,int b,int e,int i,int v)
{
    if(b>i || e<i) return tree[node];
    if(b==e) return tree[node]=v;
    int l=update(node*2,b,(b+e)/2,i,v);
    int r=update(node*2+1,(b+e)/2+1,e,i,v);
    return tree[node]=min(l,r);
}
int read(int node,int b,int e,int i,int j)
{
    if(b>j || e<i) return INF;
    if(b>=i && e<=j) return tree[node];
    int l=read(node*2,b,(b+e)/2,i,j);
    int r=read(node*2+1,(b+e)/2+1,e,i,j);
    return tree[node]=min(l,r);
}
int search(int val)
{
    //cout<<val;
    int l=0,r=n-1,m;
    while(r-l>1)
    {
        m=(l+r)/2;
        if(arr[m]>val) r=m;
        else l=m;
    }
    if(arr[l]>val) return l;
    if(arr[r]>val) return r;
    return n;
}
int main()
{
    int t,cs=1,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        for(i=0;i<n;i++) scanf("%d",&arr[i]);
        sort(arr,arr+n);
        if(n<3)
        {
            printf("Case %d: -1\n",cs++);
            continue;
        }
        INF=n+10;
        for(i=0;i<n;i++) update(1,0,n,i,INF);
        update(1,0,n,n,0);
        dp[n]=0;
        dp[n-1]=dp[n-2]=INF;
        for(i=n-3;i>=0;i--)
        {
            int nxt=search(arr[i]+2*k);
            //cout<<nxt<<" ";
            if(nxt-i<3)
            {
                dp[i]=INF;
                update(1,0,n,i,dp[i]);
            }
            else
            {
                dp[i]=min(INF,1+read(1,0,n,i+3,nxt));
                update(1,0,n,i,dp[i]);
            }
            //cout<<dp[i]<<endl;
        }
        if(dp[0]!=INF) printf("Case %d: %d\n",cs++,dp[0]);
        else printf("Case %d: -1\n",cs++);
    }
    return 0;
}
