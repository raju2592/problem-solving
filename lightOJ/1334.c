#include<string.h>
#include<stdio.h>
#define ll long long
//using namespace std;


ll pf1[50005],pf2[50005];
ll cx[50005],cy[50005];
ll mx[50005],my[50005];
char d[50005],g[50005],grev[50005];

void cpf(char *st,ll len,ll *pi)
{
    ll i,j,k;
    pi[1]=0;
    k=0;
    for(i=2;i<=len;i++)
    {
        while(k>0 && st[i]!=st[k+1]) k=pi[k];
        if(st[i]==st[k+1]) k++;
        pi[i]=k;
    }
}
int main()
{
    ll t,cs=0,l1,l2,i,j,k,x,y,ans;
    scanf("%lld",&t);
    while(t--)
    {
        d[0]=g[0]='*';
        scanf("%s %s",d+1,g+1);
        //gets(d+1);
        //gets(g+1);
        l1=strlen(d)-1;
        l2=strlen(g)-1;
        for(i=1,j=l2;i<=l2;i++,j--) grev[i]=g[j];

        cpf(g,l2,pf1);
        cpf(grev,l2,pf2);

        cx[0]=cy[0]=0;
        cx[1]=cy[1]=1;
        for(i=2;i<=l2;i++)
        {
            cx[i]=cy[i]=1;
            if(pf1[i]) cx[i]+=cx[pf1[i]];
            if(pf2[i]) cy[i]+=cy[pf2[i]];
        }

        k=0;
        for(i=1;i<=l1;i++)
        {
            while(k>0 && g[k+1]!=d[i]) k=pf1[k];
            if(g[k+1]==d[i]) k++;
            if(k==l2) k=pf1[k];
            mx[i]=k;

        }

        k=0;
        for(i=l1;i>=1;i--)
        {
            while(k>0 && grev[k+1]!=d[i]) k=pf2[k];
            if(grev[k+1]==d[i]) k++;
            if(k==l2) k=pf2[k];
            my[i]=k;
        }
        ans=0;
        for(i=1;i<l1;i++) ans=(ans+cx[mx[i]]*cy[my[i+1]]);
        printf("Case %lld: %lld\n",++cs,ans);

    }
    return 0;
}
