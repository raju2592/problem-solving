#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<utility>
#define ll int
#define ull unsigned ll
#define pb push_back
#define mp make_pair
#define ii pair<ll,ll>
#define vi vector<ll>
#define vvi vector<vector<ll> >
#define vvii vector<vector< ii > >
using namespace std;

ll Min(ll i,ll j){return i<j?i:j;}
ll Max(ll i,ll j){return i>j?i:j;}

string s1,s2,ss1,ss2,ans,tmp1;
//char s1[1000000],s2[1000000];

string decode(char c)
{
    if(c=='0') return "0000";
    if(c=='1') return "0001";
    if(c=='2') return "0010";
    if(c=='3') return "0011";
    if(c=='4') return "0100";
    if(c=='5') return "0101";
    if(c=='6') return "0110";
    if(c=='7') return "0111";
    if(c=='8') return "1000";
    if(c=='9') return "1001";
    if(c=='A') return "1010";
    if(c=='B') return "1011";
    if(c=='C') return "1100";
    if(c=='D') return "1101";
    if(c=='E') return "1110";
    if(c=='F') return "1111";
}
void allone(string &ss,string &s,int st,int &q)
{
    //cout<<st<<endl;
    //cout<<st<<endl;
    int xx;
    if(s[st]=='1')
    {
        //cout<<"dhkse";
        ss+=s[st];
        ss+=s[st+1];
        q=st+2;
        return ;
    }
    //cout<<"hu"<<st+1;
    ss+='0';
    allone(ss,s,st+1,xx);
    //cout<<"ff "<< xx<<endl;
    allone(ss,s,xx,xx);
    //cout<<"gg "<< xx<<endl;
    allone(ss,s,xx,xx);
    //cout<<"hh "<< xx<<endl;
    allone(ss,s,xx,xx);
    //cout<<"ii "<< xx<<endl;
    q=xx;
}
void allzero(string &s,int st,int &q)
{
    int xx;
    if(s[st]=='1')
    {
        q=st+2;
    }
    else
    {
        allzero(s,st+1,xx);
        allzero(s,xx,xx);
        allzero(s,xx,xx);
        allzero(s,xx,xx);
        q=xx;
    }
    //ans+="10";
}

void calc(string &ss,int a,int b,int &x,int &y)
{
    //cout<<a<<' '<<b<<endl;
    int p,q;
    //string tmp;
    //cout<<"HU";
    if(ss1[a]=='1' && ss2[b]=='1')
    {
        //cout<<"dhukse";
        ss+='1';
        char cc=((ss1[a+1]-'0')&&(ss2[b+1]-'0'))+'0';
        ss+=cc;
        x=a+2;
        y=b+2;
        return;
    }
    else if(ss1[a]=='1' && ss2[b]=='0')
    {
        if(ss1[a+1]=='1') allone(ss,ss2,b,q);
        else
        {
            ss+="10";
            allzero(ss2 ,b,q);
        }
        p=a+2;
        x=p;
        y=q;
    }
    else if(ss2[b]=='1' && ss1[a]=='0')
    {
        if(ss2[b+1]=='1') allone(ss,ss1,a,p);
        else
        {
            ss+="10";
            allzero(ss1,a,p);
        }
        q=b+2;
        x=p;
        y=q;
    }
    else
    {
        string tmp="0";
        //tmp+='0';
        calc(tmp,a+1,b+1,p,q);
        calc(tmp,p,q,p,q);
        calc(tmp,p,q,p,q);
        calc(tmp,p,q,p,q);
        if(tmp.compare("010101010")==0) ss+="10";
        else ss+=tmp;
        x=p;
        y=q;
    }
}
char encode(string &s,int st)
{
    int ret=0;
    int pow=8;
    int i;
    for(i=st;i<st+4;i++)
    {
        ret+=(s[i]-'0')*pow;
        pow/=2;
    }
    if(ret<10) return ret+'0';
    if(ret==10) return 'A';
    if(ret==11) return 'B';
    if(ret==12) return 'C';
    if(ret==13) return 'D';
    if(ret==14) return 'E';
    if(ret==15) return 'F';
}
int main()
{
    ll a,b,c,d,e,i,j,k,l,m,n;
    string tmp;
    int kase=1;
    while(cin>>s1>>s2)
    {
        if(s1=="0" && s2=="0") break;
        ss1="";
        ss2="";
        int l1,l2;
        l1=s1.size();
        l2=s2.size();
		//l1=strlen(s1);
		//l2=strlen(s2);
        for(i=0;i<l1;i++)
        {
            tmp=decode(s1[i]);
            if(i!=0) ss1+=tmp;
            else
            {
                for(j=0;j<tmp.size();j++)
                {
                    if(tmp[j]=='1') break;
                }
                for(++j;j<tmp.size();j++) ss1+=tmp[j];
            }
        }
        for(i=0;i<l2;i++)
        {
            tmp=decode(s2[i]);
            if(i!=0) ss2+=tmp;
            else
            {
                for(j=0;j<tmp.size();j++)
                {
                    if(tmp[j]=='1') break;
                }
                for(++j;j<tmp.size();j++) ss2+=tmp[j];
            }
        }
        //cout<<ss1<<" "<<ss2<<endl;
        ans="1";
        calc(ans,0,0,c,d);
        //cout<<ans;
        //if(ans=="1010101010") ans="110";
        int len=ans.size();
        tmp="";
        while(len%4)
        {
            tmp+='0';
            len++;
        }
        tmp+=ans;
        len=tmp.size();
        string out="";
        for(i=0;i<len;i+=4)
        {
            out+=encode(tmp,i);
        }
        //cout<<out;
        if(kase!=1) cout<<"\n";
        cout<<"Image "<<kase<<":\n"<<out<<"\n";
        kase++;
    }
    return 0;
}
