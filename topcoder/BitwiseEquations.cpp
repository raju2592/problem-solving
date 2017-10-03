/**
    SRM: 430
    div: 1
    lev: 1
**/

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

class BitwiseEquations {
	public:
	ll kthPlusOrSolution(int x, int k) {
		ll i,j,bb;
		//bb=__builtin_popcount(x);
		long long ret=0,tmp,inp=0;
		//j=32;
		//while(1<<(j-1)<k) j++;
		inp=inp|x;
		j=0;
		i=0;
		ll p=1;
		while(i<32)
		{
		    if((inp & (p<<j)) ==0)
		    {
		        tmp= k & (p<<i);
		        if(tmp) ret = ret | (p<<j);
		        i++;
		        //cout<<ret<<endl;
		    }
		    j++;
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
			int x                     = 5;
			int k                     = 1;
			ll expected__      = 2;

			clock_t start__           = clock();
			ll received__      = BitwiseEquations().kthPlusOrSolution(x, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int x                     = 5;
			int k                     = 5;
			ll expected__      = 18;

			clock_t start__           = clock();
			ll received__      = BitwiseEquations().kthPlusOrSolution(x, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int x                     = 10;
			int k                     = 3;
			ll expected__      = 5;

			clock_t start__           = clock();
			ll received__      = BitwiseEquations().kthPlusOrSolution(x, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int x                     = 1;
			int k                     = 1000000000;
			ll expected__      = 2000000000;

			clock_t start__           = clock();
			ll received__      = BitwiseEquations().kthPlusOrSolution(x, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

      case 4: {
			int x                     = 1073741824;
			int k                     = 1073741824;
			ll expected__      = 2147483648;

			clock_t start__           = clock();
			ll received__      = BitwiseEquations().kthPlusOrSolution(x, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
      /*case 5: {
			int x                     = 4;
			int k                     = 4;
			ll expected__      = 8;

			clock_t start__           = clock();
			ll received__      = BitwiseEquations().kthPlusOrSolution(x, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int x                     = ;
			int k                     = ;
			ll expected__      = ;

			clock_t start__           = clock();
			ll received__      = BitwiseEquations().kthPlusOrSolution(x, k);
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
