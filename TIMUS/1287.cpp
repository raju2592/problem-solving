#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int val[2][4][1500];
char arr[1500][1500];
int  gettype(char s)
{
    if(s=='s') return 0;
    else return 1;
}
void settyp(int &typ,int &ans,int k,int i,int j)
{
    if(k>ans)
    {
        ans=k;
        typ=gettype(arr[i][j]);
    }
    else if(k==ans)
    {
        if(typ!=2 && typ!=gettype(arr[i][j])) typ=2;
    }
}
int main()
{
    int i,j,k,n;
    int ans,typ,cur,prev;
    scanf("%d\n",&n);
    for(i=0;i<n;i++) scanf("%s",arr[i]);
    prev=0;
    cur=1;
    for(i=0;i<4;i++) val[prev][i][0]=1;
    ans=1,typ=gettype(arr[0][0]);
    for(i=1;i<n;i++)
    {
        k=val[prev][1][i]=val[prev][2][i]=val[prev][3][i]=1;
        settyp(typ,ans,k,0,i);
        if(arr[0][i]==arr[0][i-1]) k=val[prev][0][i]=val[prev][0][i-1]+1;
        else k=val[prev][0][i]=1;
        settyp(typ,ans,k,0,i);
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(j-1>=0)
            {
                if(arr[i][j]==arr[i][j-1]) k=val[cur][0][j]=val[cur][0][j-1]+1;
                else k=val[cur][0][j]=1;
            }
            else k=val[cur][0][j]=1;
            settyp(typ,ans,k,i,j);
            if(i-1>=0)
            {
                if(arr[i][j]==arr[i-1][j]) k=val[cur][1][j]=val[prev][1][j]+1;
                else k=val[cur][1][j]=1;
            }
            else k=val[cur][1][j]=1;
            settyp(typ,ans,k,i,j);
            if(i-1>=0 && j-1>=0)
            {
                if(arr[i][j]==arr[i-1][j-1]) k=val[cur][2][j]=val[prev][2][j-1]+1;
                else k=val[cur][2][j]=1;
            }
            else k=val[cur][2][j]=1;
            settyp(typ,ans,k,i,j);
            if(i-1>=0 && j+1<n)
            {
                if(arr[i][j]==arr[i-1][j+1]) k=val[cur][3][j]=val[prev][3][j+1]+1;
                else k=val[cur][3][j]=1;
            }
            else k=val[cur][3][j]=1;
            settyp(typ,ans,k,i,j);
        }
        swap(cur,prev);
    }
    if(typ==0) cout<<"s\n";
    else if(typ==1) cout<<"S\n";
    else cout<<"?\n";
    cout<<ans<<endl;
    return 0;
}
