/**
*  SRM: 584
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


class Egalitarianism {
	public:
	int maxDifference(vector <string> isFriend, int d) {
	    queue<int> q;
	    int i,j,k;
	    int v[55]={0};
	    int dis[55]={0};
	    int ret=0,tmp;
	    for(int xx=0;xx<isFriend.size();xx++)
	    {
	        //cout<<"iteration "<<xx<<endl<<"_________________"<<endl;
	        memset(v,0,sizeof(v));
	        memset(dis,0,sizeof(dis));
	        //q.clear();
            q.push(xx);
            v[xx]=1;
            dis[xx]=0;
            tmp=0;
            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                //cout<<"u :"<< u<<endl;
                for(i=0;i<isFriend.size();i++)
                {
                    if(isFriend[u][i]=='Y' && !v[i])
                    {
                        dis[i]=dis[u]+d;
                        tmp=max(dis[i],tmp);
                        v[i]=1;
                        q.push(i);
                        //cout<<"i: "<<i<<" "<<dis[i]<<endl;
                    }
                }
            }
            for(i=0;i<isFriend.size();i++) if(!v[i]) return -1;
            ret=max(tmp,ret);
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
			string isFriend[]         = {"NYN", "YNY", "NYN"};
			int d                     = 10;
			int expected__            = 20;

			clock_t start__           = clock();
			int received__            = Egalitarianism().maxDifference(vector <string>(isFriend, isFriend + (sizeof isFriend / sizeof isFriend[0])), d);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string isFriend[]         = {"NN", "NN"};
			int d                     = 1;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = Egalitarianism().maxDifference(vector <string>(isFriend, isFriend + (sizeof isFriend / sizeof isFriend[0])), d);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string isFriend[]         = {"NNYNNN", "NNYNNN", "YYNYNN", "NNYNYY", "NNNYNN", "NNNYNN"};
			int d                     = 1000;
			int expected__            = 3000;

			clock_t start__           = clock();
			int received__            = Egalitarianism().maxDifference(vector <string>(isFriend, isFriend + (sizeof isFriend / sizeof isFriend[0])), d);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string isFriend[]         = {"NNYN", "NNNY", "YNNN", "NYNN"};
			int d                     = 584;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = Egalitarianism().maxDifference(vector <string>(isFriend, isFriend + (sizeof isFriend / sizeof isFriend[0])), d);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string isFriend[]         = {"NYNYYYN", "YNNYYYN", "NNNNYNN", "YYNNYYN", "YYYYNNN", "YYNYNNY", "NNNNNYN"};
			int d                     = 5;
			int expected__            = 20;

			clock_t start__           = clock();
			int received__            = Egalitarianism().maxDifference(vector <string>(isFriend, isFriend + (sizeof isFriend / sizeof isFriend[0])), d);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string isFriend[]         = {"NYYNNNNYYYYNNNN", "YNNNYNNNNNNYYNN", "YNNYNYNNNNYNNNN", "NNYNNYNNNNNNNNN", "NYNNNNYNNYNNNNN", "NNYYNNYNNYNNNYN", "NNNNYYNNYNNNNNN", "YNNNNNNNNNYNNNN", "YNNNNNYNNNNNYNN", "YNNNYYNNNNNNNNY", "YNYNNNNYNNNNNNN", "NYNNNNNNNNNNNNY", "NYNNNNNNYNNNNYN", "NNNNNYNNNNNNYNN", "NNNNNNNNNYNYNNN"} ;
			int d                     = 747;
			int expected__            = 2988;

			clock_t start__           = clock();
			int received__            = Egalitarianism().maxDifference(vector <string>(isFriend, isFriend + (sizeof isFriend / sizeof isFriend[0])), d);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 6: {
			string isFriend[]         = {"NY", "YN"};
			int d                     = 0;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = Egalitarianism().maxDifference(vector <string>(isFriend, isFriend + (sizeof isFriend / sizeof isFriend[0])), d);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			string isFriend[]         = ;
			int d                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Egalitarianism().maxDifference(vector <string>(isFriend, isFriend + (sizeof isFriend / sizeof isFriend[0])), d);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string isFriend[]         = ;
			int d                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Egalitarianism().maxDifference(vector <string>(isFriend, isFriend + (sizeof isFriend / sizeof isFriend[0])), d);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string isFriend[]         = ;
			int d                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Egalitarianism().maxDifference(vector <string>(isFriend, isFriend + (sizeof isFriend / sizeof isFriend[0])), d);
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
