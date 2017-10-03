#include<stdio.h>
typedef struct
{
    long long fu;
    long long kh;
} sln;
int main()
{
    int n,i;
    sln mem[35];
    mem[0].fu=1;
    mem[1].kh=1;
    mem[2].kh=1;
    mem[2].fu=3;
    for(i=3;i<=30;i++)
    {
        if(i%2==1)
        {
            mem[i].kh=mem[i-1].fu+mem[i-2].kh;
        }
        else
        {
            if((i/2)%2==0)
            {
                mem[i].fu=mem[i/2].fu*mem[i/2].fu+2*mem[i/2].kh*mem[i/2].kh;
                mem[i].kh=mem[i-2].fu+mem[i-3].kh;
            }
            else
            {
                mem[i].fu=mem[i/2+1].fu*mem[i/2-1].fu+2*mem[i/2+1].kh*mem[i/2-1].kh;
                mem[i].kh=mem[i-2].fu+mem[i-3].kh;
            }
        }
    }
    while(1)
    {
        scanf("%d",&n);
        if(n==-1) break;
        if(n%2==1) printf("0\n");
        else printf("%lld\n",mem[n].fu);
    }
    return 0;
}
