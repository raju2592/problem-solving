#include<iostream>
#include<queue>
#include<utility>
#include<vector>
#define  max(i,j) i>j?i:j

using namespace std;

enum color{red,blue};

vector<vector<int> > g;
vector<int> v;
vector<color> clr;
vector<pair<int,int> > clrcc;
vector<vector<int> > cc;

void bfs(int s,int no_cc)
{
    int i,u;
    int r,b;
    color c;
    v[s]=1;
    clr[s]=red;
    cc[no_cc].push_back(s);
    r=0;
    b=0;
    r++;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        if(clr[u]==red) c=blue;
        else c=red;
        for(i=0;i<g[u].size();i++)
        {
            if(v[g[u][i]]==0)
            {

                v[g[u][i]]=1;
                clr[g[u][i]]=c;
                cc[no_cc].push_back(g[u][i]);
                q.push(g[u][i]);
                if(c==red) r++;
                else b++;
            }
        }
    }
    clrcc[no_cc].first=r;
    clrcc[no_cc].second=b;
}
int main()
{
    int t,n,m,i,j,k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        g.clear();
        v.clear();
        clr.clear();
        g.resize(n+1);
        v.resize(n+1);
        clr.resize(n+1);
        for(i=1;i<=n;i++)
        {
            cin>>m;
            for(j=0;j<m;j++)
            {
                cin>>k;
                if(k>n) continue;
                g[i].push_back(k);
                g[k].push_back(i);
            }
        }
        cc.clear();
        clrcc.clear();
        //cout<<cc.size()<<clrcc.size();
        int no_cc=1;
        for(i=0;i<v.size();i++) v[i]=0;
        for(i=1;i<=n;i++)
        {
            if(v[i]==0)
            {
                cc.resize(no_cc);
                clrcc.resize(no_cc);
                bfs(i,no_cc-1);
				no_cc++;
            }

        }

        int ans=0,bip;
        for(i=0;i<cc.size();i++)
        {
            bip=1;
            for(j=0;j<cc[i].size();j++)
            {
                for(k=0;k<g[cc[i][j]].size();k++)
                {
                    if(clr[cc[i][j]]==clr[g[cc[i][j]][k]])
                    {
                        bip=0;
                        break;
                    }
                }
                if(bip==0) break;
            }
            if(bip==1) ans+=max(clrcc[i].first,clrcc[i].second);
        }
        cout<<ans<<endl;

    }
    return 0;
}
