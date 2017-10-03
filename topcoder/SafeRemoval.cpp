/**
*  SRM: 553
*  Div: 2
*  Point:1000
*/

#include<string>
#include<cstdio>
#include<ctime>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<utility>
#define ll long //long
#define ull unsigned ll
#define pb push_back
#define mp make_pair
#define ii pair<ll,ll>
#define vi vector<ll>
#define vvi vector<vector<ll> >
#define vvii vector<vector< ii > >
#define INF 100000000
using namespace std;

ll Min(ll i,ll j){return i<j?i:j;}
ll Max(ll i,ll j){return i>j?i:j;}

vector<int> mods[4];
int dp[55][55][55][55];
int tot,cumu[4][55];
int n;

int MOD(int a)
{
    return ((a%4)+4)%4;
}

int calc(int a,int b,int c,int d)
{
    int &ret=dp[a][b][c][d];
    if(ret!=-1) return ret;
	int i,j,k;
	int m=MOD(tot-cumu[0][a]-cumu[1][b]-cumu[2][c]-cumu[3][d]);
    if(a+b+c+d==n)
    {
        ret=0;
        for(i=a;i<mods[0].size();i++) ret+=mods[0][i];
        for(i=b;i<mods[1].size();i++) ret+=mods[1][i];
        for(i=c;i<mods[2].size();i++) ret+=mods[2][i];
        for(i=d;i<mods[3].size();i++) ret+=mods[3][i];
        return ret;
    }
    ret=-INF;
    if(a<mods[0].size() && m!=MOD(mods[0][a]))
    {
        k=calc(a+1,b,c,d);
        if(k!=-INF && k>ret) ret=k;
    }
    if(b<mods[1].size() && m!=MOD(mods[1][b]))
    {
        k=calc(a,b+1,c,d);
        if(k!=-INF && k>ret) ret=k;
    }
    if(c<mods[2].size() && m!=MOD(mods[2][c]))
    {
        k=calc(a,b,c+1,d);
        if(k!=-INF && k>ret) ret=k;
    }
    if(d<mods[3].size() && m!=MOD(mods[3][d]))
    {
        k=calc(a,b,c,d+1);
        if(k!=-INF && k>ret) ret=k;
    }
    return ret;
}

class SafeRemoval {
	public:
	int removeThem(vector <int> seq, int k) {
        int i,j,x;
        for(i=0;i<4;i++) mods[i].clear();
        n=k;
        for(i=0;i<seq.size();i++)
        {
            tot+=seq[i];
            mods[seq[i]%4].pb(seq[i]);
        }

        for(i=0;i<4;i++) sort(mods[i].begin(),mods[i].end());
        for(i=0;i<4;i++)
        {
            cumu[i][0]=0;
            for(j=1;j<=mods[i].size();j++) cumu[i][j]=cumu[i][j-1]+mods[i][j-1];
        }
        memset(dp,-1,sizeof(dp));
        x=calc(0,0,0,0);
        if(x==-INF) return -1;
        return x;
	}
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}

		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}

		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}

	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) {
		cerr << "Example " << casenum << "... ";

		string verdict;
		vector<string> info;
		char buf[100];

		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}

		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}

		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;

		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl;
			cerr << "    Received: " << received << endl;
		}

		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			int seq[]                 = {3, 8, 4};
			int k                     = 1;
			int expected__            = 11;

			clock_t start__           = clock();
			int received__            = SafeRemoval().removeThem(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])), k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int seq[]                 = {1,1,1,1,1,1};
			int k                     = 3;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = SafeRemoval().removeThem(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])), k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int seq[]                 = {1,6,1,10,1,2,7,11};
			int k                     = 6;
			int expected__            = 21;

			clock_t start__           = clock();
			int received__            = SafeRemoval().removeThem(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])), k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int seq[]                 = {1,1,1,1,1,1,1,1,7};
			int k                     = 3;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = SafeRemoval().removeThem(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])), k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

      case 4: {
			int seq[]                 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50};
			int k                     = 25;
			int expected__            = 950;

			clock_t start__           = clock();
			int received__            = SafeRemoval().removeThem(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])), k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 5: {
			int seq[]                 = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SafeRemoval().removeThem(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])), k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int seq[]                 = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SafeRemoval().removeThem(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])), k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}

int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
