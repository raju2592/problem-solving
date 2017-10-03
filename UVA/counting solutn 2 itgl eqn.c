#include<stdio.h>
int main()
{
    long int n,x,y_plus_z,i;
    long long int soln;
    int start;
    while(scanf("%ld",&n)!=EOF)
    {
        if(n%2==0) start=0;
        else start=1;
        soln=0;
        for(x=start;x<=n-2;x+=2)
        {
            y_plus_z=(n-x)/2;
            soln+=y_plus_z+1;
        }
        soln+=1;
        printf("%lld\n",soln);
    }
    return 0;
}
