#include<stdio.h>
#define NOT_COMP -1;

unsigned long int dp[28][355][28];


unsigned long int compute(int l,int s,int from)
{
	int sum=0,i;
	unsigned long int ans;
	if(l==1)
	{
		if(s>from) return 0;
		else return 1;
	}
	if(l>=s) return 0;
	if(dp[l][s][from]!=-1) return dp[l][s][from];
	sum=(l*(2*from+1-l))/2;
	if(sum<s)
	{
        dp[l][s][from]=0;
        return 0;
	}
	else if(sum==s)
	{
	    dp[l][s][from]=1;
	    return 1;
	}
	sum=(l*(l+1))/2;
	if(sum>s)
	{
	    dp[l][s][from]=0;
        return 0;
	}
	else if(sum==s)
	{
	    dp[l][s][from]=1;
	    return 1;
	}
	ans=0;
	if(s<=from)
	{
		for(i=s-1;i>=2;i--) ans+=compute(l-1,s-i,i-1);
	}
	else
	{
		for(i=from;i>=2;i--) ans+=compute(l-1,s-i,i-1);
	}
	dp[l][s][from]=ans;
	return dp[l][s][from];
}
int main()
{
	int l,s,i,j,k;
	for(i=0;i<28;i++)
			for(j=0;j<355;j++)
				for(k=0;k<28;k++) dp[i][j][k]=NOT_COMP;

    i=0;

	while(++i)
	{

		scanf("%d %d",&l,&s);
		if(l==0 && s==0) break;
		if(l>26 || s>351 || s==0) printf("Case %d: 0\n",i);
		else printf("Case %d: %lu\n",i,compute(l,s,26));
	}
	return 0;
}
