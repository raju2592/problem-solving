#include<iostream>
using namespace std;
void print_ans(int *arr,int l,int r)
{
    int i,j,p=arr[r];
    if(l==r)
    {
        cout<<arr[l]<<' ';
        return;
    }
    for(i=l;arr[i]<p;i++);
    if(i!=r) print_ans(arr,i,r-1);
    if(i!=l) print_ans(arr,l,i-1);
    cout<<arr[r]<<' ';
}
int main()
{
    int n,arr[3005],i,j,k;
    cin>>n;
    for(i=1;i<=n;i++) cin>>arr[i];
    print_ans(arr,1,n);
    return 0;
}
