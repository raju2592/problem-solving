/**
*  SRM: 632 round 1
*  Div: 1
*  Point: 300
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
#define ll long //long
#define ull unsigned ll
#define pb push_back
#define mp make_pair
#define ii pair<ll,ll>
#define vi vector<ll>
#define vvi vector<vector<ll> >
#define vvii vector<vector< ii > >
#define INF 20000000
using namespace std;

ll Min(ll i,ll j){return i<j?i:j;}
ll Max(ll i,ll j){return i>j?i:j;}

int n;

/*bool possible(int a,int b,vector<int> &d)
{
    vector<pair<ll,ll> > num;
    if(d[a]==0) num.pb(mp(1,1));
    else
    {
        num.pb(1,1);
        num.pb(0,d[a]);
    }
    bool ret=true;
    int i,j,k;
    for(i=a+1;i<=b;i++)
    {
        k=num.size()-1;
        if(num[k].second==0)
        {
            if(num[k].first==1)
            {
                num.pop_back();
                num[num.size()-1]++;
            }
            else
            {
                num[k].first--;
                num.pb(mp(1,1));
            }
        }
        else if(num[k].second==1)
        {
            if(num.size()==1)
            {
                ll x=num.pop_back();
                num.pb(mp(1,1));
                num.pb(mp(x,0));
            }
            else
            {
                ll x=num.pop_back();
                ll y=num.pop_back();
                ll z=num.pop_back();
                if(y==1)
                {
                    num.pb(mp(z+1,1));
                    num.pb(mp(x,0));
                }
                else
                {
                    num.pb(mp(z,1));
                    num.pb(mp(y-1,0));
                    num.pb(mp(1,1));
                    num.pb(mp(x,0));
                }
            }
        }
        if(num[num.size()-1].second==1 && d[i]>0)
        {
            ret=false;
            break;
        }
        else if()
    }
    return ret;
}*/

bool check(ll x)
{
    int i,j;
    for(i=31;i>=0;i--)
    {
        if(x & (1<<i))
        {
            for(j=i-1;j>=0;j--)
            {
                if(!(x & (1<<j))) return false;
            }
            return true;
        }
    }
}

int zeros(ll x)
{
    int i,ret=0;
    for(i=0;i<32;i++)
    {
        if(x & (1<<i)) return ret;
        else ret++;
    }
}

bool possible(int a,int b,vector<int> &d)
{
    ll x,i,lz;
    if(a==b) return true;
    if(b==a+1)
    {
        if((d[a]==0 && d[b]!=0) || (d[a]!=0 && d[b]==0)) return true;
        else return false;
    }
    if(d[a]>30) x=1<<30;
    else x=1<<d[a];
    lz=d[a];
    bool ret=true;
    for(i=a+1;i<=b;i++)
    {
        if(check(x))
        {
            if(d[i]>0)
            {
                if(d[i]<=lz)
                {
                    ret=false;
                    break;
                }
                else lz=d[i];
                if(d[i]>30) x=1<<30;
                else x=1<<d[i];
            }
            else
            {
                ret=false;
                break;
            }
        }
        else
        {
            x++;
            if(zeros(x)!=d[i])
            {
                ret=false;
                break;
            }
        }
    }
	return ret;
}

class PotentialArithmeticSequence {
	public:
	int numberOfSubsequences(vector <int> d) {
        n=d.size();
        int i,j,k,ret=0;
        for(i=0;i<n;i++)
        {
            for(j=i;j<n;j++)
				if(possible(i,j,d)) ret++;
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
			int d[]                   = {0,1,0,2,0,1,0};
			int expected__            = 28;

			clock_t start__           = clock();
			int received__            = PotentialArithmeticSequence().numberOfSubsequences(vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int d[]                   = {0,0,0,0,0,0,0};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = PotentialArithmeticSequence().numberOfSubsequences(vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int d[]                   = {0,0,0,0,1,1,1};
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = PotentialArithmeticSequence().numberOfSubsequences(vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int d[]                   = {0,100,0,2,0};
			int expected__            = 11;

			clock_t start__           = clock();
			int received__            = PotentialArithmeticSequence().numberOfSubsequences(vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int d[]                   = {1,11,3,0,1,0,1,0,1,0,1,0,3,0,2,0,0,0,0,1,2,3,20};
			int expected__            = 49;

			clock_t start__           = clock();
			int received__            = PotentialArithmeticSequence().numberOfSubsequences(vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int d[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PotentialArithmeticSequence().numberOfSubsequences(vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int d[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PotentialArithmeticSequence().numberOfSubsequences(vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int d[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PotentialArithmeticSequence().numberOfSubsequences(vector <int>(d, d + (sizeof d / sizeof d[0])));
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
