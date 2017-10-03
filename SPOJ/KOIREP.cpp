//#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<utility>
#include<string>
#define ll long long
#define ull unsigned ll
#define pb push_back
#define mp make_pair
#define ii pair<ll,ll>
#define vi vector<ll>
#define vvi vector<vector<ll> >
#define vvii vector<vector< ii > >
using namespace std;

int fnd[1005];
int Min(int a,int b){return a<b?a:b;}

int main()
{
    int n,m,i,j,k;
    vector<pair<int,int> > vv;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>k;
            vv.push_back(make_pair(k,i));
        }
    }
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    sort(vv.begin(),vv.end());
    int cnt=1,x=0,mn=1000000009;
    fnd[vv[0].second]=1;
    for(i=1;i<vv.size();i++)
    {
        if(vv[i].second==vv[x].second)
        {
            while(x<i && vv[x].second==vv[i].second) fnd[vv[i].second]--,x++;
            if(fnd[vv[i].second]==0) cnt--;
            while(x<i && vv[x].second==vv[x+1].second) fnd[vv[x].second]--,x++;
        }
        fnd[vv[i].second]++;
        if(fnd[vv[i].second]==1) cnt++;
        if(cnt==1)
        {
            x=i;
            fnd[vv[i].second]=1;
        }
        else if(cnt==n)
        {
            /*mn=Min(mn,vv[i].first-vv[x].first);
            fnd[vv[x].second]--;
            if(fnd[vv[x].second]==0) cnt--;
            x++;*/
            //while(x<vv.size()-1 && vv[x].second==vv[x+1].second) fnd[vv[x].second]--,x++;
            while(cnt==n)
            {
                while(x<i && vv[x].second==vv[x+1].second) fnd[vv[x].second]--,x++;
                mn=Min(mn,vv[i].first-vv[x].first);
                fnd[vv[x].second]--;
                if(fnd[vv[x].second]==0) cnt--;
                x++;
            }
        }
    }
    cout<<mn<<endl;
    return 0;
}
