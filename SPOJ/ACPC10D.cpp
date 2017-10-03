#include<cstdio>
#define ll long long
using namespace std;
typedef struct
{
    int a;
    int b;
    int c;
} level;

typedef struct
{
    ll a;
    ll b;
    ll c;
} rslt;

ll min(ll a,ll b,ll c,ll d)
{
    ll ret;
    ret=a<b?a:b;
    ret=ret<c?ret:c;
    ret=ret<d?ret:d;
    return ret;
}
ll min(ll a,ll b,ll c)
{
    ll ret;
    ret=a<b?a:b;
    ret=ret<c?ret:c;
    return ret;
}
ll min(ll a,ll b)
{
    ll ret;
    ret=a<b?a:b;
    return ret;
}
int main()
{
    ll N,i,j,k,c=1;
    level gr[100005];
    rslt prev,cur;
    while(scanf("%lld",&N)!=EOF)
    {
        if(N==0) break;
        for(i=1;i<=N;i++) scanf("%lld %lld %lld",&gr[i].a,&gr[i].b,&gr[i].c);
        prev.c=gr[N-1].c+gr[N].b;
        prev.b=gr[N-1].b+min(prev.c,gr[N].b,gr[N].a+gr[N].b);
        prev.a=gr[N-1].a+min(prev.b,gr[N].b,gr[N].a+gr[N].b);
        for(i=N-2;i>=1;i--)
        {
            cur.c=gr[i].c+min(prev.b,prev.c);
            cur.b=gr[i].b+min(cur.c,prev.b,prev.a,prev.c);
            cur.a=gr[i].a+min(cur.b,prev.a,prev.b);
            prev=cur;
        }
        printf("%lld. %lld\n",c,prev.b);
        c++;

    }
    return 0;
}














