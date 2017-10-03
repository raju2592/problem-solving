#include<stdio.h>
int main()
{
    long long int en_3,en_2,en_1,en;
    int n,i;
    while(scanf("%d",&n)!=EOF)
    {
        if( n==2 || n==3) printf("2\n");
        else if(n==1) printf("1\n");
        else
        {
            en_3=1;
            en_2=1;
            en_1=1;
            for(i=4;i<=n-1;i++)
            {
                en=en_2+en_3;
                en_3=en_2;
                en_2=en_1;
                en_1=en;
            }
            printf("%lld\n",en_1+en_2+en_3);
        }
    }
    return 0;
}

/*this problem uses simple recurrece
    S(n)=E(n)+E(n-1);
 or S(n)=E(n-1)+E(n-2)+E(n-3)
where E(1)=1,E(2)=2,E(3)=3 and
    E(n)=E(n-2)+E(n-3);

Here S(n) denotes solution of problem of
size n and E(n) denotes those solutions of
problem of size n that ends exactly at positin n*/
