#include<stdio.h>

int visited[102][102],ans,R,C;
char sky[104][103];

int dfs(int r,int c)
{
    int dr[]={0,1,-1},dc[]={0,1,-1},isstar=1,i,j,k;
    visited[r][c]=1;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(i!=0 || j!=0)
            {
                if(r+dr[i]<R && r+dr[i]>=0 && c+dc[j]<C && c+dc[j]>=0)
                {
                    if(sky[r+dr[i]][c+dc[j]]=='*' && visited[r+dr[i]][c+dc[j]]==0)
                    {
                        isstar=0;
                        dfs(r+dr[i],c+dc[j]);
                    }

                }
            }
        }
    }
    return isstar;
}
int main()
{
    int i,j,k,m,isstar;
    while(1)
    {
        scanf("%d %d",&R,&C);
        if(R==0 && C==0) break;
        gets(sky[103]);
        for(i=0;i<R;i++) gets(sky[i]);
        for(i=0;i<R;i++)
        {
            for(j=0;j<C;j++) visited[i][j]=0;
        }
        ans=0;
        for(i=0;i<R;i++)
        {
            for(j=0;j<C;j++)
            {
                if(sky[i][j]=='*' && visited[i][j]==0)
                {
                    isstar=dfs(i,j);
                    if(isstar) ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
