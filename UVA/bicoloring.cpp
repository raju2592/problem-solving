#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<vector<int> > g;
vector<int> v;
vector<int> level;
void bfs(int s)
{
    int i;
    for(i=0;i<v.size();i++) v[i]=0;
    int lv=0;
    v[s]=1;
    level[s]=lv;
    queue<int> q;
    q.push(s);
    int u;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        lv=level[u]+1;
        for(i=0;i<g[u].size();i++)
        {
            if(v[g[u][i]]==0)
            {
                v[g[u][i]]=1;
                level[g[u][i]]=lv;
                q.push(g[u][i]);
            }
        }
    }

}
int main()
{
    int n,m,i,j,k;
    while(1)
    {
        cin>>n;
        if(n==0) break;
        cin>>m;
        g.clear();
        v.clear();
        level.clear();
        g.resize(n);
        v.resize(n);
        level.resize(n);
        for(i=0;i<m;i++)
        {
            cin>>j>>k;
            g[j].push_back(k);
            g[k].push_back(j);
        }

        bfs(0);
        int bip=1;
        for(i=0;i<n;i++)
        {
            for(j=0;j<g[i].size();j++)
            {
                if(level[i]==level[g[i][j]])
                {
                    bip=0;
                    break;
                }
            }
            if(bip==0) break;
        }
        if(bip==0) cout<<"NOT BICOLORABLE.\n";
        else cout<<"BICOLORABLE.\n";
    }
    return 0;
}
