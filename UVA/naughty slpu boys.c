#include<stdio.h>
int get_result(int i,long int position,long long int pow_ten)
{
        int j;
		long long int total=0,prev=0;
        for(j=0;total<position;)
		{
			j++;
			prev=total;
			total+=i*pow_ten;
		}
        if(total==position) return 9;
		else
		{

			long int temp;
			int p;
			long long int k;
			int ans;
			int a;
			position=position-prev;
			if(position%i==0) temp=position/i-1;
			else temp=position/i;
			p=position%i;
			if(p==0) p=i;
			k=j*pow_ten+temp;
			for(a=1;a<=i-p+1;a++)
			{
				ans=k%10;
				k=k/10;
			}
			return ans;
		}
}

void main()
{
    long int n;
    long long int total,pow_ten,prev;
    int i,ans;
    while(scanf("%ld",&n)!=EOF)
    {
		if(n<10)
		{
			printf("%ld\n",n);
			continue;
		}

        total=0;
        pow_ten=1;
        for(i=0;total<n;)
        {
			i++;
			prev=total;
            total+=i*9*pow_ten;
            pow_ten=pow_ten*10;
        }
        if(total==n) ans=9;
        else ans=get_result(i,n-prev,pow_ten/10);
        printf("%d\n",ans);
    }
}
