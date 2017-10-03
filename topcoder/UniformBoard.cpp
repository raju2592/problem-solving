/**
*  SRM: 223
*  Div: 1
*  Point: 300
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


class UniformBoard {
	public:
	int getBoard(vector <string> board, int K) {
        int n,td,tp,ta,cd,cp,ca;
        vector<string> &arr=board;
        n=board.size();
        td=tp=ta=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[i][j]=='.') td++;
                if(arr[i][j]=='A') ta++;
                if(arr[i][j]=='P') tp++;
            }
        }
        //cout<<td<<" "<<tp<<" "<<ta<<endl;
        int ret=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int a=1;i+a<=n;a++)
                {
                    for(int b=1;j+b<=n;b++)
                    {
                        ca=cd=cp=0;
                        for(int x=i;x<i+a;x++)
                        {
                            for(int y=j;y<j+b;y++)
                            {
                                if(arr[x][y]=='.') cd++;
                                if(arr[x][y]=='A') ca++;
                                if(arr[x][y]=='P') cp++;
                            }
                        }
                        //if(ta-ca<cp+cd) continue;
                        //if(td-cd<cp) continue;
                        //if(cp>K) continue;
                        if(ta<a*b) continue;
                        //if(2*cp+cd>K) continue;
                        if(cp>0 && td==0) continue;
                        if(2*cp+cd>K) continue;
                        ret=max(ret,a*b);
                    }
                }
            }
        }
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
			string board[]            = {"AP", ".A"};
			int K                     = 0;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = UniformBoard().getBoard(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string board[]            = {"AP", ".A"};
			int K                     = 1;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = UniformBoard().getBoard(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string board[]            = {"PPP", "APA", "A.P"};
			int K                     = 2;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = UniformBoard().getBoard(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string board[]            = {"AAA", "PPP", "AAA"};
			int K                     = 10;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = UniformBoard().getBoard(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string board[]            = {"."};
			int K                     = 1000;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = UniformBoard().getBoard(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string board[]            = {"PPAAPA..AP", "PPA.APAP..", "..P.AA.PPP", "P.P..APAA.", "P.P..P.APA", "PPA..AP.AA", "APP..AAPAA", "P.P.AP...P", ".P.A.PAPPA", "..PAPAP..P"};
			int K                     = 10;
			int expected__            = 15;

			clock_t start__           = clock();
			int received__            = UniformBoard().getBoard(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string board[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = UniformBoard().getBoard(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string board[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = UniformBoard().getBoard(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string board[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = UniformBoard().getBoard(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
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
