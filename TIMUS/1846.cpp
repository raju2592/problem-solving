#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#define MAX 100000
using namespace std;

int val[350000];
map<int,int> no;
int pos[100005],nxt[100005],lst[100005];

int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int update(int node,int b,int e,int i,int v)
{
    if(i<b || i>e) return val[node];
    if(b==i && e==i)
    {
        if(v!=0) return val[node]=v;
        return val[node]=-1;
    }
    int l,r;
    l=update(node*2,b,(b+e)/2,i,v);
    r=update(node*2+1,(b+e)/2+1,e,i,v);
    if(l==-1) return val[node]=r;
    if(r==-1) return val[node]=l;
    return val[node]=gcd(l,r);
}
int main()
{
    int q,x,d,k,cnt,y;
    char c;
    scanf("%d",&q);
    getchar();
    d=0;
    cnt=0;
    memset(val,-1,sizeof(val));
    while(q--)
    {
        //cin>>c>>y;
        scanf("%c %d",&c,&y);
        getchar();
        if(no[y]==0)
        {
            d++;
            no[y]=d;
        }
        x=no[y];
        if(c=='+')
        {
            cnt++;
            if(pos[x]==0)
            {
                lst[x]=cnt;
                pos[x]=cnt;
            }
            else
            {
                nxt[lst[x]]=cnt;
                lst[x]=cnt;
            }
            k=update(1,1,MAX,cnt,y);
            if(k!=-1) printf("%d\n",k);//cout<<k<<'\n';
            else puts("1");
        }
        else
        {
            k=update(1,1,MAX,pos[x],0);
            if(k!=-1) printf("%d\n",k);//cout<<k<<'\n';
            else puts("1");
            pos[x]=nxt[pos[x]];
        }
    }
    return 0;
}
