#include<iostream>
#include<istream>
#include<cstring>
#include<string>
using namespace std;
#define ll long long
ll comp(ll *arr)
{
    ll i,j,k,len,tot;
    for(i=0;i<26;i++)
    {
        if(arr[i]!=0) break;
    }
    tot=1;
    len=arr[i]/2;
    for(++i;i<26;i++)
    {
        if(arr[i]==0) continue;
        for(j=1;j<=arr[i]/2;j++)
        {
            tot=(tot*(len+1))/j;
            len++;
        }
    }
    return tot;
}

int main()
{
    ll i,j,k,l,m;
    ll arr[26];
    string s,str;
	//char str[500];
    while(getline(cin,str))
    {
        l=str.size();
        m=0;
        memset(arr,0,sizeof(arr));
        for(i=0;i<l;i++)
        {
            if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z'))
            {
                m++;
                if(str[i]>='A' && str[i]<='Z') arr[str[i]-'A']++;
                else arr[str[i]-'a']++;
            }
        }
        if(m==0)
        {
            cout<<1<<endl;
            continue;
        }
        if(m%2==0)
        {
            bool f=true;
            for(i=0;i<26;i++)
            {
                if(arr[i]%2==1)
                {
                    f=false;
                    break;
                }
            }
            if(f)
            {
                cout<<comp(arr)<<endl;
            }
            else cout<<0<<endl;
        }
        else
        {
            ll odd=0;
            for(i=0;i<26;i++)
            {
                if(arr[i]%2==1) odd++;;
            }
            if(odd!=1) cout<<0<<endl;
            else cout<<comp(arr)<<endl;
        }
    }
    return 0;
}
