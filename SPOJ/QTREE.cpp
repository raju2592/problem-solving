#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define MAXN 10000
#define fs first
#define sc second
using namespace std;

int n;
vector<vector<int> > gr,wt,idx;
#define root 1

/// hc[i]=no of the heaviest child of node i
/// hcst[i]=cost of the edge connecting node i to its heaviest child
int hc[MAXN+5],hcst[MAXN+5];
int height[MAXN+5];
int tail[MAXN+5],par[MAXN+5]; /// tail[i]=tail of edge i
int base[MAXN+5]; ///base[i]=cost of the edge connecting node i to its parent

int cc; /// chain count
int cn[MAXN+5] ; ///cn[i]=chain no of node i;
int ch[MAXN+5]; /// ch[i]= node at the head of the chain no i
int pb[MAXN+5]; ///pb[i]=position of node i in base array
int ptr; ///pointer in the base array;

int tree[4*MAXN];


int update_tree(int node,int b,int e,int i,int v)
{
    //cout<<b<<" "<<e<<endl;
    if(i<b || i>e) return tree[node];
    if(b==e) return tree[node]=v;
    int l=update_tree(node*2,b,(b+e)/2,i,v);
    int r=update_tree(node*2+1,(b+e)/2+1,e,i,v);
    return tree[node]=max(l,r);
}

int read_tree(int node,int b,int e,int i,int j)
{
    //cout<<b<<" "<<e<<i<<j<<endl;
    if(j<i) return -1;
    if(j<b || i>e) return -1;
    if(b>=i && e<=j) return tree[node];
    int l=read_tree(node*2,b,(b+e)/2,i,j);
    int r=read_tree(node*2+1,(b+e)/2+1,e,i,j);
    return max(l,r);
}

int dfs(int node)
{
    //cout<<node<<endl;
    int hcno=-1,hcsz=0,cst;
    int sz=1; ///size of subtree rooted at node
    for(int i=0;i<gr[node].size();i++)
    {
        if(gr[node][i]!=par[node])
        {
            //cout<<"hu";
            par[gr[node][i]]=node;
            height[gr[node][i]]=height[node]+1;
            tail[idx[node][i]]=gr[node][i];
            int k=dfs(gr[node][i]);
            if(k>hcsz) hcsz=k,hcno=gr[node][i],cst=wt[node][i];
            sz+=k;
        }
    }
    hc[node]=hcno;hcst[node]=cst;
    return sz;
}

void hld(int node,int cst)
{
    //cout<<node<<" "<<cst<<endl;
    cn[node]=cc;
    pb[node]=ptr;
    base[ptr]=cst;
    ptr++;
    if(hc[node]!=-1) hld(hc[node],hcst[node]);
    for(int i=0;i<gr[node].size();i++)
    {
        if(gr[node][i]!=par[node] && gr[node][i]!=hc[node])
        {
            //if(node==3) cout<<gr[node][i]<<endl;
            cc++;
            ch[cc]=gr[node][i];
            hld(gr[node][i],wt[node][i]);
        }
    }

}

pair<int,int> get_up(int node)
{
    if(node==root) return mp(root,-1);
    int p=par[node];
    if(cn[node]==cn[p])
    {
        int x=ch[cn[p]];
        int y=read_tree(1,1,n,pb[x]+1,pb[node]);
        return mp(x,y);
    }
    int x=read_tree(1,1,n,pb[node],pb[node]);
    return mp(p,x);
}
int query_hld(int a,int b)
{
    //cout<<a<<b<<endl;
    int ret=-1;
    while(cn[a]!=cn[b])
    {
        //cout<<a<<" "<<b<<" ";
        //cout<<"dhukse";
        pair<int,int> p=get_up(a),q=get_up(b);
        //cout<<p.fs<<" "<<q.fs<<endl;
        if(height[p.fs]>height[q.fs])
        {
            ret=max(ret,p.sc);
            a=p.fs;
        }
        else if(height[q.fs]>height[p.fs])
        {
            ret=max(ret,q.sc);
            b=q.fs;
        }
        else
        {
            ret=max(ret,p.sc);
            a=p.fs;
            ret=max(ret,q.sc);
            b=q.fs;
        }
    }
    if(height[b]<height[a]) swap(a,b);
    //cout<<a<<" "<<b<<" "<<pb[a]<<" "<<pb[b]<<endl;
    int k=read_tree(1,1,n,pb[a]+1,pb[b]);
    //cout<<k<<endl;
    ret=max(k,ret);
    return ret;
}
int main()
{
    int t;
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);

        gr.clear();wt.clear();idx.clear();
        gr.resize(n+1);wt.resize(n+1);idx.resize(n+1);
        for(int i=1;i<n;i++)
        {
            int j,k,l;
            scanf("%d %d %d",&j,&k,&l);
            gr[j].pb(k);gr[k].pb(j);
            wt[j].pb(l);wt[k].pb(l);
            idx[j].pb(i);idx[k].pb(i);
            //cout<<"ok";
        }
        //cout<<"oka";
        par[root]=-1,height[root]=0; /// root 1

        dfs(root);
        //cout<<"ok";
        //for(int i=1;i<=n;i++) cout<<hc[i]<<" ";
        cc=1;ptr=1;
        ch[1]=root; /// root is the head of 1st chain
        hld(root,-1);



        for(int i=1;i<=n;i++) update_tree(1,1,n,i,base[i]);
        //cout<<ptr<<endl;
        //cout<<base[1]<<base[2]<<base[3];
        while(1)
        {
            char str[10];
            int p,q;
            scanf("%s",str);
            //cout<<str;
            if(str[0]=='D') break;
            scanf("%d %d",&p,&q);
            if(str[0]=='C')
            {
                //cout<<"QQ\n";
                update_tree(1,1,n,pb[tail[p]],q);
            }
            else printf("%d\n",query_hld(p,q));
        }
        //cout<<"done\n";

    }
    return 0;
}
