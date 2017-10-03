#include<stdio.h>

#define INFINITY 999999999
/*  0==left+down
    1==right+down
    2==absolute maximum
*/
#define max(i,j) i>j?i:j
int main()
{
    int N,k,grid[77][77],neg,i,j,a,b,c,t,sum;
    long m[6][3][77][77];
    c=0;
    while(++c)
    {
        scanf("%d %d",&N,&k);
		if(N==0 && k==0) break;
        for(i=1;i<=N;i++)
            for(j=1;j<=N;j++) scanf("%d",&grid[i][j]);
        neg=0;
        sum=0;
        for(i=N;i>=1;i--)
        {
            sum+=grid[N][i];
            if(grid[N][i]<0) neg++;
            for(j=0;j<=k;j++)
            {
                if(neg<=j) m[j][2][N][i]=sum;
                else m[j][2][N][i]=-INFINITY;
            }

        }
        for(i=N-1;i>=1;i--)
        {
            if(grid[i][1]>=0)
            {
                for(j=0;j<=k;j++)
                {
                    m[j][0][i][1]=m[j][2][i+1][1];
                    if(m[j][0][i][1]!=-INFINITY) m[j][0][i][1]+=grid[i][1];

                }
            }
            else
            {
                m[0][0][i][1]=-INFINITY;
                for(j=1;j<=k;j++)
                {
                    m[j][0][i][1]=m[j-1][2][i+1][1];
                    if(m[j][0][i][1]!=-INFINITY) m[j][0][i][1]+=grid[i][1];
                }
            }
            for(j=2;j<=N;j++)
            {
                if(grid[i][j]>=0)
                {
                    for(a=0;a<=k;a++)
					{
						m[a][0][i][j]=max(m[a][0][i][j-1],m[a][2][i+1][j]);
						if(m[a][0][i][j]!=-INFINITY) m[a][0][i][j]+=grid[i][j];
					}
                }
                else
                {
                    m[0][0][i][j]=-INFINITY;
                    for(a=1;a<=k;a++)
					{
						m[a][0][i][j]=max(m[a-1][0][i][j-1],m[a-1][2][i+1][j]);
                        if(m[a][0][i][j]!=-INFINITY) m[a][0][i][j]+=grid[i][j];
					}
                }
            }
            if(grid[i][N]>0)
            {
                for(j=0;j<=k;j++)
                {
                    m[j][1][i][N]=m[j][2][i+1][N];
                    if(m[j][1][i][N]!=-INFINITY) m[j][1][i][N]+=grid[i][N];
                }
            }
            else
            {
                m[0][1][i][N]=-INFINITY;
                for(j=1;j<=k;j++)
                {
                    m[j][1][i][N]=m[j-1][2][i+1][N];
                    if(m[j][1][i][N]!=-INFINITY) m[j][1][i][N]+=grid[i][N];
                }
            }
            for(j=N-1;j>=1;j--)
            {
                if(grid[i][j]>=0)
                {
                    for(a=0;a<=k;a++)
					{
						m[a][1][i][j]=max(m[a][1][i][j+1],m[a][2][i+1][j]);
						if(m[a][1][i][j]!=-INFINITY) m[a][1][i][j]+=grid[i][j];
					}
                }
                else
                {
                    m[0][1][i][j]=-INFINITY;
                    for(a=1;a<=k;a++)
					{
						m[a][1][i][j]=max(m[a-1][1][i][j+1],m[a-1][2][i+1][j]);
                        if(m[a][1][i][j]!=-INFINITY) m[a][1][i][j]+=grid[i][j];
					}
                }
            }
            for(j=1;j<=N;j++)
            {
                for(a=0;a<=k;a++) m[a][2][i][j]=max(m[a][0][i][j],m[a][1][i][j]);
            }
        }
        if(m[k][2][1][1]==-INFINITY) printf("Case %d: impossible\n",c);
        else printf("Case %d: %ld\n",c,m[k][2][1][1]);
    }
    return 0;
}


