#include<bits/stdc++.h>
#define MAX 50000
using namespace std;

int sa[MAX+10];
int bucket[MAX+10],nBucket[MAX+10];
int first[MAX+10];
int cnt[MAX+10];
int B[MAX+10];
int rank[MAX+10],LCP[MAX+10];
int H;

int n;
string ss;

bool cmp(int i,int j)
{
    if(H==0) return ss[i]<ss[j];
    if(bucket[i]!=bucket[j]) return bucket[i]<bucket[j];
    return (i+H<n && j+H<n) ? bucket[i+H]<bucket[j+H] : i>j;
}

bool equal(int i,int j)
{
    return !cmp(i,j) && !cmp(j,i);
}

void update_bucket()
{
    int id=1,i;
    first[sa[0]]=0;
    nBucket[sa[0]]=id;
    for(i=1;i<n;i++)
    {
        if(!equal(sa[i],sa[i-1]))
        {
            id++;
            first[sa[i]]=i;
        }
        else first[sa[i]]=first[sa[i-1]];
        nBucket[sa[i]]=id;
    }
    for(i=0;i<n;i++) bucket[i]=nBucket[i];
}

void radix_sort()
{
    int i,x,y;
    memset(cnt,0,sizeof(cnt));
    for(i=n-1;i>=n-H;i--)
    {
        B[first[i]]=i;
        cnt[first[i]]++;
    }
    for(i=0;i<n;i++)
    {
        x=sa[i]-H;
        if(x<0) continue;
        y=first[x];
        B[y+cnt[y]]=x;
        cnt[y]++;
    }
    for(i=0;i<n;i++) sa[i]=B[i];
}
void suffix_array()
{
    int i,j,k;
    H=0;
    for(i=0;i<n;i++) sa[i]=i;
    sort(sa,sa+n,cmp);
    update_bucket();
    for(H=1;H<n;H*=2)
    {
        radix_sort();
        update_bucket();
    }
}
void computeLCP()
{
    int i,j,k;
    for(i=0;i<n;i++) rank[sa[i]]=i;
    LCP[0]=0;
    k=0;
    for(i=0;i<n;i++)
    {
        j=rank[i];
        if(j==0) continue;
        j=sa[j-1];
        while(i+k<n && j+k<n && ss[i+k]==ss[j+k]) k++;
        LCP[rank[i]]=k;
        if(k) k--;
    }
}

int main()
{
    int t,cs=0,i,j,k,p,q,ans;
    cin>>t;
    while(t--)
    {
        cin>>ss>>p>>q;
        n=ss.size();
        suffix_array();
        computeLCP();
        ans=0;
        for(i=0;i<n;i++)
        {
            k=min(n-sa[i],q);
            j=max(LCP[i]+1,p);
            if(j>k) continue;
            ans+=k-j+1;
        }
        printf("Case %d: %d\n",++cs,ans);
    }
    return 0;
}
