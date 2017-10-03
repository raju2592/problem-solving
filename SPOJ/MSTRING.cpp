#include<iostream>
#include<cstring>
using namespace std;
#define ll long
ll Max(ll i,ll j){return i>j?i:j;}
ll nxt_oc[26][1005],dp[2][1005],*prev,*cur,*tmp;
int main()
{
    ll i,j,k,fi[26],pr[26],lv,lt;
    char v[1005],t[1005];
    cin>>v>>t;
    lv=strlen(v);
    lt=strlen(t);
    memset(fi,-1,sizeof(fi));
    for(i=0,j=0;i<lt && j<26;i++)
    {
        if(fi[t[i]-'a']==-1)
        {
            fi[t[i]-'a']=i;
            j++;
        }
    }
    memset(nxt_oc,-1,sizeof(nxt_oc));
    memset(pr,0,sizeof(pr));
    for(i=0;i<lt;i++)
    {

            for(j=pr[t[i]-'a'];j<i;j++)
			{
				nxt_oc[t[i]-'a'][j]=i;
			}
            pr[t[i]-'a']=i;


    }
    prev=dp[0];
    cur=dp[1];
    for(i=0;i<lv;i++)
    {
        if(fi[v[i]-'a']==-1)
        {
            cout<<1<<endl;
            goto ret;
        }
        else
        {
            if(i!=0) prev[i]=Max(fi[v[i]-'a'],prev[i-1]);
            else prev[i]=fi[v[i]-'a'];
        }
    }
    for(i=2;i<=lv;i++)
    {
        cur[i-2]=-1;
        for(j=i-1;j<lv;j++)
        {
            if(nxt_oc[v[j]-'a'][prev[j-1]]==-1)
            {
                cout<<i<<endl;
                goto ret;
            }
            else cur[j]=Max(nxt_oc[v[j]-'a'][prev[j-1]],cur[j-1]);
        }
        tmp=prev;
        prev=cur;
        cur=tmp;
    }
    ret: return 0;
}
