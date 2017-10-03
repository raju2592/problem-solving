#include<iostream>
#include<vector>
#include<cstring>
#define ll long long
using namespace std;
vector<vector<ll> > gr;
int main()
{
    ll in[1005],n,m,i,j,k;
    cin>>n>>m;
    gr.resize(n+1);
    memset(in,0,sizeof(in));
    for(i=1;i<=m;i++)
    {
        cin>>j>>k;
        gr[j].push_back(k);
        in[k]++;
    }
    for(i=1;i<=n;i++)
    {
        cin>>j;
        if(in[j]!=0)
        {
            cout<<"NO";
            goto ret;
        }
        else
        {
            for(k=0;k<gr[j].size();k++) in[gr[j][k]]--;
        }
    }
    cout<<"YES";
    ret: return 0;
}
