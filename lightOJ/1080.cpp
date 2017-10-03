#include<iostream>
#include<cstring>
#include<cstdio>
#define ll int
using namespace std;

ll val[2500000];
ll add[2500000];
ll updt(ll node,ll b,ll e,ll i,ll j,ll v)
{
    if(e<i || b>j) return 0;
    if(b>=i && e<=j)
    {
        val[node]+=(e-b+1)*v;
        add[node*2]+=v;
        add[node*2+1]+=v;
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
    add[node*2]+=add[node];
    add[node*2+1]+=add[node];
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
    int i,j,k,mx,q,t;
    char str[300005],c;
    scanf("%d",&t);
	getchar();
    for(int cc=1;cc<=t;cc++)
    {
        gets(str+1);
        str[0]=1;
        mx=strlen(str)-1;
        printf("Case %d:\n",cc);
        scanf("%d",&q);
		getchar();
        memset(val,0,sizeof(val));
        memset(add,0,sizeof(add));
        while(q--)
        {
            scanf("%c",&c);
            if(c=='I')
            {
                scanf("%d %d",&i,&j);
				getchar();
                updt(1,1,mx,i,j,1);
            }
            else
            {
                scanf("%d",&i);
				getchar();
                k=read(1,1,mx,i,i);
                if(k%2) printf("%d\n",(str[i]-'0'+1)%2);
                else printf("%d\n",str[i]-'0');
            }
        }
    }
    return 0;
}
