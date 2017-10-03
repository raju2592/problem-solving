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

class RobotHerbDiv2 {
	public:
	int getdist(int T, vector <int> a) {
	    int i,j;
	    int x=0,y=0,dx=1,dy=0;
	    for(i=0;i<T;i++)
	    {
	        for(j=0;j<a.size();j++)
	        {
	            x+=dx*a[j];
	            y+=dy*a[j];
	            if((a[j]/2)%2)
	            {
	                dx=-dx;
	                dy=-dy;
	            }
	            if(a[j]%2)
	            {
	                if(dx==1) dx=0,dy=1;
	                else if(dx==-1) dx=0,dy=-1;
	                else if(dy==1) dx=-1,dy=0;
	                else if(dy==-1) dx=1,dy=0;
	            }
	        }
	    }
	    return (int) abs(x)+ (int) abs(y);

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
			int T                     = 1;
			int a[]                   = {1,2,3};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = RobotHerbDiv2().getdist(T, vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int T                     = 100;
			int a[]                   = {1};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = RobotHerbDiv2().getdist(T, vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int T                     = 5;
			int a[]                   = {1,1,2};
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = RobotHerbDiv2().getdist(T, vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int T                     = 100;
			int a[]                   = {400000};
			int expected__            = 40000000;

			clock_t start__           = clock();
			int received__            = RobotHerbDiv2().getdist(T, vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int T                     = ;
			int a[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RobotHerbDiv2().getdist(T, vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int T                     = ;
			int a[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RobotHerbDiv2().getdist(T, vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int T                     = ;
			int a[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RobotHerbDiv2().getdist(T, vector <int>(a, a + (sizeof a / sizeof a[0])));
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
