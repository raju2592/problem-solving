#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;
vector<vector<int> > gr;
vector<int> v,aft;
int isin[26];
void dfs(int n)
{
    v[n]=1;
    for(int i=0;i<gr[n].size();i++)
    {
        if(v[gr[n][i]]==0) dfs(gr[n][i]);
    }
    aft.push_back(n);
}
int main()
{
    int i,j,k,l;
    char str[50],prev[50];
    memset(isin,0,sizeof(isin));
    gets(prev);
    for(i=0;i<strlen(prev);i++) isin[prev[i]-'A']=1;
    gr.resize(26);
    while(1)
    {
        gets(str);
        if(!strcmp("#",str)) break;
        for(i=0;i<strlen(str);i++) isin[str[i]-'A']=1;
        k=strlen(prev);
        l=strlen(str);
        for(i=0;i<k && i<l;i++)
        {
            if(prev[i]!=str[i])
            {
                gr[prev[i]-'A'].push_back(str[i]-'A');
                break;
            }
        }
        strcpy(prev,str);
    }
    v.resize(26);
    for(i=0;i<26;i++) v[i]=0;
    for(i=0;i<26;i++)
    {
        if(isin[i] && v[i]==0) dfs(i);
    }
    for(i=aft.size()-1;i>=0;i--) printf("%c",aft[i]+'A');
    cout<<endl;
    return 0;
}
