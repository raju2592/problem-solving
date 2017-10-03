#include<stdio.h>
#include<string.h>
#include<math.h>
void q_sort(int *arr,int l,int r)
{
	int x,i,j,q,temp;
	if(l<r)
	{
		x=arr[r];
		i=l-1;
		for(j=l;j<r;j++)
		{
			if(arr[j]<=x)
			{
				i++;
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
		temp=arr[i+1];
		arr[i+1]=arr[j];
		arr[j]=temp;
		q=i+1;
		q_sort(arr,l,q-1);
		q_sort(arr,q+1,r);
	}
}

int main()
{
    char str[255];
    int t,arr[27],taken[27],i,j,k,items,max_length,searching;
	long long int dp[28][28];
    scanf("%d\n",&t);
    while(t--)
    {
        gets(str);
        for(i=0;i<27;i++) taken[i]=0;
        j=0;
        for(i=0;i<strlen(str);i++)
        {
            if(str[i]>=65 && str[i]<=90 && taken[str[i]-64]==0)
            {
                taken[str[i]-64]=1;
                j++;
                arr[j]=str[i]-64;
            }
        }
        items=j;
        if(items==0)
        {
            printf("0 0\n");
            continue;
        }
        q_sort(arr,1,items);
        i=1;
        max_length=1;
        do{
            searching=(int)ceil((float)(arr[i]*5)/4);
            for(++i;i<=items;i++)
            {
                if(arr[i]>=searching)
                {
                    max_length++;
                    break;
                }
            }
        } while(i<=items);
        dp[items][1]=1;
        for(i=2;i<=max_length;i++) dp[items][i]=0;
        for(i=items-1;i>=1;i--)
        {
            for(j=1;j<=max_length;j++)
            {
                dp[i][j]=0;
				dp[i][j]=dp[i+1][j];
                if(j!=1)
                {
                    searching=(int)ceil((float)(arr[i]*5)/4);
                    k=i+1;
                    while(k<=items && arr[k]<searching) k++;
                    if(k<=items) dp[i][j]+=dp[k][j-1];
                }
                else dp[i][j]+=1;
            }
        }

        printf("%d %lld\n",max_length,dp[1][max_length]);
    }
    return 0;

}



