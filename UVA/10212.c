#include<stdio.h>

int main()
{
    int i,j,k,l,m,n,two,five;
    int d;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        two=0,five=0;
        for(i=n,j=1;j<=m;j++,i--)
        {
            k=i;
            while(k%2==0)
            {
                two++;
                k/=2;
            }
            k=i;
            while(k%5==0)
            {
                five++;
                k/=5;
            }
        }
        d=1;
        if(two>five)
        {
            for(i=1;i<=two-five;i++) d=(d*2)%10;
        }
        else
        {
            for(i=1;i<=five-two;i++) d=(d*5)%10;
        }
        for(i=n,j=1;j<=m;j++,i--)
        {
            k=i;
            while(k%5==0) k/=5;
            while(k%2==0) k/=2;
            d=(d*k)%10;
        }
        printf("%d\n",d);
    }
    return 0;
}
