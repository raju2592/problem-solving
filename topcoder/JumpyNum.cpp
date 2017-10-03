/**
*  SRM: 300
*  Div: 1
*  Point: 500
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
#include<string>
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
using namespace std;

ll Min(ll i,ll j){return i<j?i:j;}
ll Max(ll i,ll j){return i>j?i:j;}

vector<int> dig(int x)
{
    vector<int> ret;
    while(x)
    {
        ret.push_back(x%10);
        x/=10;
    }
    return ret;
}
int mmabs(int a){return a>0?a:-a;}
bool check(int x)
{
    int prev=x%10;x/=10;
    while(x)
    {
        if(mmabs(prev-x%10)<2) return false;
        prev=x%10;
        x/=10;
    }
    return true;
}
int get(int x)
{
    if(x==0) return 0;
    int dp[10][14],tot[14];
    int i,j,k,ret;
    vector<int> dd=dig(x);
    ret=0;
    for(i=0;i<=9;i++) dp[i][0]=1;
    ret=0;
    for(i=1;i<dd.size();i++)
    {
        tot[i]=0;
        for(j=0;j<=9;j++)
        {
            if(j) tot[i]+=dp[j][i-1];
            dp[j][i]=0;
            for(k=0;k<=9;k++)
            {
                //if(mmabs(k-j)<=2) continue;
                //if(k!=0) tot[i]+=dp[k][i-1];
                if(mmabs(k-j)>=2) dp[j][i]+=dp[k][i-1];
            }
            //tot[i]+=dp[j][i];
            //cout<<j<<" "<<i<<" "<<dp[j][i]<<endl;
        }
        //cout<<i<<" "<<tot[i]<<endl;
        ret+=tot[i];
    }
    //cout<<ret;
    reverse(dd.begin(),dd.end());
    for(i=0,j=dd.size()-1;i<dd.size();i++,j--)
    {
        //ret+=dp[dd[i]-'0'][j];
        for(k=(i==0?1:0);k<=dd[i]-1;k++)
        {
            //if(i!=0 && mmabs(k-dd[i-1]+'0'))
            if(i==0) ret+=dp[k][j];
            else
            {
                if(mmabs(k-dd[i-1])>=2) ret+=dp[k][j];
            }
        }
        if(i>0 && mmabs(dd[i]-dd[i-1])<2) break;
    }
    if(check(x)) ret++;
    return ret;
}
class JumpyNum {
	public:
	int howMany(int low, int high) {
        return get(high)-get(low-1);
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
			int low                   = 1;
			int high                  = 10;
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = JumpyNum().howMany(low, high);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int low                   = 9;
			int high                  = 23;
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = JumpyNum().howMany(low, high);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int low                   = 2000000000;
			int high                  = 2000000000;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = JumpyNum().howMany(low, high);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int low                   = 8000;
			int high                  = 20934;
			int expected__            = 3766;

			clock_t start__           = clock();
			int received__            = JumpyNum().howMany(low, high);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

      case 4: {
			int low                   = 1;
			int high                  = 15;
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = JumpyNum().howMany(low, high);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 5: {
			int low                   = ;
			int high                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = JumpyNum().howMany(low, high);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int low                   = ;
			int high                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = JumpyNum().howMany(low, high);
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
