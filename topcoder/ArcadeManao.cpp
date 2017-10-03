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

#define INF 20000000
#define ll long long
#define ull unsigned ll
#define pb push_back
#define mp make_pair
using namespace std;
int max(int i,int j){return i>j?i:j;}
class ArcadeManao {
	public:
	int shortestLadder(vector <string> level, int coinRow, int coinColumn) {
	    coinRow--;
	    coinColumn--;
	    int d[55][55];
	    int R=level.size();
	    int C=level[0].size();
	    int i,j;
	    for(i=0;i<55;i++)
	    {
	        for(j=0;j<55;j++) d[i][j]=INF;

	    }
		d[R-1][0]=0;
		set<pair<int,pair<int,int> > > pq;
		pq.insert(mp(0,mp(R-1,0)));
		pair<int,int> u;
		int x,y;
		while(!pq.empty())
		{
            u=pq.begin()->second;
            if(u.first==coinRow && u.second==coinColumn) return pq.begin()->first;
            pq.erase(pq.begin());
            x=u.first,y=u.second;
            if(y+1<C && level[x][y+1]=='X' && d[x][y]<d[x][y+1])
            {
                pq.erase(mp(d[x][y+1],mp(x,y+1)));
                d[x][y+1]=d[x][y];
                pq.insert(mp(d[x][y+1],mp(x,y+1)));
            }
            if(y-1>=0 && level[x][y-1]=='X' && d[x][y]<d[x][y-1])
            {
                pq.erase(mp(d[x][y-1],mp(x,y-1)));
                d[x][y-1]=d[x][y];
                pq.insert(mp(d[x][y-1],mp(x,y-1)));
            }
            for(i=1;x+i<R;i++)
            {
                if(level[x+i][y]=='X')
                {
                    if(d[x+i][y]>max(d[x][y],i))
                    {
                        pq.erase(mp(d[x+i][y],mp(x+i,y)));
                        d[x+i][y]=max(d[x][y],i);
                        pq.insert(mp(d[x+i][y],mp(x+i,y)));
                    }
                    break;
                }
            }
            for(i=1;x-i>=0;i++)
            {
                if(level[x-i][y]=='X')
                {
                    if(d[x-i][y]>max(d[x][y],i))
                    {
                        pq.erase(mp(d[x-i][y],mp(x-i,y)));
                        d[x-i][y]=max(d[x][y],i);
                        pq.insert(mp(d[x-i][y],mp(x-i,y)));
                    }
                    break;
                }
            }
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
			string level[]            = {"XXXX....", "...X.XXX", "XXX..X..", "......X.", "XXXXXXXX"};
			int coinRow               = 2;
			int coinColumn            = 4;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ArcadeManao().shortestLadder(vector <string>(level, level + (sizeof level / sizeof level[0])), coinRow, coinColumn);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string level[]            = {"XXXX", "...X", "XXXX"};
			int coinRow               = 1;
			int coinColumn            = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = ArcadeManao().shortestLadder(vector <string>(level, level + (sizeof level / sizeof level[0])), coinRow, coinColumn);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string level[]            = {"..X..", ".X.X.", "X...X", ".X.X.", "..X..", "XXXXX"};
			int coinRow               = 1;
			int coinColumn            = 3;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = ArcadeManao().shortestLadder(vector <string>(level, level + (sizeof level / sizeof level[0])), coinRow, coinColumn);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string level[]            = {"X"};
			int coinRow               = 1;
			int coinColumn            = 1;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = ArcadeManao().shortestLadder(vector <string>(level, level + (sizeof level / sizeof level[0])), coinRow, coinColumn);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string level[]            = {"XXXXXXXXXX", "...X......", "XXX.......", "X.....XXXX", "..XXXXX..X", ".........X", ".........X", "XXXXXXXXXX"};
			int coinRow               = 1;
			int coinColumn            = 1;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ArcadeManao().shortestLadder(vector <string>(level, level + (sizeof level / sizeof level[0])), coinRow, coinColumn);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

      /*case 5: {
			string level[]            = {"XXX","X.X","..X","XXX"};
			int coinRow               = 3;
			int coinColumn            = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = ArcadeManao().shortestLadder(vector <string>(level, level + (sizeof level / sizeof level[0])), coinRow, coinColumn);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
      /*case 0: {
			string level[]            ={"XX","XX"} ;
			int coinRow               = 1;
			int coinColumn            = 2;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = ArcadeManao().shortestLadder(vector <string>(level, level + (sizeof level / sizeof level[0])), coinRow, coinColumn);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string level[]            = ;
			int coinRow               = ;
			int coinColumn            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ArcadeManao().shortestLadder(vector <string>(level, level + (sizeof level / sizeof level[0])), coinRow, coinColumn);
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
