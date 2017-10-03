#include<iostream>
#include<map>
#include<vector>
#include<cstdio>
#include<string>
using namespace std;
vector<vector<int> > gr;
vector<int> v;
int visit(int n)
{
    v[n]=1;
    for(int i=0;i<gr[n].size();i++)
    {
        if(v[gr[n][i]]==1) return 0;
        else if(v[gr[n][i]]==0)
        {
            int  k=visit(gr[n][i]);
            if(!k) return k;
        }
    }
    v[n]=2;
    return 1;
}
int dfs()
{
    int i,k;
    v.resize(gr.size());
    for(i=1;i<v.size();i++) v[i]=0;
    for(i=1;i<gr.size();i++)
    {
        if(!v[i])
        {
            k=visit(i);
            if(!k) return 0;
        }
    }
    return 1;
}
int main()
{
    int i,j,k,t,m,d;
    cin>>t;
    map<string,int> mp;
    string a,b;
    for(int c=1;c<=t;c++)
    {
        mp.clear();
        cin>>m;
        d=0;
        gr.clear();
        gr.resize(1);
        getchar();
        for(i=0;i<m;i++)
        {
            cin>>a>>b;
            if(mp[a]==0)
            {
                d++;
                mp[a]=d;
                gr.resize(d+1);
            }
            if(mp[b]==0)
            {
                d++;
                mp[b]=d;
                gr.resize(d+1);
            }
            gr[mp[a]].push_back(mp[b]);
        }
        k=dfs();
        if(k==1) printf("Case %d: Yes\n",c);
        else printf("Case %d: No\n",c);
    }
    return 0;
}
