#include<stdio.h>
#include<math.h>
#define MAX 10000000

int pr[10000004],sp[10000004],even[10000004],odd[10000004],sq;

void calc()
{
    int i,j,k,cnt;
    for(i=1;i<=MAX;i++) pr[i]=1;
    sq=sqrt(MAX);
    for(i=2;i<=sq;i++)
    {
        if(pr[i])
        {
            sp[i]=i;
            for(j=i;i*j<=MAX;j++)
            {
                if(pr[i*j])
                {
                    sp[i*j]=i;
                    pr[i*j]=0;
                }

            }
        }
    }

    for(i=2;i<=sq;i++)
    {
        j=sp[i];
        k=i;
        cnt=0;
        while(k%j==0)
        {
            k/=j;
            cnt++;
        }
        if(cnt&1) odd[i]++;
        else even[i]++;
        even[i]+=even[k];
        odd[i]+=odd[k];
    }
}

int main()
{
    int n,i,j,k,t,cnt,evc,oddc;
    scanf("%d",&t);
    calc();
    while(t--)
    {
        scanf("%d",&i);
        if(pr[i]==1) printf("Ordinary Number\n");
        else
        {
            evc=oddc=0;
            while(i>sq)
            {
                cnt=0;
                if(pr[i]) j=i;
                else j=sp[i];
                while(i%j==0)
                {
                    cnt++;
                    i/=j;
                }
                if(cnt&1) oddc++;
                else evc++;
            }
            evc+=even[i];
            oddc+=odd[i];

            if(evc>oddc) printf("Psycho Number\n");
            else printf("Ordinary Number\n");
        }
    }
    return 0;
}
