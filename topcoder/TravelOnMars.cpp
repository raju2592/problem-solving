/**
*  SRM: 583
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

int mod(int a,int b){return (a%b+b)%b;}

class TravelOnMars {
	public:
	int minTimes(vector <int> range, int startCity, int endCity) {
	    vector<vector<int> > gr;
	    int n=range.size();
	    gr.resize(n);
	    for(int i=0;i<n;i++)
	    {
	        for(int j=1;j<=range[i];j++)
	        {
	            gr[i].pb(mod(i-j,n));
	            //gr[mod(i-j,n)].pb(i);
	            gr[i].pb(mod(i+j,n));
	            //gr[mod(i+j,n)].pb(i);
	        }
	    }
	    int d[55],v[55]={0};
	    queue<int> q;
	    d[startCity]=0;
	    v[startCity]=1;
	    q.push(startCity);
	    while(!q.empty())
	    {
	        int u=q.front();
	        q.pop();
	        //cout<<u<<" "<<d[u]<<endl;
	        if(u==endCity) return d[endCity];
	        for(int i=0;i<gr[u].size();i++)
	        {
	            if(!v[gr[u][i]])
	            {
	                v[gr[u][i]]=1;
	                d[gr[u][i]]=d[u]+1;
	                q.push(gr[u][i]);
	            }
	        }
	    }
	    //return d[endCity];
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

		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			int range[]               = {2, 1, 1, 1, 1, 1};
			int startCity             = 1;
			int endCity               = 4;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TravelOnMars2().minTimes(vector <int>(range, range + (sizeof range / sizeof range[0])), startCity, endCity);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int range[]               = {2, 1, 1, 2, 1, 2, 1, 1};
			int startCity             = 2;
			int endCity               = 6;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = TravelOnMars2().minTimes(vector <int>(range, range + (sizeof range / sizeof range[0])), startCity, endCity);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int range[]               = {3, 2, 1, 1, 3, 1, 2, 2, 1, 1, 2, 2, 2, 2, 3};
			int startCity             = 6;
			int endCity               = 13;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = TravelOnMars2().minTimes(vector <int>(range, range + (sizeof range / sizeof range[0])), startCity, endCity);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int range[]               = {2, 4, 2, 3, 4, 1, 4, 2, 5, 4, 3, 3, 5, 4, 5, 2, 2, 4, 4, 3, 3, 4, 2, 3, 5, 4, 2, 4, 1, 3, 2, 3, 4, 1, 1, 4, 4, 3, 5, 3, 2, 1, 4, 1, 4};
			int startCity             = 24;
			int endCity               = 8;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = TravelOnMars2().minTimes(vector <int>(range, range + (sizeof range / sizeof range[0])), startCity, endCity);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int range[]               = ;
			int startCity             = ;
			int endCity               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TravelOnMars2().minTimes(vector <int>(range, range + (sizeof range / sizeof range[0])), startCity, endCity);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int range[]               = ;
			int startCity             = ;
			int endCity               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TravelOnMars2().minTimes(vector <int>(range, range + (sizeof range / sizeof range[0])), startCity, endCity);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int range[]               = ;
			int startCity             = ;
			int endCity               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TravelOnMars2().minTimes(vector <int>(range, range + (sizeof range / sizeof range[0])), startCity, endCity);
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
