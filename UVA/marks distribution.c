#include<stdio.h>
#define ll long long
unsigned ll comb[145][75];
void nCr(int n,int r)
{
    int i,j;
    for(i=0;i<145;i++)
    {
        comb[i][0]=1;
        for(j=1;j<75;j++) comb[i][j]=0;
    }
    for(i=1;i<142;i++)
    {
        for(j=1;j<=r;j++) comb[i][j]=comb[i-1][j]+comb[i-1][j-1];
    }
}
int main()
{
    int c,n,t,p;
    scanf("%d",&c);
    nCr(141,71);
    while(c--)
    {
        scanf("%d %d %d",&n,&t,&p);
        printf("%llu\n",comb[t-n*p+n-1][n-1]);
    }
    return 0;
}
