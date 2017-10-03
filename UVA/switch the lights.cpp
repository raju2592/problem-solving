#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#define INF 1999999999
using namespace std;
vector<long> sw;
vector<long> v;
vector<long> d;
long power(int b,int p)
{
    long val=b,i;
    for(i=2;i<=p;i++) val*=b;
    return val;
}
long bfs(long s)
{
    long i,j,k;
    for(i=0;i<d.size();i++)
    {
        d[i]=INF;
        v[i]=0;
    }
    v[s]=1;
    d[s]=0;
    queue<int> q;
    q.push(s);
    long u,num;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(i=0;i<sw.size();i++)
        {
           num=u^sw[i];
           if(num==0) return d[u]+1;
           if(v[num]==0)
           {
               v[num]=1;
               d[num]=d[u]+1;
               q.push(num);
           }
        }
    }
    return d[0];
}
long convert(long int *arr,long int n)
{
    long int i,pow_two=1,val=0;
    for(i=n-1;i>=0;i--)
    {
        val+=arr[i]*pow_two;
        pow_two=pow_two*2;
    }
    return val;
}
int main()
{
    long t,n,m,i,j,k,c,arr[16];
    long min;
    cin>>t;
    for(c=1;c<=t;c++)
    {
        cin>>n>>m;
        sw.resize(m);
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++) cin>>arr[j];
            sw[i]=convert(arr,n);
        }
        long p=power(2,n);
        v.resize(p);
        d.resize(p);
        //for(i=0;i<m;i++) cout<<sw[i]<<' ';
        min=bfs(p-1);
        if(min==INF) printf("Case %d: IMPOSSIBLE\n",c);
        else printf("Case %d: %ld\n",c,min);
    }
    return 0;
}
