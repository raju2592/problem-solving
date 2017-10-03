#include<stdio.h>
#include<string.h>
int dp[32][100006],pw[32],n;

int mod(int a,int b)
{
    return (a%b+b)%b;
}

void print(int a,int b)
{
    int pos,x,y,val;
    pos=b/16;
    x=2*(b%16);
    y=x+1;
    if(dp[a][pos] &(1<<x)) val=1;
    else val=2;
    printf("%d",val);
    if(a>1)
    {
        int k=(val*pw[a])%n;
        k=mod(b-k,n);
        print(a-1,k);
    }
}
int main()
{
    int i,j,k,pos,x,y,m;
    int found;
    scanf("%d",&n);
    //int prev,cur;
    if(n==1) puts("1");
    else if(n==2) puts("2");
    else
    {
        //memset(dp,-1,sizeof(dp));
        found=0;
        pw[1]=1;
        for(i=2;i<=30;i++) pw[i]=(pw[i-1]*10)%n;
        //for(i=0;i<n;i++) dp[1][i]=-1;
        //dp[1][1]=1;
        dp[1][0] |= (1<<2);
        dp[1][0] |= (1<<5);
        for(i=2;i<=30;i++)
        {
            for(j=1;j<n;j++)
            {
                pos= j/16;
                m=j%16;
                x=2*m;
                y=x+1;
                if((dp[i-1][pos] & (1<<x)) || (dp[i-1][pos] & (1<<y)))
                {
                    k=(j+(1*pw[i])%n)%n;
                    //dp[i][k]=1;
                    pos= k/16;
                    m=k%16;
                    x=2*m;
                    y=x+1;
                    dp[i][pos] |= (1<<x);
                    k=(j+(2*pw[i])%n)%n;
                    pos= k/16;
                    m=k%16;
                    x=2*m;
                    y=x+1;
                    if((dp[i][pos] & (1<<x))==0 && (dp[i][pos] &(1<<y))==0)
                    {
                        dp[i][pos] |= (1<<y);
                    }
                }
            }
            if((dp[i][0] & (1<<0)) || (dp[i][0] & (1<<1)))
            {
                 print(i,0);
                 found=1;
                 break;
            }
        }
        if(!found) printf("Impossible");
    }
    return 0;
}
