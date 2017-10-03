#include<cstdio>
#include<iostream>
using namespace std;
int D,G;
long long int even[70][35][35],odd[70][35][35],not_used;
void compute(int total,int oddsum,int evensum,long long int &od, long long int &ev)
{
	if(evensum==0)
	{
	    od=1;
	    ev=0;
	    return;
	}
	if(oddsum==0)
	{
	    od=0;
	    ev=0;
	    return;
	}
    if(even[total][oddsum][evensum]!=-100)
    {
        od=odd[total][oddsum][evensum];
        ev=even[total][oddsum][evensum];
        return;
    }
    int small;
    if(G<oddsum) small=G;
    else small=oddsum;
    int i;
    long long int temp_even,temp_odd;
    od=0;
    ev=0;

    for(i=1;i<=small;i++)
    {
        if(i!=total)
        {
            compute(total-i,evensum,oddsum-i,temp_odd,temp_even);
            od+=temp_even;
            ev+=temp_odd;
        }
        else od+=1;
    }
    odd[total][oddsum][evensum]=od;
    even[total][oddsum][evensum]=ev;


}
int main()
{
	int t=0,i,j,k,l;
	long long int ans;
	while(++t)
	{
		scanf("%d %d",&D,&G);
		if(D==-1 && G==-1) break;
		if(D==0)
		{
		    printf("Case %d: 1\n",t);
		    continue;
		}
		else if(G==0)
		{
		    printf("Case %d: 0\n",t);
		    continue;
		}
        for(j=0;j<70;j++)
            for(k=0;k<35;k++)
                for(l=0;l<35;l++)
                {
                    even[j][k][l]=-100;
                    odd[j][k][l]=-100;
                }
		compute(2*D,D,D,not_used,ans);
		ans*=2;
		printf("Case %d: %lld\n",t,ans);
	}
	return 0;
}
