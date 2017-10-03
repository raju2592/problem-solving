#include<iostream>
#include<vector>

using namespace std;
int in[100005];
vector<vector<int> > gr;
vector<int> v,d;
vector<int> cy;
void dfs(int n)
{
    v[n]=1;
    for(int i=0;i<gr[n].size();i++)
    {
        if(v[gr[n][i]]==0)
        {
            d[gr[n][i]]=d[n]+1;
            dfs(gr[n][i]);
        }
        else if(v[gr[n][i]]==1)
        {
            cy.push_back(d[n]+1-d[gr[n][i]]);
        }
    }
    v[n]=2;
}
int main()
{
    int i,j,k,l,mx,mn,n;
    cin>>n;
    gr.resize(n+1);
    for(i=1;i<=n;i++)
    {
        cin>>j;
        if(i==j) continue;
        gr[i].push_back(j);
        in[j]++;
    }
    mn=0;
    v.resize(n+1);
    d.resize(n+1);
    for(i=1;i<=n;i++) v[i]=0,d[i]=-1;;
    for(i=1;i<=n;i++)
    {
        if(in[i]==0)
        {
            d[i]=0;
            mn++;
            dfs(i);
        }
    }
    for(i=1;i<=n;i++)
    {
        if(v[i]==0)
        {
            d[i]=0;
            mn++;
            dfs(i);
        }
    }
    mx=cy.size();
    mx+=n;
    for(i=0;i<cy.size();i++) mx-=cy[i];
    cout<<mn<<' '<<mx;
    cout<<endl;
    return 0;
}
