#include<iostream>
#include<vector>

using namespace std;
vector<vector<int> > g;
vector<int> dep;
vector<int> tsr;
vector<int> parent;
vector<int> v;

int dfs(int s)
{
    v[s]=1;
    int i,ret=0;
    for(i=0;i<g[s].size();i++)
    {
        if(v[g[s][i]]==0)
        {
            ret+=1+dfs(g[s][i]);
        }
    }
    //tsr.push_back(s);
    return ret;
}
int main()
{
    int n,i,j,k,m,max_dep,node;
    while(1)
    {
        cin>>n;
        if(n==0) break;
        g.clear();
        v.clear();
        tsr.clear();
        dep.clear();
        parent.clear();
        g.resize(n+1);
        v.resize(n+1);
        dep.resize(n+1);
        parent.resize(n+1);
        for(i=1;i<=n;i++)
        {
            cin>>m;
            for(j=0;j<m;j++)
            {
                cin>>k;
                g[i].push_back(k);
            }
        }
        /*for(i=1;i<=n;i++)
        {
            v[i]=0;
            parent[i]=0;
        }*/
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++) v[j]=0;
            dep[i]=dfs(i);
        }
        /*for(i=1;i<=n;i++)
        {
            for(j=0;j<g[i].size();j++) cout<<g[i][j];
            cout<<endl;
        }*/
        //for(i=0;i<tsr.size();i++) cout<<tsr[i]<<' ';cout<<endl;
        //for(i=1;i<=n;i++) cout<<parent[i]<<' ';
        //dep[tsr[0]]=0;
        //node=tsr[0];
        //max_dep=0;
        //for(i=1;i<=n;i++) dep[i]=0;
        /*for(i=0;i<tsr.size();i++)
        {
            dep[parent[tsr[i]]]++;
        }*/
        //cout<<node<<endl;
        max_dep=dep[1];
        node=1;
        //for(i=1;i<=n;i++) cout<<dep[i]<<' ';
        for(i=2;i<=n;i++)
        {
            if(dep[i]>max_dep)
            {
                max_dep=dep[i];
                node=i;
            }
        }
        cout<<node<<endl;
    }
    return 0;
}


