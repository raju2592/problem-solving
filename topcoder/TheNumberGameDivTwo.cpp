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
#include<ctime>
#include<set>
#include<string>
#include<bitset>
#include<iomanip>
#include<complex>
#include<numeric>
#include<valarray>
#include<deque>


#define ll long long
#define ull unsigned ll
#define pb push_back
#define mkp make_pair
using namespace std;

class TheNumberGameDivTwo {
	public:
	string find(int n) {
		int dp[100005],i,j;
		dp[1]=0;
		for(i=2;i<=n;i++)
		{
		    dp[i]=0;
		    for(j=2;j*j<=i;j++)
		    {
		        if(i%j==0)
		        {
		            if(dp[i-j]==0 || dp[i-i/j]==0)
		            {
		                dp[i]=1;
		                break;
		            }
		        }
		    }
		}
		if(dp[n]) return "John";
		else return "Brus";
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

	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) {
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
			cerr << "    Expected: \"" << expected << "\"" << endl;
			cerr << "    Received: \"" << received << "\"" << endl;
		}

		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			int n                     = 6;
			string expected__         = "John";

			clock_t start__           = clock();
			string received__         = TheNumberGameDivTwo().find(n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 2;
			string expected__         = "Brus";

			clock_t start__           = clock();
			string received__         = TheNumberGameDivTwo().find(n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 747;
			string expected__         = "Brus";

			clock_t start__           = clock();
			string received__         = TheNumberGameDivTwo().find(n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 128;
			string expected__         = "Brus";

			clock_t start__           = clock();
			string received__         = TheNumberGameDivTwo().find(n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int n                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TheNumberGameDivTwo().find(n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int n                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TheNumberGameDivTwo().find(n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TheNumberGameDivTwo().find(n);
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
