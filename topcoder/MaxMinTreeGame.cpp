/**
*  SRM: 603
*  Div: 1
*  Point: 250
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
#include<set>
#include<utility>
#define ll long long
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

int dp[2][55][55];
vector<vector<int> > gr;
vector<int> cst;
int v[55],n;
int ans=-1;
void dfs(int u)
{
    //cout<<u<<endl;
    v[u]=1;
    if(gr[u].size()==1) ans=Max(ans,cst[u]);
    for(int i=0;i<gr[u].size();i++)
    {
        if(!v[gr[u][i]]) dfs(gr[u][i]);
    }
}
class MaxMinTreeGame {
	public:
	int findend(vector <int> edges, vector <int> costs) {
	    int i,j,k;
	    cst.clear();
        cst=costs;
        n=cst.size();
        gr.clear();
        gr.resize(n+1);
        for(i=0;i<n-1;i++)
        {
            gr[i+1].pb(edges[i]);
            gr[edges[i]].pb(i+1);
        }
        ans=-1;
        memset(v,0,sizeof(v));
        dfs(0);
        return ans;
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
			int edges[]               = {0};
			int costs[]               = {4,6};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = MaxMinTreeGame().findend(vector <int>(edges, edges + (sizeof edges / sizeof edges[0])), vector <int>(costs, costs + (sizeof costs / sizeof costs[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int edges[]               = {0,1};
			int costs[]               = {4,6,5};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = MaxMinTreeGame().findend(vector <int>(edges, edges + (sizeof edges / sizeof edges[0])), vector <int>(costs, costs + (sizeof costs / sizeof costs[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int edges[]               = {0,1,2,3};
			int costs[]               = {0,1,0,1,0};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = MaxMinTreeGame().findend(vector <int>(edges, edges + (sizeof edges / sizeof edges[0])), vector <int>(costs, costs + (sizeof costs / sizeof costs[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int edges[]               = {0,0,0};
			int costs[]               = {5,1,2,3};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = MaxMinTreeGame().findend(vector <int>(edges, edges + (sizeof edges / sizeof edges[0])), vector <int>(costs, costs + (sizeof costs / sizeof costs[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int edges[]               = {0,0};
			int costs[]               = {3,2,5};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = MaxMinTreeGame().findend(vector <int>(edges, edges + (sizeof edges / sizeof edges[0])), vector <int>(costs, costs + (sizeof costs / sizeof costs[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int edges[]               = ;
			int costs[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MaxMinTreeGame().findend(vector <int>(edges, edges + (sizeof edges / sizeof edges[0])), vector <int>(costs, costs + (sizeof costs / sizeof costs[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int edges[]               = ;
			int costs[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MaxMinTreeGame().findend(vector <int>(edges, edges + (sizeof edges / sizeof edges[0])), vector <int>(costs, costs + (sizeof costs / sizeof costs[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int edges[]               = ;
			int costs[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MaxMinTreeGame().findend(vector <int>(edges, edges + (sizeof edges / sizeof edges[0])), vector <int>(costs, costs + (sizeof costs / sizeof costs[0])));
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
