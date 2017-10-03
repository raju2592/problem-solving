#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<vector>
#define INF 200000000
using namespace std;

int ex[20],n,N;
string ss[20];
int cmn[20][20];
vector<int> arr;
int pi[20][1005];
int dp[1<<15][17],ch[1<<15][17];
string ans;

pair<int,int> calc(int mask,int prev);

void cpf(int a)
{
    int i,k;
    pi[a][0]=0;
	k=0;
    for(i=1;i<ss[a].size();i++)
    {
        while(k && ss[a][i]!=ss[a][k]) k=pi[a][k-1];
        if(ss[a][i]==ss[a][k]) k++;
        pi[a][i]=k;
    }
}

void kmp(int a,int b)
{
    int i,k=0;
    for(i=0;i<ss[a].size();i++)
    {
        while(k && ss[a][i]!=ss[b][k]) k=pi[b][k-1];
        if(ss[a][i]==ss[b][k]) k++;
        if(i==ss[a].size()-1) cmn[a][b]=k;
        if(k==ss[b].size())
        {
            ex[b]=1;
            k=pi[b][k];
        }
    }
}

bool comp(int mask1,int mask2,int a,int b,int i,int j)
{
    if(mask1==(1<<N)-1) return true;
    int x,y;
    for(x=i,y=j;x<ss[arr[a]].size() && y<ss[arr[b]].size();x++,y++)
    {
        if(ss[arr[a]][x]!=ss[arr[b]][y]) return ss[arr[a]][x]<ss[arr[b]][y];
    }
    if(x==ss[arr[a]].size())
    {
        pair<int,int> xx=calc(mask1 | (1<<a),a);
        return comp(mask1 | (1<<a),mask2,xx.second,b,cmn[arr[a]][arr[xx.second]],y);
    }
    else if(y==ss[arr[b]].size())
    {
        pair<int,int> xx=calc(mask2 | (1<<b),b);
        return comp(mask1,mask2  | (1<<b),a,xx.second,x,cmn[arr[b]][arr[xx.second]]);
    }
}


pair<int,int> calc(int mask,int prev)
{
    if(dp[mask][prev]!=-1) return make_pair(dp[mask][prev],ch[mask][prev]);
    if(mask==(1<<N)-1) return make_pair(0,15);
    int a=INF,b;
    pair<int,int> xx;
    for(int i=0;i<N;i++)
    {
        if((mask & (1<<i))==0)
        {
            xx=calc( mask | (1<<i),i);
            if(xx.first+ss[arr[i]].size()-cmn[arr[prev]][arr[i]]<a)
            {
                a=xx.first+ss[arr[i]].size()-cmn[arr[prev]][arr[i]];
                b=i;
            }
            else if(xx.first+ss[arr[i]].size()-cmn[arr[prev]][arr[i]]==a)
            {
				//cout<<cmn[arr[prev]][arr[b]]<<" "<<
                if(!comp(mask,mask,b,i,cmn[arr[prev]][arr[b]],cmn[arr[prev]][arr[i]])) b=i;
            }
        }
    }
    dp[mask][prev]=a;ch[mask][prev]=b;
    return make_pair(a,b);
}
void find_ans(int mask,int prev)
{
    if(mask==(1<<N)-1) return;
    int x=calc(mask,prev).second;
    for(int i=cmn[arr[prev]][arr[x]];i<ss[arr[x]].size();i++) ans+=ss[arr[x]][i];
    find_ans(mask | (1<<x),x);
}
int main()
{
    int t,cs=1,i,j,k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++) cin>>ss[i];
        for(i=0;i<n;i++) cpf(i);
        memset(ex,0,sizeof(ex));
        memset(cmn,0,sizeof(cmn));
        for(i=0;i<n;i++)
        {
            if(ex[i]) continue;
            for(j=0;j<n;j++)
            {
                if(i==j) continue;
                kmp(i,j);
            }
        }
        /*for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++) cout<<cmn[i][j]<<" ";
            cout<<endl;
        }*/
        arr.clear();
        for(i=0;i<n;i++) if(!ex[i]) arr.push_back(i);
        N=arr.size();
        arr.push_back(15);
        memset(dp,-1,sizeof(dp));
        pair<int,int> ret=calc(0,N);
        printf("Case %d: ",cs++);
        ans="";
        find_ans(0,N);
        cout<<ans<<endl;
    }
    return 0;
}
/*
1
4
ABC BCD BCKR KRO
*/
/*
1
4
ABC BCKR KRO BCD
*/
