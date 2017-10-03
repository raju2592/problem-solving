/**
*  SRM:
*  Div:
*  Point:
*/

#include<string>
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
#include<set>
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

vector<string> arr;
int n;

bool test(vector<string> &arr)
{
    int i,j,k;
    bool b=true;
    for(i=0;i<n;i++)
    {
        k=1;
        for(j=1;j<n;j++)
        {
            if(arr[j][i]==arr[j-1][i]) k++;
            else k=1;
            if(k>n/2) b=false;
        }
    }
    if(b) return true;
    else return false;
}
bool check()
{
    int i;
    vector<string> tmp=arr;
    string wh="",bl="";
    for(i=0;i<n;i++)
    {
        wh+="W";
        bl+="B";
    }
    for(i=0;i<n;i++)
    {
        tmp[i]=wh;
        if(test(tmp)) return true;
        tmp[i]=bl;
        if(test(tmp)) return true;
        tmp[i]=arr[i];
    }
    return false;
}

class TaroJiroGrid {
	public:
	int getNumber(vector <string> grid) {
		int i,j,k;
		n=grid.size();
		arr=grid;
		if(test(arr)) return 0;
		if(check()) return 1;
		else return 2;
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
			string grid[]             = {"WB", "BB"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TaroJiroGrid().getNumber(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string grid[]             = {"WB", "WW"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TaroJiroGrid().getNumber(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string grid[]             = {"WB", "WB"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TaroJiroGrid().getNumber(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string grid[]             = {"WBBW", "WBWB", "WWBB", "BWWW"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TaroJiroGrid().getNumber(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string grid[]             = {"WBBWBB", "BBWBBW", "WWBWBW", "BWWBBB", "WBWBBW", "WWWBWB"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TaroJiroGrid().getNumber(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			string grid[]             = {"WB","BW"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = TaroJiroGrid().getNumber(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 6: {
			string grid[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TaroJiroGrid().getNumber(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string grid[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TaroJiroGrid().getNumber(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
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
