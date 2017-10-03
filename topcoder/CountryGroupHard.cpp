/** srm 653,
   div 1,
   250 point
   **/

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
#define uint unsigned int
#define pb push_back
#define mp make_pair
using namespace std;

int Min(int i,int j){return i<j?i:j;}
int Max(int i,int j){return i>j?i:j;}

int dp[105][105];

int calc(int pr,int st,vector<int> &arr)
{
    int &ret=dp[pr][st];
    if(dp[pr][st]!=-1) return dp[pr][st];
    if(st==arr.size())
    {
        if(pr<2) return ret=1;
        else return ret=2;
    }
    if(arr[st]==0) return ret=calc(pr+1,st+1,arr);
    ret=0;

    for(int i=0;i<=Min(arr[st]-1,pr);i++)
    {
        int j=arr[st]-1-i;
        if(st+j<arr.size())
        {
            cout<<j<<" ";
            bool b=true;
            for(int k=1;k<=j;k++) if(arr[st+k]!=arr[st] && arr[st+k]!=0) b=false;
            cout<<b<<endl;
            if(b)
            {
                int k=calc(0,st+j+1,arr);
                cout<<k<<endl;
                if(k>1) ret+=2;
                else if(k==1)
                {
                    if(pr-i<2) ret+=1;
                    else ret+=2;
                }
            }
        }
    }
    return ret;
}

class CountryGroupHard {
	public:
	string solve(vector <int> a) {
        memset(dp,-1,sizeof(dp));
        cout<<calc(0,0,a)<<endl;
        if(calc(0,0,a)==1) return "Sufficient";
        else return "Insufficient";
	}
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Iintegal input! Test case " << casenum << " does not exist." << endl;
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
			cerr << "Aint " << total << " tests passed!" << endl;
		}
	}

	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) {
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
			cerr << "    Expected: \"" << expected << "\"" << endl;
			cerr << "    Received: \"" << received << "\"" << endl;
		}

		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		/*case 0: {
			int a[]                   = {0,2,3,0,0};
			string expected__         = "Sufficient";

			clock_t start__           = clock();
			string received__         = CountryGroupHard().solve(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int a[]                   = {0,2,0};
			string expected__         = "Insufficient";

			clock_t start__           = clock();
			string received__         = CountryGroupHard().solve(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int a[]                   = {0,3,0,0,3,0};
			string expected__         = "Sufficient";

			clock_t start__           = clock();
			string received__         = CountryGroupHard().solve(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int a[]                   = {0,0,3,3,0,0};
			string expected__         = "Insufficient";

			clock_t start__           = clock();
			string received__         = CountryGroupHard().solve(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int a[]                   = {2,2,0,2,2};
			string expected__         = "Sufficient";

			clock_t start__           = clock();
			string received__         = CountryGroupHard().solve(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int a[]                   = {1};
			string expected__         = "Sufficient";

			clock_t start__           = clock();
			string received__         = CountryGroupHard().solve(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
      case 6: {
			int a[]                   = {0,0,3};
			string expected__         = "Sufficient";

			clock_t start__           = clock();
			string received__         = CountryGroupHard().solve(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 7: {
			int a[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = CountryGroupHard().solve(vector <int>(a, a + (sizeof a / sizeof a[0])));
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
	return 0;
}
// END CUT HERE
