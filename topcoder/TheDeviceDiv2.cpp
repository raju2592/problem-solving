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

class TheDeviceDiv2 {
	public:
	string identify(vector <string> plates) {
	    int i,j,k;
	    if(plates.size()<3) return "NO";
	    int zero,one,two;
	    for(i=0;i<plates[0].size();i++)
	    {
            one=two=0;
	        for(j=0;j<plates.size();j++)
	        {
	            for(k=j+1;k<plates.size();k++)
	            {
	                if(plates[j][i]+plates[k][i]-2*'0'==1) one=1;
	                else if(plates[j][i]+plates[k][i]-2*'0'==2) two=1;

	            }
	        }
	        if(!(one && two)) return "NO";
	    }
	    return "YES";

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
			string plates[]           = {"010", "011", "000"};
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = TheDeviceDiv2().identify(vector <string>(plates, plates + (sizeof plates / sizeof plates[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string plates[]           = {"1", "0", "1", "0"};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = TheDeviceDiv2().identify(vector <string>(plates, plates + (sizeof plates / sizeof plates[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string plates[]           = {"11111"} ;
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = TheDeviceDiv2().identify(vector <string>(plates, plates + (sizeof plates / sizeof plates[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string plates[]           = {"0110011", "0101001", "1111010", "1010010"};
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = TheDeviceDiv2().identify(vector <string>(plates, plates + (sizeof plates / sizeof plates[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string plates[]           = {"101001011", "011011010", "010110010", "111010100", "111111111"};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = TheDeviceDiv2().identify(vector <string>(plates, plates + (sizeof plates / sizeof plates[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string plates[]           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TheDeviceDiv2().identify(vector <string>(plates, plates + (sizeof plates / sizeof plates[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string plates[]           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TheDeviceDiv2().identify(vector <string>(plates, plates + (sizeof plates / sizeof plates[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string plates[]           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TheDeviceDiv2().identify(vector <string>(plates, plates + (sizeof plates / sizeof plates[0])));
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
