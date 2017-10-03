#include<stdio.h>

long int dp[205][205][205];
int myarr[205],previous[205];

long int dp_function(int l,int r)
{
	long int ans,original,temp,prev;

	if(dp[l][r][myarr[r]]!=-1) return dp[l][r][myarr[r]];
	if(l==r)
	{
	    long int x=myarr[l]*myarr[l];
		dp[l][r][myarr[r]]=x;
		return x;
	}
	if(r-l==1)
	{
	    long int x=myarr[l]*myarr[l]+myarr[r]*myarr[r];
		dp[l][r][myarr[r]]=x;
		return x;
	}
	temp=0;
	ans=dp_function(l,r-1)+myarr[r]*myarr[r];
	prev=r;
	while(1)
	{
		prev=previous[prev];
		if(prev<l) break;
		original=myarr[prev];
		myarr[prev]+=myarr[r];
	    temp=dp_function(prev+1,r-1)+dp_function(l,prev);
	    myarr[prev]=original;
	    if(temp>ans) ans=temp;
	}
	dp[l][r][myarr[r]]=ans;
	return ans;
}
int main()
{
    int t,n,last_found[205],temp,i,j,k,c;
    int current_type;
	long int ans;
    scanf("%d",&t);
    for(c=1;c<=t;c++)
    {
        for(i=0;i<205;i++)
        {
            myarr[i]=0;
			last_found[i]=0;
			previous[i]=0;
        }
		for(i=0;i<205;i++)
			for(j=0;j<205;j++)
				for(k=0;k<205;k++) dp[i][j][k]=-1;
        scanf("%d",&n);
        current_type=0;
        j=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&temp);
            if(temp==current_type) myarr[j]++;
            else
            {
				current_type=temp;
                j++;
				previous[j]=last_found[current_type];
				last_found[current_type]=j;
                myarr[j]++;
            }
        }
        /*for(i=1;i<=j;i++) printf("%d	",myarr[i]);
		printf("\n");
		for(i=1;i<=j;i++) printf("%d	",which_type[i]);
		printf("\n");
		for(i=1;i<=j;i++) printf("%d	",previous[i]);*/

		ans=dp_function(1,j);
		printf("Case %d: %ld\n",c,ans);

    }
    return 0;
}
