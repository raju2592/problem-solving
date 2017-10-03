#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define ll long
ll maax;
ll bit[1000005];
void updt(ll i,ll up)
{
    if(i==0) bit[i]+=up;
    else while(i<=maax)
    {
        bit[i]+=up;
        i+=i & -i;
    }
}
ll read(ll i)
{
    ll sum=0;
    while(i>0)
    {
        sum+=bit[i];
        i-=i & -i;
    }
    sum+=bit[0];
    return sum;
}
int main()
{
    char str[1000005];
    ll l,i,j,k,c=1,ans,mx,mn;
    while(gets(str)!=NULL)
    {
        //getchar();
        l=strlen(str);
        if(l==0) break;
        maax=l-1;
        memset(bit,0,sizeof(bit));
		for(i=0;i<l;i++)
		{
			if(str[i]=='1') updt(i,1);
		}
        scanf("%ld",&k);
        printf("Case %ld:\n",c);
        while(k--)
        {
            scanf("%ld %ld",&i,&j);
            mx=i>j?i:j;
            mn=i<j?i:j;
            if(mn!=0) ans=read(mx)-read(mn-1);
            else ans=read(mx);
            if(ans==0 || ans%(mx-mn+1)==0) printf("Yes\n");
            else printf("No\n");

        }
        getchar();
		c++;
    }
    return 0;
}
