#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;

vector<vector<long> > tree;
long n;
vector<long> v,p;
long long dp[2][100005];

void bfs(long s)
{
    v[s]=1;
    p[s]=0;
    long u,i,j,k;
    queue<long> q;
    q.push(s);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(i=0;i<tree[u].size();i++)
        {
            if(v[tree[u][i]]==0)
            {
                v[tree[u][i]]=1;
                p[tree[u][i]]=u;
                q.push(tree[u][i]);
            }
        }
    }
}

long long dpf(int pt,long ver)
{
    if(dp[pt][ver]!=-1) return dp[pt][ver];
    long long ans1,ans2,i;
    if(tree[ver].size()==1 && pt==1) return 0;
    else if(tree[ver].size()==1 && pt==0) return 1;
    ans1=1;
    for(i=0;i<tree[ver].size();i++)
    {
        if(tree[ver][i]==p[ver]) continue;
        ans1+=dpf(1,tree[ver][i]);
    }
    if(pt==0) return dp[pt][ver]=ans1;
    ans2=0;
    for(i=0;i<tree[ver].size();i++)
    {
        if(tree[ver][i]==p[ver]) continue;
        ans2+=dpf(0,tree[ver][i]);
    }
    return dp[pt][ver]=ans1<ans2?ans1:ans2;
}
int main()
{
    cin>>n;
    int i,j,k;
    tree.resize(n+1);
    for(i=1;i<n;i++)
    {
        cin>>j>>k;
        tree[j].push_back(k);
        tree[k].push_back(j);
    }
    v.resize(n+1);
    p.resize(n+1);
    for(i=1;i<=n;i++) v[i]=0;
    bfs(1);
    //for(i=1;i<=n;i++) cout<<p[i]<<' '
    memset(dp,-1,sizeof(dp));
    long long ans1=0,ans2=1;
    for(i=0;i<tree[1].size();i++) ans1+=dpf(0,tree[1][i]);
    for(i=0;i<tree[1].size();i++) ans2+=dpf(1,tree[1][i]);
    cout<<(ans1<ans2?ans1:ans2)<<endl;
    return 0;
}



























