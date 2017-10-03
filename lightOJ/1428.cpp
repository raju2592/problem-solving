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

int n,m;
string ss,sb;
int pi[50005];
int ocr[50005];
int next[50005];

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

void prefixFunc(string &p)
{
    int i,j,k,m;
    m=p.size();
    k=0;
    pi[1]=0;
    for(i=1;i<m;i++)
    {
        while(k && p[i]!=p[k]) k=pi[k];
        if(p[i]==p[k]) k++;
        pi[i+1]=k;
    }
}

void KMPmatch()
{
    int i,j,k=0;
    for(i=0;i<n;i++)
    {
        while(k && ss[i]!=sb[k]) k=pi[k];
        if(ss[i]==sb[k]) k++;
        if(k==m)
        {
            ocr[i-m+1]=1;
            k=pi[k];
        }
    }
}
void findnext()
{
    next[n]=n;
    for(int i=n-1;i>=0;i--)
    {
        if(ocr[i]) next[i]=i;
        else next[i]=next[i+1];
    }
}
int main()
{
    int t,cs=0,i,j,k,a,b,c;
    long long ans;
    cin>>t;
    while(t--)
    {
        cin>>ss>>sb;
        n=ss.size();
        m=sb.size();
        prefixFunc(sb);
        memset(ocr,0,sizeof(ocr));
        KMPmatch();
        findnext();
        suffix_array();
        computeLCP();
        ans=0;
        for(i=0;i<n;i++)
        {
            a=sa[i];
            b=next[a];
            c=LCP[i];
            if(b==n) a=n-a;
            else a=b+m-1-a;
            if(c<a) ans+=a-c;
        }
        //for(i=0;i<n;i++) cout<<next[i]<<endl;
        printf("Case %d: %lld\n",++cs,ans);
    }

}
