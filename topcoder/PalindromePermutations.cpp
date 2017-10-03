/**
*  SRM: 625
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

double fact(int n)
{
    int i;
    double ret=1;
    for(i=1;i<=n;i++) ret*=i;
    return ret;
}

class PalindromePermutations {
	public:
	double palindromeProbability(string word) {
	    int cnt[30]={0};
	    int ev,od,i;
	    for(i=0;i<word.size();i++) cnt[word[i]-'a']++;
	    ev=od=0;
	    for(i=0;i<26;i++)
	    {
	        //cout<<cnt[i];
	        if(cnt[i]%2)
	        {
	            od++;
	            //cnt[i]--;
	        }
	        else ev++;
	    }
	    //cout<<ev<<od;
	    //for(i=0;i<26;i++) cout<<cnt[i];
	    if(od>1) return 0;
        double prb=1;
        for(i=0;i<26;i++)
        {
            //c
            prb*=fact(cnt[i]);
            //cout<<i<<" "<<cnt[i]<<" "<<prb<<endl;
        }
        //cout<<prb<<endl;
        prb/=fact(word.size());
        int tot=0;
        for(i=0;i<26;i++)
        {
            cnt[i]/=2;
            tot+=cnt[i];
        }
        prb*=fact(tot);
        for(i=0;i<26;i++) prb/=fact(cnt[i]);
        return prb;

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

	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ(double expected, double result) { if (isnan(expected)) { return isnan(result); } else if (isinf(expected)) { if (expected > 0) { return result > 0 && isinf(result); } else { return result < 0 && isinf(result); } } else if (isnan(result) || isinf(result)) { return false; } else if (fabs(result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }

	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) {
		cerr << "Example " << casenum << "... ";

		string verdict;
		vector<string> info;
		char buf[100];

		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}

		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received);
			if (rerr > 0) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			string word               = "haha";
			double expected__         = 0.3333333333333333;

			clock_t start__           = clock();
			double received__         = PalindromePermutations().palindromeProbability(word);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string word               = "xxxxy";
			double expected__         = 0.2;

			clock_t start__           = clock();
			double received__         = PalindromePermutations().palindromeProbability(word);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string word               = "xxxx";
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = PalindromePermutations().palindromeProbability(word);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string word               = "abcde";
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = PalindromePermutations().palindromeProbability(word);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string word               = "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhff";
			double expected__         = 0.025641025641025637;

			clock_t start__           = clock();
			double received__         = PalindromePermutations().palindromeProbability(word);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			string word               = "aabcc";
			double expected__         = 0.333333333333;

			clock_t start__           = clock();
			double received__         = PalindromePermutations().palindromeProbability(word);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 6: {
			string word               = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = PalindromePermutations().palindromeProbability(word);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string word               = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = PalindromePermutations().palindromeProbability(word);
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
