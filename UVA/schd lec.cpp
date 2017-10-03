#include<cstdio>
#include<iostream>
#define NOT_POSSIBLE 2147483645
#define NOT_COMPUTED 2147483640
using namespace std;
int courses[1005],L,C,N,minlec[1005];
long int mindi[1005];

void compute_minlec(int si,int &min_lec,long int &min_di)
{
	if(si>N)
	{
		min_lec=0;
		min_di=0;
		return;
	}
    if(minlec[si]!=N+10)
    {
        min_lec=minlec[si];
        min_di=mindi[si];
        return;
    }
    if(si==N)
    {
        int tem=L-courses[N];
        minlec[si]=1;
        if(tem==0) mindi[si]=0;
        else if(tem<=10) mindi[si]=-C;
        else if(tem>10) mindi[si]=(tem-10)*(tem-10);
        min_lec=minlec[si];
        min_di=mindi[si];
        return;
    }
    long int w,di=NOT_POSSIBLE,temp_di;
    int lec=N+10,temp_lec,i;
    w=0;
    for(i=si;i<=N;i++)
    {
        w+=courses[i];
        if(w>L) break;
        compute_minlec(i+1,temp_lec,temp_di);
        if(temp_lec+1<lec)
        {
            lec=temp_lec+1;
            if(L-w==0) temp_di=temp_di;
            else if(L-w<=10) temp_di-=C;
            else if(L-w>10) temp_di+=(L-w-10)*(L-w-10);
            di=temp_di;
        }
		else if(temp_lec+1==lec)
		{
            if(L-w==0) temp_di=temp_di;
            else if(L-w<=10) temp_di-=C;
            else if(L-w>10) temp_di+=(L-w-10)*(L-w-10);
            if(temp_di<di) di=temp_di;
		}

    }
    minlec[si]=lec;
    mindi[si]=di;
    min_lec=minlec[si];
    min_di=mindi[si];
}
int main()
{
	int i,j,k,min_lec,w;
	int t=1;
	long int min_di;
	while(scanf("%d",&N)!=EOF)
	{
		if(N==0) break;
		if(t!=1) printf("\n");
		scanf("%d %d",&L,&C);
		for(i=1;i<=N;i++) scanf("%d",&courses[i]);
		for(i=0;i<1005;i++) minlec[i]=N+10;
		for(i=0;i<1005;i++) mindi[i]=NOT_COMPUTED;
        compute_minlec(1,min_lec,min_di);
		printf("Case %d:\n",t);
		printf("Minimum number of lectures: %d\n",min_lec);
		printf("Total dissatisfaction index: %ld\n",min_di);
		t++;
	}
	return 0;
}
