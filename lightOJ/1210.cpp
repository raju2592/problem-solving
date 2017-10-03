#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int> > gr,gr_rev;
vector<int> v,comp,aft;
int max(int i,int j) {return i>j?i:j;}
void dfs(vector<vector<int> > &gr,int n,int push,int cn=0)
{
    v[n]=1;
    for(int i=0;i<gr[n].size();i++)
    {
        if(v[gr[n][i]]==0) dfs(gr,gr[n][i],push,cn);
    }
    if(push) aft.push_back(n);
    else comp[n]=cn;
}
int main()
{
    int t,i,j,k,n,m,cn;
    scanf("%d",&t);
    for(int c=1;c<=t;c++)
    {
        scanf("%d %d",&n,&m);
        gr.clear();
        gr.resize(n+1);
        gr_rev.clear();
        gr_rev.resize(n+1);
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&j,&k);
            gr[j].push_back(k);
            gr_rev[k].push_back(j);
        }
        aft.clear();
        v.clear();
        v.resize(n+1);
        for(i=1;i<=n;i++) v[i]=0;
        for(i=1;i<=n;i++) if(v[i]==0) dfs(gr_rev,i,1);
        for(i=1;i<=n;i++) v[i]=0;
        cn=0;
        comp.clear();
        comp.resize(n+1);
        for(i=aft.size()-1;i>=0;i--)
        {
            if(v[aft[i]]==0)
            {
                cn++;
                dfs(gr,aft[i],0,cn);
            }
        }
        vector<int> in,out;
        in.resize(cn+1);
        out.resize(cn+1);
        for(i=1;i<=cn;i++) in[i]=out[i]=0;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<gr[i].size();j++)
            {
                if(comp[i]!=comp[gr[i][j]])
                {
                    out[comp[i]]++;
                    in[comp[gr[i][j]]]++;
                }
            }
        }
        int inz=0,ouz=0,btz=0;
        for(i=1;i<=cn;i++)
        {
            if(in[i]==0 && out[i]==0) btz++;
            else if(in[i]==0 && out[i]!=0) inz++;
            else if(in[i]!=0 && out[i]==0) ouz++;
        }
        int ans;
        if(cn>1)ans=max(inz+btz,ouz+btz);
        else ans=0;
        printf("Case %d: %d\n",c,ans);
    }
    return 0;
}
