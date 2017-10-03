/**
*  SRM: 604
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

int MOD(int a,int b){return (a%b+b)%b;}
vector<int> conv(int x)
{
    vector<int> ret;
    if(x==0)
    {
        ret.pb(0);
        return ret;
    }
    while(x)
    {
        if(MOD(x,3)<2)
        {
            //cout<<MOD(x,3)<<" ";
            ret.pb(MOD(x,3));
            x=(x-MOD(x,3))/3;

        }
        else
        {
            ret.pb(-1);
            x=(x+1)/3;
            //cout<<-1<<" ";
        }
        //cout<<x<<endl;
    }
    return ret;
}
class PowerOfThree {
	public:
	string ableToGet(int x, int y) {
	    if(x==0 && y==0) return "Possible";
	    vector<int> xx=conv(x),yy=conv(y);
	    int i,j,k,p,q;
	    /*for(i=0;i<xx.size();i++) if(xx[i]>1) return "Impossible";
	    for(i=0;i<yy.size();i++) if(yy[i]>1) return "Impossible";*/
	    p=xx.size();
	    q=yy.size();
	    //for(i=0;i<p;i++) cout<<xx[i]<<" ";
	    //cout<<endl;
	    //for(i=0;i<q;i++) cout<<yy[i]<<" ";
	    //cout<<endl;
	    for(i=0;i<min(p,q);i++)
	    {
	        if(xx[i]!=0 && yy[i]!=0) return "Impossible";
	        else if(xx[i]==0 && yy[i]==0) return "Impossible";
	    }
	    if(p<=q)
	    {
	        for(j=p;j<q;j++) if(yy[j]==0) return "Impossible";
	        return "Possible";
	    }
	    else
	    {
	        for(j=q;j<p;j++) if(xx[j]==0) return "Impossible";
	        return "Possible";
	    }

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
		/*case 0: {
			int x                     = 1;
			int y                     = 3;
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = PowerOfThree().ableToGet(x, y);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int x                     = 0;
			int y                     = 2;
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = PowerOfThree().ableToGet(x, y);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int x                     = 1;
			int y                     = 9;
			string expected__         = "Impossible";

			clock_t start__           = clock();
			string received__         = PowerOfThree().ableToGet(x, y);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int x                     = 3;
			int y                     = 0;
			string expected__         = "Impossible";

			clock_t start__           = clock();
			string received__         = PowerOfThree().ableToGet(x, y);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int x                     = 1;
			int y                     = 1;
			string expected__         = "Impossible";

			clock_t start__           = clock();
			string received__         = PowerOfThree().ableToGet(x, y);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			int x                     = -6890;
			int y                     = 18252;
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = PowerOfThree().ableToGet(x, y);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 6: {
			int x                     = 1000000000;
			int y                     = -1000000000;
			string expected__         = "Impossible";

			clock_t start__           = clock();
			string received__         = PowerOfThree().ableToGet(x, y);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 7: {
			int x                     = 0;
			int y                     = 0;
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = PowerOfThree().ableToGet(x, y);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/

		// custom cases

      case 8: {
			int x                     = 39;
			int y                     = 1;
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = PowerOfThree().ableToGet(x, y);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 9: {
			int x                     = ;
			int y                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = PowerOfThree().ableToGet(x, y);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 10: {
			int x                     = ;
			int y                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = PowerOfThree().ableToGet(x, y);
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
