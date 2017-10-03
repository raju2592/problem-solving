#include<iostream>
#include<vector>
#define MAX 1000000
using namespace std;

int p[1000005];
vector<int> pr;
int cnt[4][1000005];
void sieve()
{
    int i,j;
    for(i=1;i<=MAX;i++) p[i]=1;
    for(i=2;i*i<=MAX;i++)
    {
        if(p[i])
        {
            pr.push_back(i);
            for(j=i;i*j<=MAX;j++) p[i*j]=0;
        }
    }
    for(;i<=MAX;i++) if(p[i]) pr.push_back(i);
}

void calc()
{
    int i,j,k;
    for(i=pr.size()-1;i>=0;i--)
    {
		//cout<<pr[i];
        cnt[0][i]=cnt[0][i+1]+(pr[i]%10==1);
        cnt[1][i]=cnt[1][i+1]+(pr[i]%10==3);
        cnt[2][i]=cnt[2][i+1]+(pr[i]%10==7);
        cnt[3][i]=cnt[3][i+1]+(pr[i]%10==9);
    }
}
int srch1(int n)
{
    int l=0,r=pr.size()-1,m;
    while(r-l>1)
    {
        m=(l+r)/2;
        if(pr[m]<n) l=m+1;
        else r=m;
    }
    if(pr[l]>=n) return l;
    return r;
}
int srch2(int n)
{
    int l=0,r=pr.size()-1,m;
    while(r-l>1)
    {
        m=(l+r)/2;
        if(pr[m]>n) r=m-1;
        else l=m;
    }
    if(pr[r]<=n) return r;
    return l;
}
int main()
{
    int n,i,j,k,ans,two,five,pw,x,y;
    sieve();
    calc();
	//for(i=pr.size()-1;i>=0;i--) cout<<pr[i];
    while(cin>>n)
    {
        if(n==0) break;
        ans=1;
        two=0;
        five=0;
        for(i=0;pr[i]*pr[i]<=n;i++)
        {
            pw=1;
            x=n;
            while(x/pr[i])
            {
                pw*=pr[i];
                x/=pr[i];
            }
            if(pr[i]!=2 && pr[i]!=5) ans=(ans*pw)%10;
        }
        x=srch1(pr[i]);
        y=srch2(n);
        for(i=0;i<cnt[1][x]-cnt[1][y+1];i++) ans=(ans*3)%10;
        for(i=0;i<cnt[2][x]-cnt[2][y+1];i++) ans=(ans*7)%10;
        for(i=0;i<cnt[3][x]-cnt[3][y+1];i++) ans=(ans*9)%10;
        x=n;
        two=five=0;
        while(x/2)
        {
            two++;
            x/=2;
        }
        x=n;
        while(x/5)
        {
            five++;
            x/=5;
        }
        if(two>five)
        {
            for(i=0;i<two-five;i++) ans=(ans*2)%10;
        }
        else
        {
            for(i=0;i<five-two;i++) ans=(ans*5)%10;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
