#include<iostream>
#include<utility>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
vector<vector<pair<ll,ll> > > gr;
int main()
{
    ll t,n,i,j,k,l;
    cin>>t;
    for(ll c=1;c<=t;c++)
    {
        cin>>n;
        gr.clear();
        gr.resize(n+1);
        for(i=1;i<=n;i++)
        {
            cin>>j>>k>>l;
            gr[j].push_back(make_pair(k,0));
            gr[k].push_back(make_pair(j,l));
        }
        ll c1,c2;
        c1=gr[1][0].second;
        ll cur=gr[1][0].first,prev=1;
        while(cur!=1)
        {
            if(gr[cur][0].first==prev)
            {
                c1+=gr[cur][1].second;
                prev=cur;
                cur=gr[cur][1].first;
            }
            else
            {
                c1+=gr[cur][0].second;
                prev=cur;
                cur=gr[cur][0].first;
            }
        }
        c2=gr[1][1].second;
        cur=gr[1][1].first,prev=1;
        while(cur!=1)
        {
            if(gr[cur][0].first==prev)
            {
                c2+=gr[cur][1].second;
                prev=cur;
                cur=gr[cur][1].first;
            }
            else
            {
                c2+=gr[cur][0].second;
                prev=cur;
                cur=gr[cur][0].first;
            }
        }
        printf("Case %lld: %lld\n",c,c1<c2?c1:c2);
    }
    return 0;
}
