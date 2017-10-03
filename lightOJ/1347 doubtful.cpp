#include<bits/stdc++.h>
#define MAX 50000
#define INF 50000
using namespace std;

int sa[MAX+10];
int bucket[MAX+10],nBucket[MAX+10];
int first[MAX+10];
int cnt[MAX+10];
int B[MAX+10];
int rank[MAX+10],LCP[MAX+10];
int H;

int n,a,b,c;
string ssa,ssb,ssc,ss;

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

int get(int x)
{
    if(x>=a+b) return 2;
    if(x>=a) return 1;
    return 0;
}
void adjustLCP()
{
    int i,j,k,prev,cur;
    prev=get(sa[0]);
    for(i=1;i<n;i++)
    {
        cur=get(sa[i]);
        if(prev!=2 || cur!=2)
        {
            int x,y;
            if(prev==0) x=a-sa[i-1];
            else if(prev==1) x=a+b-sa[i-1];
            else x=a+b+c-sa[i-1];
            if(cur==0) y=a-sa[i];
            else if(cur==1) x=a+b-sa[i];
            else x=a+b+c-sa[i];
            LCP[i]=min(LCP[i],min(x,y));
        }
        prev=cur;
    }
}
int main()
{
    int t,cs=0,i,j,k,p,q,ans,cnt,mn;
    int fnd[3],cur;
    cin>>t;
    while(t--)
    {
        cin>>ssa>>ssb>>ssc;
        a=ssa.size();b=ssb.size();c=ssc.size();
        ss=ssa+ssb+ssc;
        n=a+b+c;
        suffix_array();
        computeLCP();
        adjustLCP();
        ans=0;
        cnt=0;
        mn=INF;
        fnd[0]=fnd[1]=fnd[2]=0;
        fnd[get(sa[0])]=1;
        cnt++;
        cur=get(sa[0]);
        for(i=1;i<n;i++)
        {
            if(get(sa[i])==cur)
            {
                if(cnt==2) mn=min(mn,LCP[i]);
                else mn=INF;
            }
            else
            {
                if(cnt==1)
                {
                    cnt++;
                    fnd[get(sa[i])]=1;
                    cur=get(sa[i]);
                    mn=min(mn,LCP[i]);
                }
                else
                {
                    if(fnd[get(sa[i])])
                    {
                        cur=get(sa[i]);
                        mn=LCP[i];
                    }
                    else
                    {
                        mn=min(mn,LCP[i]);
                        ans=max(mn,ans);
                        fnd[0]=fnd[1]=fnd[2]=0;
                        fnd[cur]=fnd[get(sa[i])]=1;
                        cur=get(sa[i]);
                        mn=LCP[i];
                    }
                }
            }
        }
        printf("Case %d: %d\n",++cs,ans);
    }
    return 0;
}
