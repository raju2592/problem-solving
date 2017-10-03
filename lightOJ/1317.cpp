#include<cstdio>
using namespace std;

int main()
{
    int t,n,m,k,cs=0;
    double p;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %lf",&n,&m,&k,&p);
        printf("Case %d: %.10lf\n",++cs,n*k*p);
    }
    return 0;
}

/**
Expectation of binomial random variable = np;

E[x1+x2+x3..]=E[x1]+E[x2]+E[x3]+.........

*/
