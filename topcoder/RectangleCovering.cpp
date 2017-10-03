/**
*  SRM: 629
*  Div: 1
*  Point: 250
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


bool cmp(pair<int,int> a,pair<int,int> b)
{
    return a.second>b.second;
}
class RectangleCovering {
	public:
	int minimumNumber(int holeH, int holeW, vector <int> boardH, vector <int> boardW) {
		vector<pair<int,int> > pt,arr;
		int n,i,j,k;
		n=boardH.size();
		for(i=0;i<n;i++) pt.pb(mp(boardH[i],boardW[i]));
		for(i=0;i<n;i++)
		{
		    if(pt[i].first>holeH && pt[i].second>holeH)
		    {
		        int a=min(pt[i].first,pt[i].second);
		        int b=max(pt[i].first,pt[i].second);
		        pt[i].first=a;
		        pt[i].second=b;
		        arr.pb(mp(a,b));
		    }
		    else if(pt[i].second>holeH && pt[i].first<=holeH)
		    {
		        swap(pt[i].first,pt[i].second);
		        arr.pb(pt[i]);
		    }
		    else if(pt[i].first>holeH && pt[i].second<=holeH) arr.pb(pt[i]);
		}
		sort(arr.begin(),arr.end(),cmp);
		//for(i=0;i<arr.size();i++) cout<<arr[i].first<<" "<<arr[i].second;
		int x=0,y=0,kk=0;
		for(i=0;i<arr.size();i++)
		{
		    kk+=arr[i].second;
		    x++;
		    if(kk>=holeW) break;
		}
		int INF=n+500;
		if(kk<holeW) x=INF;
		//cout<<x<<endl;
		arr.clear();
		for(i=0;i<n;i++)
		{
		    if(pt[i].first>holeW && pt[i].second>holeW)
		    {
		        int a=min(pt[i].first,pt[i].second);
		        int b=max(pt[i].first,pt[i].second);
		        pt[i].first=a;
		        pt[i].second=b;
		        arr.pb(mp(a,b));
		    }
		    else if(pt[i].second>holeW && pt[i].first<=holeW)
		    {
		        swap(pt[i].first,pt[i].second);
		        arr.pb(pt[i]);
		    }
		    else if(pt[i].first>holeW && pt[i].second<=holeW) arr.pb(pt[i]);
		}
		sort(arr.begin(),arr.end(),cmp);
		y=0;kk=0;
		for(i=0;i<arr.size();i++)
		{
		    kk+=arr[i].second;
		    y++;
		    if(kk>=holeH) break;
		}
		if(kk<holeH) y=INF;
		if(min(x,y)==INF) return -1;
		return min(x,y);
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
			int holeH                 = 5;
			int holeW                 = 5;
			int boardH[]              = {8,8,8};
			int boardW[]              = {2,3,4};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = RectangleCovering().minimumNumber(holeH, holeW, vector <int>(boardH, boardH + (sizeof boardH / sizeof boardH[0])), vector <int>(boardW, boardW + (sizeof boardW / sizeof boardW[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int holeH                 = 10;
			int holeW                 = 10;
			int boardH[]              = {6,6,6,6};
			int boardW[]              = {6,6,6,6};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = RectangleCovering().minimumNumber(holeH, holeW, vector <int>(boardH, boardH + (sizeof boardH / sizeof boardH[0])), vector <int>(boardW, boardW + (sizeof boardW / sizeof boardW[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int holeH                 = 5;
			int holeW                 = 5;
			int boardH[]              = {5};
			int boardW[]              = {5};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = RectangleCovering().minimumNumber(holeH, holeW, vector <int>(boardH, boardH + (sizeof boardH / sizeof boardH[0])), vector <int>(boardW, boardW + (sizeof boardW / sizeof boardW[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int holeH                 = 3;
			int holeW                 = 5;
			int boardH[]              = {6};
			int boardW[]              = {4};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = RectangleCovering().minimumNumber(holeH, holeW, vector <int>(boardH, boardH + (sizeof boardH / sizeof boardH[0])), vector <int>(boardW, boardW + (sizeof boardW / sizeof boardW[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int holeH                 = 10000;
			int holeW                 = 5000;
			int boardH[]              = {12345,12343,12323,12424,1515,6666,6789,1424,11111,25};
			int boardW[]              = {1442,2448,42,1818,3535,3333,3456,7890,1,52};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = RectangleCovering().minimumNumber(holeH, holeW, vector <int>(boardH, boardH + (sizeof boardH / sizeof boardH[0])), vector <int>(boardW, boardW + (sizeof boardW / sizeof boardW[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int holeH                 = ;
			int holeW                 = ;
			int boardH[]              = ;
			int boardW[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RectangleCovering().minimumNumber(holeH, holeW, vector <int>(boardH, boardH + (sizeof boardH / sizeof boardH[0])), vector <int>(boardW, boardW + (sizeof boardW / sizeof boardW[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int holeH                 = ;
			int holeW                 = ;
			int boardH[]              = ;
			int boardW[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RectangleCovering().minimumNumber(holeH, holeW, vector <int>(boardH, boardH + (sizeof boardH / sizeof boardH[0])), vector <int>(boardW, boardW + (sizeof boardW / sizeof boardW[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int holeH                 = ;
			int holeW                 = ;
			int boardH[]              = ;
			int boardW[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RectangleCovering().minimumNumber(holeH, holeW, vector <int>(boardH, boardH + (sizeof boardH / sizeof boardH[0])), vector <int>(boardW, boardW + (sizeof boardW / sizeof boardW[0])));
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
