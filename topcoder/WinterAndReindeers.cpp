/**
*  SRM: 601
*  Div: 2
*  Point: 1000
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

string sa,sb,sc;
int st[2505][2505],en[2505][2505];

int  calc1(int a,int b)
{
    if(a<0 || b<0) return 0;
    if(st[a][b]!=-1) return st[a][b];
    if(sa[a]==sb[b]) return st[a][b]=1+calc1(a-1,b-1);
    st[a][b]=max(calc1(a-1,b),calc1(a,b-1));
    return st[a][b];
}
int calc2(int a,int b)
{
    if(a>=sa.size() || b>=sb.size()) return 0;
    if(en[a][b]!=-1) return en[a][b];
    if(sa[a]==sb[b]) return en[a][b]=1+calc2(a+1,b+1);
    en[a][b]=max(calc2(a+1,b),calc2(a,b+1));
    return en[a][b];
}

class WinterAndReindeers {
	public:
	int getNumber(vector <string> allA, vector <string> allB, vector <string> allC) {
        sa="";
        sb="";
        sc="";
        int i,j,k;
        for(i=0;i<allA.size();i++) sa+=allA[i];
        for(i=0;i<allB.size();i++) sb+=allB[i];
        for(i=0;i<allC.size();i++) sc+=allC[i];
        memset(st,-1,sizeof(st));
        memset(en,-1,sizeof(en));
        for(i=0;i<sa.size();i++)
        {
            for(j=0;j<sb.size();j++)
            {
                calc2(i,j);
                calc1(i,j);
            }
        }
        vector<pair<int,int> > va,vb;
        for(i=0;i<sa.size();i++)
        {
            if(sa[i]!=sc[0]) continue;
            int len=0,cur=0;
            for(j=i;j<sa.size();j++)
            {
                if(sa[j]==sc[cur])
                {
                    len++;
                    cur++;
                    if(len==sc.size())
                    {
                        va.pb(mp(i-1,j+1));
                        break;
                    }
                }
            }
        }
        for(i=0;i<sb.size();i++)
        {
            if(sb[i]!=sc[0]) continue;
            int len=0,cur=0;
            for(j=i;j<sb.size();j++)
            {
                if(sb[j]==sc[cur])
                {
                    len++;
                    cur++;
                    if(len==sc.size())
                    {
                        vb.pb(mp(i-1,j+1));
                        break;
                    }
                }
            }
        }
        if(va.empty() || vb.empty())
        {
            //cout<<"HU";
            return 0;
        }
        int ret=sc.size(),tmp=-1;
        //cout<<va[0].first<<" "<<va[0].second<<enl;
        //cout<<vb[0].first<<" "<<vb[0].second<<enl;
        for(i=0;i<va.size();i++)
        {
            for(j=0;j<vb.size();j++)
            {
                tmp=max(tmp,calc1(va[i].first,vb[j].first)+calc2(va[i].second,vb[j].second));
            }
        }
        ret+=tmp;
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
			string allA[]             = {"X"};
			string allB[]             = {"X", "Y"};
			string allC[]             = {"X"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = WinterAndReindeers().getNumber(vector <string>(allA, allA + (sizeof allA / sizeof allA[0])), vector <string>(allB, allB + (sizeof allB / sizeof allB[0])), vector <string>(allC, allC + (sizeof allC / sizeof allC[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string allA[]             = {"ABCXD"};
			string allB[]             = {"BCDEF"};
			string allC[]             = {"CD"};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = WinterAndReindeers().getNumber(vector <string>(allA, allA + (sizeof allA / sizeof allA[0])), vector <string>(allB, allB + (sizeof allB / sizeof allB[0])), vector <string>(allC, allC + (sizeof allC / sizeof allC[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string allA[]             = {"WE", "LOVE"};
			string allB[]             = {"WORKING", "FOR", "SANTA"};
			string allC[]             = {"JK"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = WinterAndReindeers().getNumber(vector <string>(allA, allA + (sizeof allA / sizeof allA[0])), vector <string>(allB, allB + (sizeof allB / sizeof allB[0])), vector <string>(allC, allC + (sizeof allC / sizeof allC[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string allA[]             = {"ABCDE"};
			string allB[]             = {"CDEAB"};
			string allC[]             = {"B"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = WinterAndReindeers().getNumber(vector <string>(allA, allA + (sizeof allA / sizeof allA[0])), vector <string>(allB, allB + (sizeof allB / sizeof allB[0])), vector <string>(allC, allC + (sizeof allC / sizeof allC[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string allA[]             = {"ABCABDEGAXAHDJBAAHFJDXBB", "ABHFHCDALFDJDBBA", "BABBAXAXXX"};
			string allB[]             = {"ABLOCBAXBAHAJDXBIJKA", "JBABCDAHKFIUDALPJAH", "AABACX"};
			string allC[]             = {"AXBADXBBAB", "CDD"};
			int expected__            = 23;

			clock_t start__           = clock();
			int received__            = WinterAndReindeers().getNumber(vector <string>(allA, allA + (sizeof allA / sizeof allA[0])), vector <string>(allB, allB + (sizeof allB / sizeof allB[0])), vector <string>(allC, allC + (sizeof allC / sizeof allC[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string allA[]             = ;
			string allB[]             = ;
			string allC[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WinterAndReindeers().getNumber(vector <string>(allA, allA + (sizeof allA / sizeof allA[0])), vector <string>(allB, allB + (sizeof allB / sizeof allB[0])), vector <string>(allC, allC + (sizeof allC / sizeof allC[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string allA[]             = ;
			string allB[]             = ;
			string allC[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WinterAndReindeers().getNumber(vector <string>(allA, allA + (sizeof allA / sizeof allA[0])), vector <string>(allB, allB + (sizeof allB / sizeof allB[0])), vector <string>(allC, allC + (sizeof allC / sizeof allC[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string allA[]             = ;
			string allB[]             = ;
			string allC[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WinterAndReindeers().getNumber(vector <string>(allA, allA + (sizeof allA / sizeof allA[0])), vector <string>(allB, allB + (sizeof allB / sizeof allB[0])), vector <string>(allC, allC + (sizeof allC / sizeof allC[0])));
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
