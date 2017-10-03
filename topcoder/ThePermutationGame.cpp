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
#include<set>
#include<string>
#include<utility>
#include<ctime>
#define ll long long
#define ull unsigned ll
#define pb push_back
#define mp make_pair
#define mod 1000000007
using namespace std;

ll Min(ll i,ll j){return i<j?i:j;}
ll Max(ll i,ll j){return i>j?i:j;}

ll np[100005];
vector<ll> primes;
void sieve()
{
    ll i;
    for(i=2;i*i<=100004;i++)
    {
        if(!np[i])
        {
            primes.pb(i);
            for(ll j=i;i*j<=100004;j++) np[i*j]=1;
        }
    }
    for(;i<=100004;i++) if(!np[i]) primes.pb(i);
}
/*ll bigmod(ll a,ll b)
{
    if(b==0) return 1;
    ll x=bigmod(a,b/2);
    if(b%2) return ((x*x)%mod)*a)%mod;
    return (x*x)%mod;
}*/

class ThePermutationGame {
	public:
	int findMin(int N) {
        ll ans=1;
        sieve();
        //cout<<"ok";
        for(ll i=0;primes[i]<=N && i<primes.size();i++)
        {
            ll x=primes[i];
            while(x<=N)
            {
                ans=(ans*primes[i])%mod;
                x*=primes[i];
            }
        }
        return (int)ans;
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
			int N                     = 2;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ThePermutationGame().findMin(N);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 3;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = ThePermutationGame().findMin(N);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 11;
			int expected__            = 504;

			clock_t start__           = clock();
			int received__            = ThePermutationGame().findMin(N);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 102;
			int expected__            = 841777601;

			clock_t start__           = clock();
			int received__            = ThePermutationGame().findMin(N);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 9999;
			int expected__            = 804862568;

			clock_t start__           = clock();
			int received__            = ThePermutationGame().findMin(N);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int N                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ThePermutationGame().findMin(N);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ThePermutationGame().findMin(N);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ThePermutationGame().findMin(N);
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
