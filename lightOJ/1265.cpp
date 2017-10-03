#include<cstdio>
#define MAX 1000
using namespace std;

double dp[1005][1005];
double max(double a,double b)
{
    return a>b?a:b;
}

void precal()
{
    int i,j,k;
    double p,a,b,x,y;
    for(i=0;i<=MAX;i++) dp[0][i]=1;
    for(i=1;i<=MAX;i++)
    {
        for(j=0;j<=MAX;j++)
        {
            a=b=1;
            //dp[i][j]=0;
            x=y=0;
            if(i>=2)
            {
                p=(double)(i*(i-1))/((i+j+1)*(i+j));
                x+=p*dp[i-2][j];
                y+=p*dp[i-2][j];
            }
            if(j>=2)
            {
                p=(double)(j*(j-1))/((i+j+1)*(i+j));
                a-=p;
                b-=p;
            }
            if(j!=0)
            {
                p=(double)(2*i*j)/((i+j+1)*(i+j));
                x+=p*dp[i][j-1];
                y+=p*dp[i][j-1];
                p=(double)(2*j)/((i+j+1)*(i+j));
                //dp[i][j]=max((dp[i][j]+p*dp[i][j-1])/a,dp[i][j]/(a-p));
                x+=p*dp[i][j-1];
                b-=p;
            }
            dp[i][j]=max(x/a,y/b);
        }
    }
}

int main()
{
    int k,t,d,cs=0;
    precal();
    scanf("%d",&k);
    while(k--)
    {
        scanf("%d %d",&t,&d);
        printf("Case %d: %.10lf\n",++cs,dp[t][d]);
    }
    return 0;
}
