#include<iostream>
#include<vector>
#define ll long long
using namespace std;

vector<int> ter,ans;

void convert(int n)
{
    while(n)
    {
        ter.push_back(n%3);
        n/=3;
    }
}
ll convert()
{
    ll ret=0,pw=1;
    for(int i=0;i<ans.size();i++)
    {
        ret+=ans[i]*pw;
        pw*=3;
    }
    return ret;
}
int main()
{
    int n,i,j;
    cin>>n;
    convert(n);
    ter.push_back(0);
    bool diff=false;
    for(i=0;i<ter.size();i++)
    {
        if(ter[i]==0 && i!=ter.size()-1) ans.push_back(0);
        else if(ter[i]==1) ans.push_back(1);
        else if(ter[i]==2)
        {
            ans.push_back(0);
            ter[i+1]+=1;
            diff=true;
        }
        else if(ter[i]==3)
        {
            ans.push_back(0);
            ter[i+1]+=1;
        }
    }
    if(!diff) ans.push_back(1);
    int k=convert();
    cout<<k<<' '<<k-n;
    return 0;
}
