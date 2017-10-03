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
#define INF 200000000

#define ll long long
#define ull unsigned ll
#define pb push_back
#define mkp make_pair
using namespace std;
int calc(ll tot,vector<int> &dread,vector<int> &price,int st)
{
    if(st==dread.size()) return 0;
    int t1=calc(tot+dread[st],dread,price,st+1)+price[st];
    int t2=INF;
    if(tot>=dread[st]) t2=calc(tot,dread,price,st+1);
    return min(t1,t2);
}

class MonstersValley2 {
	public:
	int minimumPrice(vector <int> dread, vector <int> price) {
        //memest(dp,-1,sizeof(dp));
        return calc(0,dread,price,0);

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
			int dread[]               = {8, 5, 10};
			int price[]               = {1, 1, 2};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = MonstersValley2().minimumPrice(vector <int>(dread, dread + (sizeof dread / sizeof dread[0])), vector <int>(price, price + (sizeof price / sizeof price[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int dread[]               = {1, 2, 4, 1000000000};
			int price[]               = {1, 1, 1, 2};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = MonstersValley2().minimumPrice(vector <int>(dread, dread + (sizeof dread / sizeof dread[0])), vector <int>(price, price + (sizeof price / sizeof price[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int dread[]               = {200, 107, 105, 206, 307, 400};
			int price[]               = {1, 2, 1, 1, 1, 2};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = MonstersValley2().minimumPrice(vector <int>(dread, dread + (sizeof dread / sizeof dread[0])), vector <int>(price, price + (sizeof price / sizeof price[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int dread[]               = {5216, 12512, 613, 1256, 66, 17202, 30000, 23512, 2125, 33333};
			int price[]               = {2, 2, 1, 1, 1, 1, 2, 1, 2, 1};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = MonstersValley2().minimumPrice(vector <int>(dread, dread + (sizeof dread / sizeof dread[0])), vector <int>(price, price + (sizeof price / sizeof price[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int dread[]               = ;
			int price[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MonstersValley2().minimumPrice(vector <int>(dread, dread + (sizeof dread / sizeof dread[0])), vector <int>(price, price + (sizeof price / sizeof price[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int dread[]               = ;
			int price[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MonstersValley2().minimumPrice(vector <int>(dread, dread + (sizeof dread / sizeof dread[0])), vector <int>(price, price + (sizeof price / sizeof price[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int dread[]               = ;
			int price[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MonstersValley2().minimumPrice(vector <int>(dread, dread + (sizeof dread / sizeof dread[0])), vector <int>(price, price + (sizeof price / sizeof price[0])));
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
