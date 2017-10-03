#include<stdio.h>
#include<string.h>
#define ll long long
ll n, bit[20005];
ll read(ll idx)
{
    ll sum=0;
    while(idx>0)
    {
        sum+=bit[idx];
        idx-=(idx & -idx);
    }
	return sum;
}
ll updt(ll idx)
{
    while(idx<=n)
    {
        bit[idx]++;
        idx+=(idx & -idx);
    }
}
int main()
{
    ll t,i,j,k,cur,out[20005],c,tg,up;
    scanf("%lld",&c);
    while(c--)
    {
        scanf("%lld",&n);
        memset(bit,0,sizeof(bit));
        cur=0;
        for(i=1;i<=n;i++)
        {
            t=n-read(n),tg;
            if(i+1>t)
			{
				if((i+1)%t)
				{
					tg=(i+1)%t;
				}
				else
				{
					tg=t;
				}
			}
            else tg=i+1;
			//if(tg==0) tg=i+1;
            up=t-cur+read(cur);
            if(tg>up)
            {
                cur=0;
                tg=tg-up;
            }
            ll c=cur+tg-read(cur+tg),p=cur-read(cur);
            cur=cur+tg;
            tg-=c-p;
            while(tg>0)
            {
                p=c;
                c=cur+tg-read(cur+tg);
                cur+=tg;
                tg-=c-p;
            }
            updt(cur);
            out[cur]=i;
				//cur=cur+1;
				//if(cur>1) cur=1;

            /*else
            {
                tg=tg-up;
                cur=0;
            }*/
        }

        for(i=1;i<=n;i++) printf("%lld ",out[i]);
        printf("\n");
    }
    return 0;
}
