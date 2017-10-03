/**
*  SRM:594
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
#define ll long long
#define uint unsigned ll
#define pb push_back
#define mp make_pair
#define ii pair<ll,ll>
#define vi vector<ll>
#define vvi vector<vector<ll> >
#define vvii vector<vector< ii > >
using namespace std;

ll Min(ll i,ll j){return i<j?i:j;}
ll Max(ll i,ll j){return i>j?i:j;}


class AstronomicalRecords {
	public:
	vector<int> A,B;
	int x,y;
	int dp[54][54];
	int minimalPlanets(vector <int> A, vector <int> B) {
	    int i,j;
        this->A=A;
        this->B=B;
        int ret=4000,tmp;
        for(i=0;i<A.size();i++)
        {
            for(j=0;j<B.size();j++)
            {
                tmp=i+j+1;
                x=B[j];
                y=A[i];
                memset(dp,-1,sizeof(dp));
                tmp+=calc(i+1,j+1);
                ret=min(ret,tmp);
            }
        }
        return ret;
	}
	int calc(int i,int j)
	{
	    if(dp[i][j]!=-1) return dp[i][j];
	    if(i==A.size()) return dp[i][j]=B.size()-j;
	    if(j==B.size()) return dp[i][j]=A.size()-i;
	    dp[i][j]=min(1+calc(i+1,j),1+calc(i,j+1));
	    if(((ll)A[i]*x)%y==0 && ((ll)A[i]*x)/y==B[j]) dp[i][j]=min(dp[i][j],1+calc(i+1,j+1));
	    return dp[i][j];
	}
};

