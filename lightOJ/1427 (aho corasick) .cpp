#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<iostream>
#define MAX 500*500+10
using namespace std;

char st[505],txt[1000006];

int no_state;
int go[MAX][26];
int fail[MAX];
vector<int> out[MAX];
int cnt[MAX];
int ans[600]; // contains output value

void constructGoto(int n)
{
    int i,j,k,len,state;
    memset(go,-1,sizeof(go));
    for(i=0;i<MAX;i++) out[i].clear();
    no_state=0;
    for(i=1;i<=n;i++)
    {
        scanf("%s",st);
        len=strlen(st);

        /** insert new string into trie */
        state=0;
        for(j=0;j<len && go[state][st[j]-'a']!=-1;j++) state=go[state][st[j]-'a'];
        while(j<len)
        {
            no_state=no_state+1;
            go[state][st[j]-'a']=no_state;
            state=no_state;
            j++;
        }
        out[state].push_back(i);
    }
    /**other transitions for state zero **/
    for(i=0;i<26;i++) if(go[0][i]==-1) go[0][i]=0;
}

void computeFailure()
{
    int i,j,k;
    queue<int> q;
    for(i=0;i<26;i++)
    {
        if(go[0][i]!=0)
        {
            q.push(go[0][i]);
            fail[go[0][i]]=0;
        }
    }
    while(!q.empty())
    {
        k=q.front();
        q.pop();
        for(i=0;i<26;i++)
        {
            if(go[k][i]!=-1)
            {
                q.push(go[k][i]);
                int state=fail[k];
                while(go[state][i]==-1) state=fail[state];
                fail[go[k][i]]=go[state][i];
                for(j=0;j<out[go[state][i]].size();j++)
                {
                    out[go[k][i]].push_back(out[go[state][i]][j]);
                }
            }
        }
    }
}

void searchText(char *txt)
{
    int i,j,k,len,state;
    memset(cnt,0,sizeof(cnt));
    len=strlen(txt);
    state=0;
    for(i=0;i<len;i++)
    {
        while(go[state][txt[i]-'a']==-1) state=fail[state];
        state=go[state][txt[i]-'a'];
        cnt[state]++;
    }
}

int main()
{
    int t,cs=0,i,j,k,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d\n",&n);
        scanf("%s",txt);

        constructGoto(n);
        computeFailure();
        searchText(txt);

        /** calculate output */
        memset(ans,0,sizeof(ans));
        for(i=1;i<=no_state;i++)
        {
            for(j=0;j<out[i].size();j++) ans[out[i][j]]+=cnt[i];
        }

        printf("Case %d:\n",++cs);
        for(i=1;i<=n;i++) printf("%d\n",ans[i]);
    }
    return 0;
}
