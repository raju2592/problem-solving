/**
*  SRM: 602
*  Div: 1
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

ll Min(ll i,ll j){return i<j?i:j;}
ll Max(ll i,ll j){return i>j?i:j;}

vector<int> arr;
ll dp[2500][60];

ll calc(ll val,ll st)
{
    if(dp[val][st]!=-1) return dp[val][st];
    if(st==arr.size()) return 0;
    ll tmp=val-arr[st];
    if(tmp<0) tmp=0;
    dp[val][st]=calc(tmp,st+1);
    tmp=val+arr[st];
    if(tmp<2200) dp[val][st]=Max(dp[val][st],calc(tmp,st+1));
    else if(tmp>=2200)
    {
        //ll ret=1;
        if(st==arr.size()-1) dp[val][st]=Max(dp[val][st],1);
        else
        {
            tmp-=arr[st+1];
            if(tmp<2200)
            {
                if(tmp<0) tmp=0;
                dp[val][st]=Max(2+calc(tmp,st+2),dp[val][st]);
            }
        }
    }
    return dp[val][st];
}
class TypoCoderDiv1 {
	public:
	int getmax(vector <int> D, int X) {
        memset(dp,-1,sizeof(dp));
        arr=D;
        return calc(X,0);
	}
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cout << "Illegal input! Test case " << casenum << " does not exist." << endl;
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
			cout << "No test cases run." << endl;
		} else if (correct < total) {
			cout << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cout << "All " << total << " tests passed!" << endl;
		}
	}

	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) {
		cout << "Example " << casenum << "... ";

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

		cout << verdict;
		if (!info.empty()) {
			cout << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cout << ", ";
				cout << info[i];
			}
			cout << ")";
		}
		cout << endl;

		if (verdict == "FAILED") {
			cout << "    Expected: " << expected << endl;
            cout << "    Received: " << received << endl;
		}

		return verdict =="PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			int D[]                   = {100,200,100,1,1};
			int X                     = 2000;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = TypoCoderDiv1().getmax(vector <int>(D, D + (sizeof D / sizeof D[0])), X);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int D[]                   = {0,0,0,0,0};
			int X                     = 2199;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = TypoCoderDiv1().getmax(vector <int>(D, D + (sizeof D / sizeof D[0])), X);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int D[]                   = {90000,80000,70000,60000,50000,40000,30000,20000,10000};
			int X                     = 0;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TypoCoderDiv1().getmax(vector <int>(D, D + (sizeof D / sizeof D[0])), X);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int D[]                   = {1000000000,1000000000,10000,100000,2202,1};
			int X                     = 1000;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = TypoCoderDiv1().getmax(vector <int>(D, D + (sizeof D / sizeof D[0])), X);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int D[]                   = {2048,1024,5012,256,128,64,32,16,8,4,2,1,0};
			int X                     = 2199;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = TypoCoderDiv1().getmax(vector <int>(D, D + (sizeof D / sizeof D[0])), X);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int D[]                   = ;
			int X                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TypoCoderDiv1().getmax(vector <int>(D, D + (sizeof D / sizeof D[0])), X);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int D[]                   = ;
			int X                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TypoCoderDiv1().getmax(vector <int>(D, D + (sizeof D / sizeof D[0])), X);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int D[]                   = ;
			int X                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TypoCoderDiv1().getmax(vector <int>(D, D + (sizeof D / sizeof D[0])), X);
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
