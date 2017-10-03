#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
vector<vector<int> > gr;
vector<int> even,odd;
void dfs(int n)
{
    int i;
    bool b=false;
    if(n==1 || even[n]) b=true;
    for(i=0;i<gr[n].size();i++)
    {
        if(b && !odd[gr[n][i]])
        {
            odd[gr[n][i]]=1;
            dfs(gr[n][i]);
        }
        if(odd[n] && !even[gr[n][i]])
        {
            even[gr[n][i]]=1;
            dfs(gr[n][i]);
        }
    }
}
int main()
{
    int t,i,j,k,n,m;
    cin>>t;
    for(int c=1;c<=t;c++)
    {
        cin>>n>>m;
        gr.clear();
        gr.resize(n+1);
        for(i=0;i<m;i++)
        {
            cin>>j>>k;
            gr[j].push_back(k);
            gr[k].push_back(j);
        }
        even.clear();
        even.resize(n+1);
        odd.clear();
        odd.resize(n+1);
        for(i=1;i<=n;i++)
        {
            even[i]=0;
            odd[i]=0;
        }
        even[1]=0;
        dfs(1);
        int ans=0;
        for(i=1;i<=n;i++) if(even[i]) ans++;
        printf("Case %d: %d\n",c,ans);
    }
    return 0;
}
