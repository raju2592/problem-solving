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

class TheNumberGameDiv2 {
	public:
	int minimumMoves(int A, int B) {
	    int i,j;
	    map<string,int> d;
	    map<string,int> v;
	    string u,tmp;
	    string a,b;
	    stringstream ss;
	    ss<<A;
		ss>>a;
	    stringstream sb;
	    sb<<B;
		sb>>b;
	    queue<string> q;
	    v[a]=1;
	    q.push(a);
	    while(!q.empty())
	    {
	        u=q.front();
	        if(u==b) return d[u];
	        q.pop();
	        tmp=u.substr(0,u.size()-1);
	        if(v[tmp]==0)
	        {
	            v[tmp]=1;
	            d[tmp]=d[u]+1;
	            q.push(tmp);
	        }
	        tmp=u;
	        reverse(u.begin(),u.end());
	        if(v[u]==0)
	        {
                v[u]=1;
                d[u]=d[tmp]+1;
                q.push(u);
	        }
	    }
	    return -1;
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
			int A                     = 25;
			int B                     = 5;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TheNumberGameDiv2().minimumMoves(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int A                     = 5162;
			int B                     = 16;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = TheNumberGameDiv2().minimumMoves(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int A                     = 334;
			int B                     = 12;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = TheNumberGameDiv2().minimumMoves(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int A                     = 218181918;
			int B                     = 9181;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = TheNumberGameDiv2().minimumMoves(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int A                     = 9798147;
			int B                     = 79817;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = TheNumberGameDiv2().minimumMoves(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int A                     = ;
			int B                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheNumberGameDiv2().minimumMoves(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int A                     = ;
			int B                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheNumberGameDiv2().minimumMoves(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int A                     = ;
			int B                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheNumberGameDiv2().minimumMoves(A, B);
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
