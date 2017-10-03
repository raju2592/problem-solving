/**
* SRM:597
* Div:1
* Point:250
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
map<string,int> d;

class LittleElephantAndString {
	public:
	int getNumber(string A, string B) {
	    int i,j,k,l;
        int a[26],b[26];
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(i=0;i<A.size();i++) a[A[i]-'A']++;
        for(i=0;i<B.size();i++) b[B[i]-'A']++;
        //cout<<"hu"<<endl;
        //for(i=0;i<26;i++) cout<<a[i]<<" "<<b[i]<<endl;
        for(i=0;i<26;i++) if(a[i]!=b[i]) return -1;
        int cur=A.size()-1;
        int found,done=0;
        for(i=B.size()-1;i>=0 && cur>=0;i--)
        {
            found=0;
            for(j=cur;j>=0;j--)
            {
                if(A[j]==B[i])
                {
                    found=1;
                    cur=j-1;
                    break;
                }
            }
            if(found)
            {
                //cout<<i<<" "<<cur<<endl;
                done++;
            }
            else break;
        }
        //cout<<done<<endl;
        return A.size()-done;
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
			string A                  = "ABC";
			string B                  = "CBA";
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = LittleElephantAndString().getNumber(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string A                  = "A";
			string B                  = "B";
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = LittleElephantAndString().getNumber(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string A                  = "AAABBB";
			string B                  = "BBBAAA";
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = LittleElephantAndString().getNumber(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string A                  = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			string B                  = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
			int expected__            = 25;

			clock_t start__           = clock();
			int received__            = LittleElephantAndString().getNumber(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string A                  = "A";
			string B                  = "A";
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = LittleElephantAndString().getNumber(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string A                  = "DCABA";
			string B                  = "DACBA";
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = LittleElephantAndString().getNumber(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string A                  = ;
			string B                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LittleElephantAndString().getNumber(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string A                  = ;
			string B                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LittleElephantAndString().getNumber(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string A                  = ;
			string B                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LittleElephantAndString().getNumber(A, B);
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
