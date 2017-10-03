/**
*  SRM: 624
*  Div: 1
*  Point: 450
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
#define ll long //long
#define uint unsigned int
#define pb push_back
#define mp make_pair
#define ii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int> >
#define vvii vector<vector< ii > >
#define INF 2000000000//0000LL
#define mod 1000000009
using namespace std;

int Min(int i,int j){return i<j?i:j;}
int Max(int i,int j){return i>j?i:j;}


class DrivingPlans {
	public:
	int count(int N, vector <int> A, vector <int> B, vector <int> C) {
        vvii gr;
        gr.resize(N+1);
        for(int i=0;i<A.size();i++)
        {
            gr[A[i]].pb(mp(B[i],C[i]));
            gr[B[i]].pb(mp(A[i],C[i]));
        }
        set<pair<ll,ll> > pq;
        ll cnt[2005],d[2005];
        memset(cnt,0,sizeof(cnt));
        cnt[1]=1;
        d[1]=0;
        for(ll i=2;i<=N;i++) d[i]=INF;
        pq.insert(mp(0,1));
        while(!pq.empty())
        {
            ii x=*(pq.begin());
            ll u=x.second;
            //cout<<u<<" "<<gr[u].size()<<endl;
            pq.erase(pq.begin());
            for(ll i=0;i<gr[u].size();i++) if(gr[u][i].second==0) cnt[u]=INF;
            for(ll i=0;i<gr[u].size();i++)
            {
                //if(gr[u][i].second==0) cnt[u]=INF;
                ll v=gr[u][i].first;
                //cout<<v<<endl;
                if(d[u]+gr[u][i].second<d[v])
                {
                    pq.erase(mp(d[v],v));
                    d[v]=(d[u]+gr[u][i].second);
                    pq.insert(mp(d[v],v));
                    cnt[v]=cnt[u];
                }
                else if(d[u]+gr[u][i].second==d[v])
                {
                    if(cnt[u]<INF && cnt[v]<INF) cnt[v]=(cnt[v]+cnt[u])%mod;
                    else cnt[v]=INF;
                }
            }
        }
        if(cnt[N]<INF) return cnt[N]%mod;
        return -1;
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
			int N                     = 5;
			int A[]                   = {1, 1, 2, 3, 1, 2} ;
			int B[]                   = {2, 5, 5, 5, 3, 4};
			int C[]                   = {1, 2, 1, 1, 1, 0};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = DrivingPlans().count(N, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(C, C + (sizeof C / sizeof C[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 4;
			int A[]                   = {1,1,2,3};
			int B[]                   = {2,3,4,4};
			int C[]                   = {1,1,1,0};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = DrivingPlans().count(N, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(C, C + (sizeof C / sizeof C[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 7;
			int A[]                   = {1,1,2,3,4,4,5,6};
			int B[]                   = {2,3,4,4,5,6,7,7};
			int C[]                   = {1,1,2,2,3,3,4,4};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = DrivingPlans().count(N, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(C, C + (sizeof C / sizeof C[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			int N                     = ;
			int A[]                   = ;
			int B[]                   = ;
			int C[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DrivingPlans().count(N, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(C, C + (sizeof C / sizeof C[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			int N                     = ;
			int A[]                   = ;
			int B[]                   = ;
			int C[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DrivingPlans().count(N, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(C, C + (sizeof C / sizeof C[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int N                     = ;
			int A[]                   = ;
			int B[]                   = ;
			int C[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DrivingPlans().count(N, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(C, C + (sizeof C / sizeof C[0])));
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
