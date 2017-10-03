/**
*  SRM:592
*  Div:1
*  Point:300
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


class LittleElephantAndBalls {
	public:
	int getNumber(string S) {
	    map<char,int> L,R;
	    int a=1,b=0;
	    int ret=0;
	    L[S[0]]=1;
	    for(int i=1;i<S.size();i++)
	    {
	        ret+=a+b;
	        if(L[S[i]]==0) L[S[i]]=1,a++;
	        else if(R[S[i]]==0) R[S[i]]=1,b++;
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
			string S                  = "RGB";
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = LittleElephantAndBalls().getNumber(S);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string S                  = "RGGRBBB";
			int expected__            = 21;

			clock_t start__           = clock();
			int received__            = LittleElephantAndBalls().getNumber(S);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string S                  = "RRRGBRR";
			int expected__            = 16;

			clock_t start__           = clock();
			int received__            = LittleElephantAndBalls().getNumber(S);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string S                  = "RRRR";
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = LittleElephantAndBalls().getNumber(S);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string S                  = "GGRRRGR";
			int expected__            = 18;

			clock_t start__           = clock();
			int received__            = LittleElephantAndBalls().getNumber(S);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string S                  = "G";
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = LittleElephantAndBalls().getNumber(S);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string S                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LittleElephantAndBalls().getNumber(S);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string S                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LittleElephantAndBalls().getNumber(S);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string S                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LittleElephantAndBalls().getNumber(S);
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
