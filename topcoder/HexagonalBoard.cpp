/**
*  SRM:593
*  Div:1
*  Point:250
*/

#include<cstdio>
#include<ctime>
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
#define ll long
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
int dx[]={-1,1,0,1,-1,0};
int dy[]={0,0,-1,-1,1,1};
int v[55][55];
class HexagonalBoard {
	public:
	int minColors(vector <string> board) {
	    int ret=0,i,j,k;
	    for(i=0;i<board.size();i++)
	    {
	        for(j=0;j<board.size();j++)
	        {
	            if(board[i][j]=='X')
	            {
	                //ret=max(ret,1);
	                if(!v[i][j]) ret=Max(ret,dfs(i,j,board,1));
	            }
	        }
	    }
	    return ret;
	}
	int dfs(int x,int y,vector<string> &brd,int col)
	{
	    v[x][y]=col;
	    int ret=1;
	    for(int k=0;k<6;k++)
	    {
	        int xx=x+dx[k],yy=y+dy[k];
	        if(xx>=0 && xx<brd.size() && yy>=0 && yy<brd.size())
	        {
	            if(!v[xx][yy] && brd[xx][yy]=='X')
	            {
	                ret=Max(ret,2);
	                ret=Max(ret,dfs(xx,yy,brd,(col==1)?2:1));
	            }
	            else if(v[xx][yy]==col)
	            {
	                cout<<x<<" "<<y<<" "<<xx<<" "<<yy<<endl;
	                return 3;
	            }
	        }
	    }
	    return ret;
	}
};

