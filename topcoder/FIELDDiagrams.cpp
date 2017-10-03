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
#define mp make_pair
using namespace std;

ll dp[35][35];

class FIELDDiagrams {
	public:
	ll countDiagrams(int fieldOrder) {
	    ll i,j,k,n=fieldOrder,l,ret;
	    for(i=1;i<=n+1;i++) dp[0][i]=1;
	    ret=0;
	    for(i=1;i<=n;i++)
	    {
	        for(j=n;j>=1;j--)
	        {

	            l=n-j+1;
	            //cout<<l<<endl;
	            dp[i][j]=0;
	            if(i>l) continue;
	            //dp[i][j]=0;
	            //cout<<"dhukse";
	            for(k=i;k>=0;k--)
	            {
                    dp[i][j]+=dp[k][j+1];
	            }
	            //cout<<i<<' '<<j<<' '<<dp[i][j];
	            if(j==1) ret+=dp[i][j];
	        }
	    }
	    return ret;
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

	int verify_case(int casenum, const ll &expected, const ll &received, clock_t elapsed) {
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
			int fieldOrder            = 2;
			ll expected__      = 4;

			clock_t start__           = clock();
			ll received__      = FIELDDiagrams().countDiagrams(fieldOrder);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int fieldOrder            = 3;
			ll expected__      = 13;

			clock_t start__           = clock();
			ll received__      = FIELDDiagrams().countDiagrams(fieldOrder);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int fieldOrder            = 5;
			ll expected__      = 131;

			clock_t start__           = clock();
			ll received__      = FIELDDiagrams().countDiagrams(fieldOrder);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			int fieldOrder            = ;
			ll expected__      = ;

			clock_t start__           = clock();
			ll received__      = FIELDDiagrams().countDiagrams(fieldOrder);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			int fieldOrder            = ;
			ll expected__      = ;

			clock_t start__           = clock();
			ll received__      = FIELDDiagrams().countDiagrams(fieldOrder);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int fieldOrder            = ;
			ll expected__      = ;

			clock_t start__           = clock();
			ll received__      = FIELDDiagrams().countDiagrams(fieldOrder);
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
