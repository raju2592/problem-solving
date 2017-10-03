#include<stdio.h>
#include<math.h>
int main()
{
    int i,j,n,k;
    while(1)
    {
        scanf("%d",&n);
        if(n==0) break;
        k=(int) sqrt(n);
        n-=k*k;
        if(k%2)
        {
            if(n==0) printf("%d %d\n",1,k);
            else if(n<=k+1) printf("%d %d\n",n,k+1);
            else printf("%d %d\n",k+1,2*(k+1)-n);
        }
        else
        {
            if(n==0) printf("%d %d\n",k,1);
            else if(n<=k+1) printf("%d %d\n",k+1,n);
            else printf("%d %d\n",2*(k+1)-n,k+1);
        }
    }
    return 0;
}
