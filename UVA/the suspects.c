#include<stdio.h>
int p[3005],r[3005],mb[3005];
void makeset(int v)
{
    p[v]=v;
    r[v]=0;
    mb[v]=1;
}
int find(int v)
{
    if(p[v]!=v)
        return p[v]=find(p[v]);
    return p[v];
}
void link(int x,int y)
{
    if(r[x]>r[y])
    {
        p[y]=x;
        mb[x]+=mb[y];
    }
    else
    {
        p[x]=y;
        mb[y]+=mb[x];
        if(r[x]==r[y]) r[y]++;
    }
}
void merge(int j,int k)
{
    link(find(j),find(k));
}
int main()
{
    int n,m,i,j,k,f,l;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(n==0 && m==0) break;
        for(i=0;i<n;i++) makeset(i);
        for(i=0;i<m;i++)
        {
            scanf("%d",&k);
            if(k>=1)
            {
                scanf("%d",&f);
                for(j=2;j<=k;j++)
                {
                    scanf("%d",&l);
                    if(find(l)!=find(f)) merge(f,l);
                }
            }
        }
        printf("%d\n",mb[find(0)]);
    }
    return 0;
}
