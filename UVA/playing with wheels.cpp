#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
int init[4],n,v[10000],d[10000],final[4],fb[10000];
int convert(int *arr)
{
    int i,val=0,pow_ten=1;
    for(i=3;i>=0;i--)
    {
        val+=arr[i]*pow_ten;
        pow_ten*=10;
    }
	return val;
}
void de(int *arr,int val)
{
    int i,pow_ten=1000;
    for(i=0;i<4;i++)
    {
        arr[i]=val/pow_ten;
        val=val%pow_ten;
        pow_ten/=10;
    }
}

int bfs(int ival,int fval)
{
    int i,s,j,k,u,val,arr[4];
    for(i=0;i<10000;i++)
    {
        v[i]=0;
        d[i]=-1;
    }
    v[ival]=1;
    d[ival]=0;
    queue<int> q;
    q.push(ival);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        de(arr,u);
        for(i=0;i<4;i++)
        {
            arr[i]=(arr[i]+9)%10;
            val=convert(arr);
            if(v[val]==0 && fb[val]==0)
            {
                v[val]=1;
                d[val]=d[u]+1;
                if(val==fval) return d[val];
                q.push(val);
            }
            arr[i]=(arr[i]+2)%10;
            val=convert(arr);
            if(v[val]==0 && fb[val]==0)
            {
                v[val]=1;
                d[val]=d[u]+1;
                if(val==fval) return d[val];
                q.push(val);
            }
            arr[i]=(arr[i]+9)%10;
        }
    }
    return d[fval];
}
int main()
{
    int t,i,j,k,f[4],val,fval,ival;
    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<4;i++) scanf("%d",&init[i]);
        for(i=0;i<4;i++) scanf("%d",&final[i]);
        scanf("%d",&n);
        for(i=0;i<10000;i++) fb[i]=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<4;j++) scanf("%d",&f[j]);
            val=convert(f);
            fb[val]=1;
        }
        ival=convert(init);
        fval=convert(final);
        if(fb[ival]==1) printf("-1\n");
        else printf("%d\n",bfs(ival,fval));
    }
    return 0;
}
