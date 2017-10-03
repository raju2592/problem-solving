#include<cstdio>
#include<algorithm>
#include<utility>
#include<vector>
#include<cstring>
#define ll int
using namespace std;
vector<int> quer1,quer2;
vector<pair<int,int> >upd;
int val[200005],add[200005];
int bsearch(int n,int f)
{
    int l=0,r=quer1.size()-1,m;
    while(r-l>1)
    {
        m=(l+r)/2;
        if(quer1[m]<n) l=m+1;
        else r=m;
    }
    if(f==0)
    {
        if(quer1[l]>=n) return l;
        if(quer1[l]<n && quer1[r]>=n) return r;
        if(quer1[r]<n)
        {
            if(r==quer1.size()-1) return -1;
            else return r+1;
        }
    }
    if(f==1)
    {
        if(quer1[r]<=n) return r;
        if(quer1[r]>n && quer1[l]<=n) return l;
        if(quer1[l]>n)
        {
            if(l==0) return -1;
            else return l-1;
        }
    }
}
ll updt(ll node,ll b,ll e,ll i,ll j,ll v)
{
    if(e<i || b>j) return 0;
    if(b>=i && e<=j)
    {
        val[node]+=(e-b+1)*v;
        if(b!=e)
        {
            add[node*2]+=v;
            add[node*2+1]+=v;
        }
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
    if(b!=e)
    {
        add[node*2]+=add[node];
        add[node*2+1]+=add[node];
    }
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
    int i,j,k,t,n,q;
    scanf("%d",&t);
    for(int c=1;c<=t;c++)
    {
        scanf("%d %d",&n,&q);
        upd.clear();
        quer1.clear();
        quer2.clear();
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&j,&k);
            upd.push_back(make_pair(j,k));
        }
        for(i=0;i<q;i++)
        {
            scanf("%d",&j);
            quer1.push_back(j);
            quer2.push_back(j);
        }
        sort(quer1.begin(),quer1.end());
        memset(val,0,sizeof(val));
        memset(add,0,sizeof(add));
        for(i=0;i<n;i++)
        {
            j=bsearch(upd[i].first,0);
            k=bsearch(upd[i].second,1);
            if(j!=-1 && k!=-1) updt(1,0,q-1,j,k,1);
        }
        printf("Case %d:\n",c);
        for(i=0;i<q;i++)
        {
            k=bsearch(quer2[i],0);
            j=read(1,0,q-1,k,k);
            printf("%d\n",j);
        }
    }
    return 0;
}
