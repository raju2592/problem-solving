#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int main()
{
    int n,arr[50],i,j,k;
    multiset<int> st;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>j;
        st.insert(j);
    }
    set<int>::iterator it;
    int ans=0;
    while(!st.empty())
    {
        k=*(st.begin());
        st.erase(st.begin());
        it=st.find(k+1);
        if(it!=st.end())
        {
            st.erase(it);
        }
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
