#include<iostream>
#include<stack>
using namespace std;

int n;
pair<int,int> arr[100005];
stack<int> st;
int cur;

void calc(int j)
{
    int x=st.top();
    if(cur>n)
    {
        cout<<x<<endl;
        return;
    }
    /*if(arr[cur].first<=j && arr[cur].second>=j)
    {
        st.push(cur);
        cur++;
        calc(j);
    }*/
    //else
    //{
    while(arr[cur].second<j && arr[cur].second<=arr[x].second && cur<=n) cur++;
    if(cur>n)
    {
        cout<<x<<endl;
        return;
    }
    if(arr[cur].first>j)
    {
        cout<<x<<endl;
        return;
    }
    else if(arr[cur].first<=j && arr[cur].second>=j)
    {
        st.push(cur);
        cur++;
        calc(j);
    }
    else if(arr[cur].first>arr[x].second) cout<<x<<endl;
    //}
}

int main()
{
    int i,j,k,m;
    cin>>n;
    for(i=1;i<=n;i++) cin>>arr[i].first>>arr[i].second;
    cin>>m;
    bool found;
    cur=1;
    for(i=0;i<m;i++)
    {
        cin>>j;
        while(!st.empty())
        {
            int x=st.top();
            if(!(arr[x].first<=j && arr[x].second>=j)) st.pop();
            else break;
        }
        if(st.empty())
        {
            while(arr[cur].second<j && cur<=n) cur++;
            if(cur>n) cout<<-1<<endl;
            else if(arr[cur].first>j) cout<<-1<<endl;
            else
            {
                st.push(cur);
                cur++;
                calc(j);
            }
        }
        else calc(j);
    }
    return 0;
}
