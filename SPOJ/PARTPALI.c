#include<stdio.h>
#include<string.h>
#include<math.h>
#define ull unsigned long long
void Extended_Euclid(int a,int b,int *d,int *x,int *y)
{
    int x1,y1;
    if(b==0)
    {
        *d=a;
        *x=1;
        *y=0;
        return;
    }
    Extended_Euclid(b,a%b,d,&x1,&y1);
    *x=y1;
    *y=x1-(a/b)*y1;
    return;

}
int mod(int a,int b)
{
	if(a>=0) return a%b;
	else return (a%b+b) %b;
}
int congr_solver(int a,int b,int m,int *arr)
{
    int d,x,y,i,x1;
    Extended_Euclid(a,m,&d,&x,&y);
    if(b%d!=0) return 0;
    x1=x*(b/d);
	x1=mod(x1,m);
    for(i=0;i<d;i++) arr[i]=(x1+i*(m/d))%m;
    return d;
}
int main()
{
    int t,m,s,i,k,a,l,b,d,sln[20];
    unsigned long long j,po;
    unsigned long dp[21][1005],ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&m,&s);
        memset(dp,0,sizeof(dp));
        if(m%10==0)
        {
            printf("0\n");
            continue;
        }
        if(s==1)
        {
            if(m>10) printf("0\n");
            else
            {
                ans=0;
                k=m;
                while(k<=9)
                {
                    ans++;
                    k+=m;
                }
                printf("%lu\n",ans);
            }
            continue;
        }
        else if(s==2)
        {
            ans=0;
            for(i=1;i<=9;i++) if((i*10+i)%m==0) ans++;
            printf("%lu\n",ans);
            continue;
        }
        if(s%2==0)
        {
            l=2;
            for(i=0;i<=9;i++)
            {
                j=i*10+i;
                dp[2][j%m]++;
            }
        }
        else
        {
            l=1;
            for(i=0;i<=9;i++) dp[1][i%m]++;
        }
        po=pow(10,l+1);
        for(l=l+2;l<s;l+=2)
        {
            for(i=0;i<=9;i++)
            {
                j=(i*po+i);
                j%=m;
                for(k=0;k<m;k++)
                {
                    d=k-j;
                    if(d>=0)
                    {
                        b=congr_solver(10,d,m,sln);
                        for(a=0;a<b;a++) dp[l][k]+=dp[l-2][sln[a]];
                    }
                    d=m+k-j;
                    if(d<m)
                    {
                        b=congr_solver(10,d,m,sln);
                        for(a=0;a<b;a++) dp[l][k]+=dp[l-2][sln[a]];
                    }
                }
            }
            po=po*100;
        }
        ans=0;
        for(i=1;i<=9;i++)
        {
            j=(i*po+i);
            j%=m;
            if(j==0)
            {
                b=congr_solver(10,0,m,sln);
                for(a=0;a<b;a++) ans+=dp[l-2][sln[a]];
            }
            else
            {
                b=congr_solver(10,m-j,m,sln);
                for(a=0;a<b;a++) ans+=dp[l-2][sln[a]];
            }
        }
        printf("%lu\n",ans);
    }
    return 0;
}
