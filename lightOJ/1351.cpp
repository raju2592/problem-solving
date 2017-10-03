#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;

int dp[2][2][65][65][65];
char stra[65],strb[65];
int len;

int calc(int cf,int flpd,int sa,int ea,int sb)
{
    int &ret=dp[cf][flpd][sa][ea][sb];
    if(ret!=-1) return ret;
    int sz;
    if(flpd) sz=sa-ea+1;
    else sz=ea-sa+1;
    if(sz<1) return 0;
    ret=INF;
    if(cf)
    {
        int k=calc(!cf,!flpd,ea,sa,sb);
        if(k!=INF) ret=k+1;
    }
    int eb=sb+sz-1;
    if(!flpd)
    {
        if(stra[sa]==strb[sb]) ret=min(ret,calc(1,0,sa+1,ea,sb+1));
        if(stra[ea]==strb[eb]) ret=min(ret,calc(1,0,sa,ea-1,sb));
    }
    else
    {
        if(stra[sa]==strb[sb]) ret=min(ret,calc(1,1,sa-1,ea,sb+1));
        if(stra[ea]==strb[eb]) ret=min(ret,calc(1,1,sa,ea+1,sb));
    }
    return ret;
}
int main()
{
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s %s",stra,strb);
        len=strlen(stra);
        memset(dp,-1,sizeof(dp));
        int k=calc(1,0,0,len-1,0);
        if(k!=INF) printf("Case %d: %d\n",cs++,k);
        else printf("Case %d: impossible\n",cs++);

    }
    return 0;
}
