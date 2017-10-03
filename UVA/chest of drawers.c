#include<stdio.h>
int main()
{
    int n,s,i,j,k;
    unsigned long long sln[70][70];
    for(i=1;i<70;i++)
    {
        sln[i][i]=1;
        sln[i][i-1]=1;
    }
    sln[2][0]=2;
    sln[1][1]=1;
    sln[2][1]=1;
    for(i=3;i<70;i++) sln[i][0]=sln[i-1][0]+sln[i-2][0]; /*1+i-1+(i/2)*/
    for(i=1;i<70;i++)
    {
        for(j=i+1;j<70;j++) sln[i][j]=0;
    }
    for(i=2;i<70;i++)
        for(j=1;j<i-1;j++) sln[i][j]=sln[i-1][j-1]+sln[i-1][j]-sln[i-2][j-1]+sln[i-2][j];
    while(1)
    {
        scanf("%d %d",&n,&s);
        if(n<0 && s<0) break;
        printf("%llu\n",sln[n][s]);
    }
    return 0;
}
