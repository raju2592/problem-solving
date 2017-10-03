/**
*  SRM: 585
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
#define mod 1000000007
ll Min(ll i,ll j){return i<j?i:j;}
ll Max(ll i,ll j){return i>j?i:j;}

int val[1000005];
class TrafficCongestion {
	public:
	int theMinCars(int treeHeight) {

	    val[0]=val[1]=1;
	    int sum=0;
	    for(int i=2;i<=treeHeight;i++)
	    {
	        sum= (sum+val[i-2])%mod;
	        val[i]= (2*sum+1)%mod;
	    }
	    return val[treeHeight];
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
			int treeHeight            = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TrafficCongestion().theMinCars(treeHeight);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int treeHeight            = 2;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = TrafficCongestion().theMinCars(treeHeight);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int treeHeight            = 3;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = TrafficCongestion().theMinCars(treeHeight);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int treeHeight            = 585858;
			int expected__            = 548973404;

			clock_t start__           = clock();
			int received__            = TrafficCongestion().theMinCars(treeHeight);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int treeHeight            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TrafficCongestion().theMinCars(treeHeight);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int treeHeight            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TrafficCongestion().theMinCars(treeHeight);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int treeHeight            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TrafficCongestion().theMinCars(treeHeight);
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
