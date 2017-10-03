/**
*  SRM: 601
*  Div: 2
*  Point: 500
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


class WinterAndCandies {
	public:
	int getNumber(vector <int> type) {
		sort(type.begin(),type.end());
		int i,j,k,cnt[55];
		memset(cnt,0,sizeof(cnt));
		for(i=0;i<type.size();i++) cnt[type[i]]++;
		int ret=0;
		for(i=1;i<=type[type.size()-1];i++)
		{
		    int tmp=1;
		    for(j=1;j<=i;j++) tmp*=cnt[j];
		    ret+=tmp;
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
			int type[]                = {1, 3, 2};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = WinterAndCandies().getNumber(vector <int>(type, type + (sizeof type / sizeof type[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int type[]                = {1, 1, 2};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = WinterAndCandies().getNumber(vector <int>(type, type + (sizeof type / sizeof type[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int type[]                = {1, 3, 2, 5, 7, 4, 5, 4};
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = WinterAndCandies().getNumber(vector <int>(type, type + (sizeof type / sizeof type[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int type[]                = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
			int expected__            = 62;

			clock_t start__           = clock();
			int received__            = WinterAndCandies().getNumber(vector <int>(type, type + (sizeof type / sizeof type[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int type[]                = {2};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = WinterAndCandies().getNumber(vector <int>(type, type + (sizeof type / sizeof type[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int type[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WinterAndCandies().getNumber(vector <int>(type, type + (sizeof type / sizeof type[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int type[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WinterAndCandies().getNumber(vector <int>(type, type + (sizeof type / sizeof type[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int type[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WinterAndCandies().getNumber(vector <int>(type, type + (sizeof type / sizeof type[0])));
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
