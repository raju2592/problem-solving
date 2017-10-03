#include<cstdio>
#include<iostream>
#include<queue>
#define INF 1999999999
using namespace std;

int v[10006];
long d[10006];
int L,U,R,btn[12];
long bfs(int s,int t)
{
    int i,u,num;
    for(i=0;i<=9999;i++)
    {
        v[i]=0;
        d[i]=INF;
    }
    v[s]=1;
    d[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(i=0;i<R;i++)
        {
            num=(u+btn[i])%10000;
            if(num==t) return d[u]+1;
            if(v[num]==0)
            {
                v[num]=1;
                d[num]=d[u]+1;
                q.push(num);
            }
        }
    }
    return d[t];
}
int main()
{
    int i,j,k,c=1;
    long ans;
    while(1)
    {
        scanf("%d %d %d",&L,&U,&R);
        if(L==0 && U==0 && R==0) break;
        for(i=0;i<R;i++) scanf("%d",&btn[i]);
        if(L==U) printf("Case %d: 0\n",c);
        else
        {
            ans=bfs(L,U);
            if(ans==INF) printf("Case %d: Permanently Locked\n",c);
            else printf("Case %d: %ld\n",c,ans);
        }
        c++;
    }
    return 0;
}
