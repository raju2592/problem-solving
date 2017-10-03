#include<iostream>
#include<vector>
#include<cstdio>
#define MAX 5001
using namespace std;

int p[5005];
vector<int> pr;
vector<int> fact;
int min(int i,int j){return i<j?i:j;}
void sieve()
{
    int i,j,k;
    for(i=2;i<=MAX;i++) p[i]=1;
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

/*int gcd(int a,int b)
{
    if(a%b==0) return b;
    else return gcd(b,a%b);
}*/
int find_ans()
{
    int ret=fact[0];
    for(int i=1;i<fact.size();i++) ret=min(ret,fact[i]);
    return ret;
}
int main()
{
    int i,j,k,n,m,t,kase,cnt,ans,pw,val,tmp,x;
    bool b;
    sieve();
    cin>>t;
    kase=0;
    while(t--)
    {
        fact.clear();
        cin>>m>>n;
        printf("Case %d:\n",++kase);
        if(n==1)
        {
            printf("Impossible to divide\n");
            continue;
        }
        b=false;
		x=m;
        for(i=0;i<pr.size() && pr[i]<=m;i++)
        {
			//if(pr[i]==m) cout<<"ok"<<endl;
            cnt=0;
            while(m%pr[i]==0)
            {
                cnt++;
                m/=pr[i];
            }
			//if(m==1) cout<<cnt<<' ';
            if(cnt)
            {
                tmp=0;
                val=pr[i];
                pw=1;
                while(val<=n)
                {
                    //tmp+=n/pw;
                    for(j=1;j*val<=n;j++)
                    {
                        if(j%pr[i]) tmp+=pw;
                    }
                    val*=pr[i];
                    pw++;
                }
                if(tmp<cnt)
                {
                    printf("Impossible to divide\n");
                    b=true;
                    break;
                }
                else fact.push_back(tmp/cnt);
            }
        }
        if(!b) cout<<find_ans()<<endl;
    }
    return 0;
}
