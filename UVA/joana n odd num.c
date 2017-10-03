#include<stdio.h>
void main()
{
    unsigned long long int n,sum,p,x;
    while(scanf("%llu",&n)!=EOF)
    {
        p=(n-1)/2+1;
        x=2*p*p-1;
        sum=3*x-6;
        printf("%llu\n",sum);

    }
}
