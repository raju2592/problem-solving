/**
*  SRM: 601
*  Div: 2
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
#define INF 2000000000
ll Min(ll i,ll j){return i<j?i:j;}
ll Max(ll i,ll j){return i>j?i:j;}


class WinterAndMandarins {
	public:
	int getNumber(vector <int> bags, int K) {
		sort(bags.begin(),bags.end());
		int ans=INF,i;
		for(i=0;i<=bags.size()-K;i++)
		{
		    ans=min(ans,bags[i+K-1]-bags[i]);
		}
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
			int bags[]                = {10, 20, 30};
			int K                     = 2;
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = WinterAndMandarins().getNumber(vector <int>(bags, bags + (sizeof bags / sizeof bags[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int bags[]                = {4, 7, 4};
			int K                     = 3;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = WinterAndMandarins().getNumber(vector <int>(bags, bags + (sizeof bags / sizeof bags[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int bags[]                = {4, 1, 2, 3};
			int K                     = 3;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = WinterAndMandarins().getNumber(vector <int>(bags, bags + (sizeof bags / sizeof bags[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int bags[]                = {5, 4, 6, 1, 9, 4, 2, 7, 5, 6};
			int K                     = 4;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = WinterAndMandarins().getNumber(vector <int>(bags, bags + (sizeof bags / sizeof bags[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int bags[]                = {47, 1000000000, 1, 74};
			int K                     = 2;
			int expected__            = 27;

			clock_t start__           = clock();
			int received__            = WinterAndMandarins().getNumber(vector <int>(bags, bags + (sizeof bags / sizeof bags[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int bags[]                = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WinterAndMandarins().getNumber(vector <int>(bags, bags + (sizeof bags / sizeof bags[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int bags[]                = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WinterAndMandarins().getNumber(vector <int>(bags, bags + (sizeof bags / sizeof bags[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int bags[]                = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WinterAndMandarins().getNumber(vector <int>(bags, bags + (sizeof bags / sizeof bags[0])), K);
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
