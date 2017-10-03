#include<cstdio>
using namespace std;


double H[1000006];

void precal()
{
    H[1]=1;
    for(int i=2;i<=100000;i++)
    {
        H[i]=H[i-1]+(double)1/i;
    }
}

int main()
{
    int t,n,cs=0;
    precal();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("Case %d: %.10lf\n",++cs,n*H[n]);
    }
    return 0;
}


/**
Explanation:

E[x] denotes Expected value when we alreay got x different values

E[x]=1+x/n*E[x]+(n-x)/x*E[x+1];

solving E[x]=n/(n-x)+E[x+1];

so E[0]=n*H[n]+E[n]=n*H[n]

*/
