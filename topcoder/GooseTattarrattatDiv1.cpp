/**
*  SRM: 589
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

int par[26];

int find(int a)
{
    if(a==par[a]) return a;
    return par[a]=find(par[a]);
}
void uni(int a,int b)
{
    par[find(a)]=find(b);
}

class GooseTattarrattatDiv1 {
	public:
	int getmin(string S) {
	    int i,j;
        for(i=0;i<26;i++) par[i]=i;
        for(i=0,j=S.size()-1;i<j;i++,j--) uni(S[i]-'a',S[j]-'a');
        int cnt[26]={0};
        int mx[26]={0},tot[26]={0};
        for(i=0;i<S.size();i++)
        {
            cnt[S[i]-'a']++;
            tot[find(S[i]-'a')]++;
        }
        for(i=0;i<S.size();i++) mx[find(S[i]-'a')]=Max(mx[find(S[i]-'a')],cnt[S[i]-'a']);
        int ret=0;
        for(i=0;i<26;i++) ret+=tot[i]-mx[i];
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
			string S                  = "geese";
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = GooseTattarrattatDiv1().getmin(S);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string S                  = "tattarrattat";
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = GooseTattarrattatDiv1().getmin(S);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string S                  = "xyyzzzxxx";
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = GooseTattarrattatDiv1().getmin(S);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string S                  = "xrepayuyubctwtykrauccnquqfuqvccuaakylwlcjuyhyammag";
			int expected__            = 11;

			clock_t start__           = clock();
			int received__            = GooseTattarrattatDiv1().getmin(S);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string S                  = "abaabb";
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = GooseTattarrattatDiv1().getmin(S);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string S                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = GooseTattarrattatDiv1().getmin(S);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string S                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = GooseTattarrattatDiv1().getmin(S);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string S                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = GooseTattarrattatDiv1().getmin(S);
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
