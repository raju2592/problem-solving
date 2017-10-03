#include<cstdio>
#include<queue>
#include<cstring>
#include<iostream>
using namespace std;
struct state
{
    int pos;
    int dm;
    int bm;
    state(int a,int b,int c)
    {
        pos=a;
        dm=b;
        bm=c;
    }
};

/**
    up 0
    down 2
    rear 1
    front 3
    left 4
    right 5
*/

int up(int x)
{
    ///412356
    char st[]="301245";
    int ret=0;
    for(int i=0;i<6;i++)
    {
        ret |= ((x & (1<<(st[i]-'0'))) >> (st[i]-'0')) << i;
    }
    return ret;
}
int down(int x)
{
    ///234156
    char st[]="123045";
    int ret=0;
    for(int i=0;i<6;i++)
    {
        ret |= ((x & (1<<(st[i]-'0'))) >> (st[i]-'0')) << i;
    }
    return ret;
}
int left(int x)
{
    ///625413
    char st[]="514302";
    int ret=0;
    for(int i=0;i<6;i++)
    {
        ret |= ((x & (1<<(st[i]-'0'))) >> (st[i]-'0')) << i;
    }
    return ret;

}
int right(int x)
{
    ///526431
    char st[]="415320";
    int ret=0;
    for(int i=0;i<6;i++)
    {
        ret |= ((x & (1<<(st[i]-'0'))) >> (st[i]-'0')) << i;
    }
    return ret;
}
char arr[4][4];
int v[16][1<<6][1<<16],dis[16][1<<6][1<<16];
int main()
{
    int t,i,j,k,strtpos,brdmsk,diemsk;
    scanf("%d",&t);
    getchar();
    while(t--)
    {

        gets(arr[0]);
        for(i=0;i<4;i++) gets(arr[i]);
        brdmsk=0;
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                k=4*i+j;
                if(arr[i][j]=='X') brdmsk |= (1<<k);
                if(arr[i][j]=='D') strtpos=k;
            }
        }
        diemsk=0;
        memset(v,0,sizeof(v));
        dis[strtpos][diemsk][brdmsk]=0;
        v[strtpos][diemsk][brdmsk]=1;
        queue<state> q;
        state s(strtpos,diemsk,brdmsk);
        q.push(s);
        int ans=-1;
        while(!q.empty())
        {
            state u=q.front();
            q.pop();
            //cout<<u.pos<<" "<<u.dm<<" "<<u.bm<<endl;
            if(u.dm==(1<<6)-1)
            {
                ans=dis[u.pos][u.dm][u.bm];
                break;
            }
            int a,b,c,d;
            if(u.pos>3)
            {
                a=u.pos-4;
                b=up(u.dm);
                d=u.bm;
                c= (u.bm & (~(1<<a))) | (((b & (1<<2)) >> 2) << a);
                b =(b & (~(1<<2))) | (((d & (1<<a)) >> a) << 2);
                if(!v[a][b][c])
                {
                    v[a][b][c]=1;
                    dis[a][b][c]=dis[u.pos][u.dm][u.bm]+1;
                    state nw(a,b,c);
                    q.push(nw);
                }

            }
            if(u.pos<12)
            {
                a=u.pos+4;
                b=down(u.dm);
                d=u.bm;
                c= (u.bm & (~(1<<a))) | (((b & (1<<2)) >> 2) << a);
                b =(b & (~(1<<2))) | (((d & (1<<a)) >> a) << 2);
                if(!v[a][b][c])
                {
                    v[a][b][c]=1;
                    dis[a][b][c]=dis[u.pos][u.dm][u.bm]+1;
                    state nw(a,b,c);
                    q.push(nw);
                }
            }
            if(u.pos%4)
            {
                a=u.pos-1;
                b=left(u.dm);
                d=u.bm;
                c= (u.bm & (~(1<<a))) | (((b & (1<<2)) >> 2) << a);
                b =(b & (~(1<<2))) | (((d & (1<<a)) >> a) << 2);
                if(!v[a][b][c])
                {
                    v[a][b][c]=1;
                    dis[a][b][c]=dis[u.pos][u.dm][u.bm]+1;
                    state nw(a,b,c);
                    q.push(nw);
                }
            }
            if(u.pos%4!=3)
            {
                a=u.pos+1;
                b=right(u.dm);
                d=u.bm;
                c= (u.bm & (~(1<<a))) | (((b & (1<<2)) >> 2) << a);
                b =(b & (~(1<<2))) | (((d & (1<<a)) >> a) << 2);
                if(!v[a][b][c])
                {
                    v[a][b][c]=1;
                    dis[a][b][c]=dis[u.pos][u.dm][u.bm]+1;
                    state nw(a,b,c);
                    q.push(nw);
                }
            }
        }
        if(ans!=-1) printf("%d\n",ans);
        else puts("impossible");
        while(!q.empty()) q.pop();
    }
    return 0;
}

/*int main()
{
    cout<<up(14)<<endl;
	cout<<down(14)<<endl;
	cout<<up(40)<<endl;
	cout<<down(40)<<endl;
    return 0;
}*/

