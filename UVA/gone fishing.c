#include<stdio.h>

int main()
{
    int n,h,f[30],d[30],t[30],i,j,k,f_rem,t_rem;
    long dp[200][30],tem;
    long ch[200][30];
    int c=1;
    while(scanf("%d",&n))
    {
        if(n==0) break;
        scanf("%d",&h);
        for(i=1;i<=n;i++) scanf("%d",f+i);
        for(i=1;i<=n;i++) scanf("%d",d+i);
        for(i=1;i<n;i++) scanf("%d",t+i);
        h*=12;
        t[n]=0;
        for(i=1;i<=n;i++)
        {
            dp[h][i]=0;
            ch[h][i]=0;
        }
        for(i=h-1;i>=0;i--)
        {
            dp[i][n]=0;
            ch[i][n]=h-i;

            f_rem=f[n];
            t_rem=h-i;
            while(f_rem>0 && t_rem>0)
            {
                dp[i][n]+=f_rem;
                f_rem-=d[n];
                t_rem--;
            }

            for(j=n-1;j>=1;j--)
            {
                dp[i][j]=-1;
                for(k=0;k<=h-i;k++)
                {
                    f_rem=f[j];
                    t_rem=k;
                    tem=0;
                    while(f_rem>0 && t_rem>0)
                    {
                        tem+=f_rem;
                        f_rem-=d[j];
                        t_rem--;
                    }
                    if(k+t[j]<=h-i) tem+=dp[i+k+t[j]][j+1];
                    if(tem>=dp[i][j])
                    {
                        dp[i][j]=tem;
                        ch[i][j]=k;
                    }
                }
            }
        }
        if(c!=1) printf("\n");
        printf("%ld",ch[0][1]*5);
        long t_pass=ch[0][1]+t[1];
        for(i=2;i<=n;i++)
        {
            printf(", ");
            if(t_pass>=h) printf("0");
            else
            {
                printf("%ld",ch[t_pass][i]*5);
                t_pass+=ch[t_pass][i]+t[i];
            }
        }
        printf("\nNumber of fish expected: %ld\n",dp[0][1]);
        c++;
    }
    return 0;
}
