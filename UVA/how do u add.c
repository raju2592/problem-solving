#include<stdio.h>
long long int arr[102][102];
long long int how_do_u_add(int N,int K)
{
    int i;
    long long int temp,ans;
    if(K==0) return 0;
    if(K==1) return 1;
    if(K==2) return N+1;
    if(arr[N][K]!=-100) return arr[N][K];

	ans=0;
    for(i=N;i>=0;i--)
    {
        temp=(how_do_u_add(N-i,K-1))%1000000;
        arr[N-i][K-1]=temp;
        ans+=temp;
    }
    arr[N][K]=ans;
    return ans;
}
int main()
{
	int N,K,i,j;
	long long int ans;
	for(i=0;i<103;i++)
    {
        for(j=0;j<103;j++) arr[i][j]=-100;
    }
	while(1)
	{
		scanf("%d %d",&N,&K);
		if(N==0 && K==0) break;
		ans=how_do_u_add(N,K);
		ans=ans%1000000;
		printf("%lld\n",ans);
	}
	return 0;
}
