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

class RevealTriangle {
	public:
	vector <string> calcTriangle(vector <string> questionMarkTriangle) {
		vector<string> vv=questionMarkTriangle;
		int n=vv.size(),i,j,k,l,b,a,x,y;
		for(i=n-2;i>=0;i--)
		{
		    for(j=0;j<vv[i].size();j++) if(vv[i][j]!='?') k=j;
		    x=k;
		    while(x>0)
		    {
                a=vv[i+1][x-1]-'0';
                b=vv[i][x]-'0';
                if(a>=b) vv[i][x-1]=a-b+'0';
                else vv[i][x-1]=10+a-b+'0';
                x--;
		    }
		    x=k;
		    while(x<vv[i].size()-1)
		    {
		        a=vv[i+1][x]-'0';
		        b=vv[i][x]-'0';
		        if(a>=b) vv[i][x+1] =a-b+'0';
		        else vv[i][x+1]=10+a-b+'0';
		        x++;
		    }
        }
        return vv;
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

	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }
	template<> ostream& operator<<(ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

	int verify_case(int casenum, const vector <string> &expected, const vector <string> &received, clock_t elapsed) {
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
			string questionMarkTriangle[] = {"4??", "?2", "1"};
			string expected__[]       = {"457", "92", "1" };

			clock_t start__           = clock();
			vector <string> received__ = RevealTriangle().calcTriangle(vector <string>(questionMarkTriangle, questionMarkTriangle + (sizeof questionMarkTriangle / sizeof questionMarkTriangle[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string questionMarkTriangle[] = {"1"};
			string expected__[]       = {"1" };

			clock_t start__           = clock();
			vector <string> received__ = RevealTriangle().calcTriangle(vector <string>(questionMarkTriangle, questionMarkTriangle + (sizeof questionMarkTriangle / sizeof questionMarkTriangle[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string questionMarkTriangle[] = {"???2", "??2", "?2", "2"};
			string expected__[]       = {"0002", "002", "02", "2" };

			clock_t start__           = clock();
			vector <string> received__ = RevealTriangle().calcTriangle(vector <string>(questionMarkTriangle, questionMarkTriangle + (sizeof questionMarkTriangle / sizeof questionMarkTriangle[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			string questionMarkTriangle[] = {"??5?", "??9", "?4", "6"};
			string expected__[]       = {"7054", "759", "24", "6" };

			clock_t start__           = clock();
			vector <string> received__ = RevealTriangle().calcTriangle(vector <string>(questionMarkTriangle, questionMarkTriangle + (sizeof questionMarkTriangle / sizeof questionMarkTriangle[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string questionMarkTriangle[] = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = RevealTriangle().calcTriangle(vector <string>(questionMarkTriangle, questionMarkTriangle + (sizeof questionMarkTriangle / sizeof questionMarkTriangle[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			string questionMarkTriangle[] = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = RevealTriangle().calcTriangle(vector <string>(questionMarkTriangle, questionMarkTriangle + (sizeof questionMarkTriangle / sizeof questionMarkTriangle[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			string questionMarkTriangle[] = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = RevealTriangle().calcTriangle(vector <string>(questionMarkTriangle, questionMarkTriangle + (sizeof questionMarkTriangle / sizeof questionMarkTriangle[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
