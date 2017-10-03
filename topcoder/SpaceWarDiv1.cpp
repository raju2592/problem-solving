/**
*  SRM: 582
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


class SpaceWarDiv1 {
	public:
	vector<int> arr;
	vector<pair<ll,ll> > ene;
	long long minimalFatigue(vector <int> magicalGirlStrength, vector <int> enemyStrength, vector<long long> enemyCount) {
	    ll i,j,k,l,r,m;
	    arr=magicalGirlStrength;
	    ene.resize(enemyStrength.size());
	    for(i=0;i<ene.size();i++) ene[i].first=enemyStrength[i],ene[i].second=enemyCount[i];
	    sort(arr.begin(),arr.end());
	    sort(ene.begin(),ene.end());
	    if(ene[ene.size()-1].first>arr[arr.size()-1]) return -1;
	    l=1,r=50LL*100000000000000LL;
	    while(r-l>1)
	    {
	        m=(l+r)/2;
	        if(check(m)) r=m;
	        else l=m;
	    }
	    if(check(l)) return l;
	    else return r;
	}
	bool check(ll val)
	{
	    ll st=0,rem=ene[0].second,tmp,i;
	    tmp=val;
	    i=0;
	    while(i<arr.size())
	    {
	        if(arr[i]<ene[st].first)
	        {
	            i++;
	            tmp=val;
	            continue;
	        }
	        if(rem>tmp)
	        {
	            i++;
	            rem-=tmp;
	            tmp=val;
	        }
	        else if(rem==tmp)
	        {
	            st++;
	            if(st==ene.size()) return true;
	            rem=ene[st].second;
	            i++;
	            tmp=val;
	        }
	        else if(rem<tmp)
	        {
	            st++;
	            if(st==ene.size()) return true;
	            tmp-=rem;
	            rem=ene[st].second;
	        }
	    }
	    return false;
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

	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) {
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
			int magicalGirlStrength[] = {2, 3, 5};
			int enemyStrength[]       = {1, 3, 4};
			long long enemyCount[]    = {2, 9, 4};
			long long expected__      = 7;

			clock_t start__           = clock();
			long long received__      = SpaceWarDiv1().minimalFatigue(vector <int>(magicalGirlStrength, magicalGirlStrength + (sizeof magicalGirlStrength / sizeof magicalGirlStrength[0])), vector <int>(enemyStrength, enemyStrength + (sizeof enemyStrength / sizeof enemyStrength[0])), vector<long long>(enemyCount, enemyCount + (sizeof enemyCount / sizeof enemyCount[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int magicalGirlStrength[] = {2, 3, 5};
			int enemyStrength[]       = {1, 1, 2};
			long long enemyCount[]    = {2, 9, 4};
			long long expected__      = 5;

			clock_t start__           = clock();
			long long received__      = SpaceWarDiv1().minimalFatigue(vector <int>(magicalGirlStrength, magicalGirlStrength + (sizeof magicalGirlStrength / sizeof magicalGirlStrength[0])), vector <int>(enemyStrength, enemyStrength + (sizeof enemyStrength / sizeof enemyStrength[0])), vector<long long>(enemyCount, enemyCount + (sizeof enemyCount / sizeof enemyCount[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int magicalGirlStrength[] = {14, 6, 22};
			int enemyStrength[]       = {8, 33};
			long long enemyCount[]    = {9, 1};
			long long expected__      = -1;

			clock_t start__           = clock();
			long long received__      = SpaceWarDiv1().minimalFatigue(vector <int>(magicalGirlStrength, magicalGirlStrength + (sizeof magicalGirlStrength / sizeof magicalGirlStrength[0])), vector <int>(enemyStrength, enemyStrength + (sizeof enemyStrength / sizeof enemyStrength[0])), vector<long long>(enemyCount, enemyCount + (sizeof enemyCount / sizeof enemyCount[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int magicalGirlStrength[] = {869, 249, 599, 144, 929, 748, 665, 37, 313, 99, 33, 437, 308, 137, 665, 834, 955, 958, 613, 417};
			int enemyStrength[]       = {789, 57, 684, 741, 128, 794, 542, 367, 937, 739, 568, 872, 127, 261, 103, 763, 864, 360, 618, 307};
			long long enemyCount[]    = {20626770196420LL, 45538527263992LL, 52807114957507LL, 17931716090785LL, 65032910980630LL, 88711853198687LL, 26353250637092LL, 61272534748707LL, 89294362230771LL, 52058590967576LL, 60568594469453LL, 23772707032338LL, 43019142889727LL, 39566072849912LL, 78870845257173LL, 68135668032761LL, 36844201017584LL, 10133804676521LL, 6275847412927LL, 37492167783296LL};
			long long expected__      = 75030497287405LL;

			clock_t start__           = clock();
			long long received__      = SpaceWarDiv1().minimalFatigue(vector <int>(magicalGirlStrength, magicalGirlStrength + (sizeof magicalGirlStrength / sizeof magicalGirlStrength[0])), vector <int>(enemyStrength, enemyStrength + (sizeof enemyStrength / sizeof enemyStrength[0])), vector<long long>(enemyCount, enemyCount + (sizeof enemyCount / sizeof enemyCount[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int magicalGirlStrength[] = ;
			int enemyStrength[]       = ;
			long long enemyCount[]    = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = SpaceWarDiv1().minimalFatigue(vector <int>(magicalGirlStrength, magicalGirlStrength + (sizeof magicalGirlStrength / sizeof magicalGirlStrength[0])), vector <int>(enemyStrength, enemyStrength + (sizeof enemyStrength / sizeof enemyStrength[0])), vector<long long>(enemyCount, enemyCount + (sizeof enemyCount / sizeof enemyCount[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int magicalGirlStrength[] = ;
			int enemyStrength[]       = ;
			long long enemyCount[]    = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = SpaceWarDiv1().minimalFatigue(vector <int>(magicalGirlStrength, magicalGirlStrength + (sizeof magicalGirlStrength / sizeof magicalGirlStrength[0])), vector <int>(enemyStrength, enemyStrength + (sizeof enemyStrength / sizeof enemyStrength[0])), vector<long long>(enemyCount, enemyCount + (sizeof enemyCount / sizeof enemyCount[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int magicalGirlStrength[] = ;
			int enemyStrength[]       = ;
			long long enemyCount[]    = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = SpaceWarDiv1().minimalFatigue(vector <int>(magicalGirlStrength, magicalGirlStrength + (sizeof magicalGirlStrength / sizeof magicalGirlStrength[0])), vector <int>(enemyStrength, enemyStrength + (sizeof enemyStrength / sizeof enemyStrength[0])), vector<long long>(enemyCount, enemyCount + (sizeof enemyCount / sizeof enemyCount[0])));
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
