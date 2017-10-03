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

#define a first
#define b second
#define ll long long
#define ull unsigned ll
#define pb push_back
#define mkp make_pair
using namespace std;

class AlternateColors {
	public:
	string getColor(ll r, ll g, ll b, ll k) {
	    pair<ll,char> arr[3];
	    arr[0].a=r;
	    arr[0].b='r';
	    arr[1].a=g;
	    arr[1].b='g';
	    arr[2].a=b;
	    arr[2].b='b';
	    sort(arr,arr+3);
	    if(k<=3*arr[0].a)
	    {
	        k--;
	        k%=3;
	        if(k==0) return "RED";
	        else if(k==1) return "GREEN";
	        else return "BLUE";
	    }
	    else
	    {
	        k-=3*arr[0].a;
	        arr[1].a-=arr[0].a;
	        arr[2].a-=arr[0].a;
	        if(k<=2*arr[1].a && arr[1].a>0)
	        {
	            k--;
	            k%=2;
	            if(arr[0].b=='b')
	            {
	                if(k==0) return "RED";
	                else return "GREEN";
	            }
	            else if(arr[0].b=='g')
	            {
	                if(k==0) return "RED";
	                else return "BLUE";
	            }
	            else if(arr[0].b=='r')
	            {
	                if(k==0) return "GREEN";
	                else return "BLUE";
	            }
	        }
	        else
	        {
	            if(arr[2].b=='r') return "RED";
	            else if(arr[2].b=='g') return "GREEN";
	            else return "BLUE";
	        }
	    }

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
		/*case 0: {
			long long r               = 20;
			long long g               = 11;
			long long b               = 6;
			long long k               = 24;
			string expected__         = "GREEN";

			clock_t start__           = clock();
			string received__         = AlternateColors().getColor(r, g, b, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			long long r               = 3;
			long long g               = 4;
			long long b               = 5;
			long long k               = 4;
			string expected__         = "RED";

			clock_t start__           = clock();
			string received__         = AlternateColors().getColor(r, g, b, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			long long r               = 7;
			long long g               = 7;
			long long b               = 1;
			long long k               = 7;
			string expected__         = "GREEN";

			clock_t start__           = clock();
			string received__         = AlternateColors().getColor(r, g, b, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			long long r               = 1000000000000LL;
			long long g               = 1;
			long long b               = 1;
			long long k               = 1000000000002LL;
			string expected__         = "RED";

			clock_t start__           = clock();
			string received__         = AlternateColors().getColor(r, g, b, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			long long r               = 653;
			long long g               = 32;
			long long b               = 1230;
			long long k               = 556;
			string expected__         = "BLUE";

			clock_t start__           = clock();
			string received__         = AlternateColors().getColor(r, g, b, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/

		// custom cases

    case 0: {
			ll r               = 20;
			ll g               = 11;
			ll b               = 6;
			ll k               = 24;
			string expected__         = "GREEN";

			clock_t start__           = clock();
			string received__         = AlternateColors().getColor(r, g, b, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 6: {
			long long r               = ;
			long long g               = ;
			long long b               = ;
			long long k               = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = AlternateColors().getColor(r, g, b, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			long long r               = ;
			long long g               = ;
			long long b               = ;
			long long k               = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = AlternateColors().getColor(r, g, b, k);
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
