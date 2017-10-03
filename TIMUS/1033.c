#include<stdio.h>
#include<string.h>

int v[50][50],ans=0,n;
char gr[50][50];
void dfs(int r,int c)
{
    v[r][c]=1;
    if(r-1<0)
    {
        if(c!=0) ans++;
    }
    else
    {
        if(v[r-1][c]==0 && gr[r-1][c]=='.') dfs(r-1,c);
        else if(gr[r-1][c]=='#') ans++;
    }
    if(r+1==n)
    {
        if(c!=n-1) ans++;
    }
    else
    {
        if(v[r+1][c]==0 && gr[r+1][c]=='.') dfs(r+1,c);
        else if(gr[r+1][c]=='#') ans++;
    }
    if(c-1<0)
    {
        if(r!=0) ans++;
    }
    else
    {
        if(v[r][c-1]==0 && gr[r][c-1]=='.') dfs(r,c-1);
        else if(gr[r][c-1]=='#') ans++;
    }
    if(c+1==n)
    {
        if(r!=n-1) ans++;
    }
    else
    {
        if(v[r][c+1]==0 && gr[r][c+1]=='.') dfs(r,c+1);
        else if(gr[r][c+1]=='#') ans++;
    }
}
int main()
{
    int i,j,k;
    scanf("%d\n",&n);
    for(i=0;i<n;i++) gets(gr[i]);
    memset(v,0,sizeof(v));
    dfs(0,0);
    if(v[n-1][n-1]==0) dfs(n-1,n-1);
    printf("%d",ans*9);
    return 0;
}
