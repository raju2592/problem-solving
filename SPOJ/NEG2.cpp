#include<iostream>
#include<vector>
using namespace std;
void div(long &n,long &k)
{
    if(n>0)
    {
        k=n%2;
        n=-(n/2);
    }
    else
    {
        k=(-n)%2;
        if(k) n=(-n)/2+1;
        else n=(-n)/2;
    }
}
int main()
{
    long i,j,k,n;
    vector<int> v;
    cin>>n;
    if(n==0)
    {
        cout<<0;return 0;
    }
    while(n)
    {
        div(n,k);
        v.push_back(k);
    }
    for(i=v.size()-1;i>=0;i--) cout<<v[i];
    cout<<endl;
    return 0;
}
