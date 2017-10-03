/**
*  SRM: 550
*  Div: 2
*  Point: 1000
*/

#include<string>
#include<cstdio>
#include<ctime>
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
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
using namespace std;

ll min(ll i,ll j){return i<j?i:j;}
ll max(ll i,ll j){return i>j?i:j;}

int gr[100][100],v;
int vis[100];

class TopView {
	public:
	string findOrder(vector <string> grid) {
	    int n=grid.size(),m=grid[0].size();
	    map<char,int> pos;
	    map<int,char> ch;
	    vector<char> dist;
	    int x=0,i,j,k;
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<m;j++)
	        {
	            if(grid[i][j]=='.') continue;
	            if(pos[grid[i][j]]) continue;
	            x++;
	            pos[grid[i][j]]=x;
	            ch[x]=grid[i][j];
	            dist.pb(grid[i][j]);
	        }
	    }
		//for(i=0;i<n;i++) cout<<grid[i]<<endl;
	    map<char,int> rmax,rmin,cmax,cmin;
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<m;j++)
	        {
	            if(rmax[grid[i][j]]==0) rmax[grid[i][j]]=i+1;
	            else rmax[grid[i][j]]=max(rmax[grid[i][j]],i+1);
	            if(rmin[grid[i][j]]==0) rmin[grid[i][j]]=i+1;
	            else rmin[grid[i][j]]=min(rmin[grid[i][j]],i+1);
	            if(cmax[grid[i][j]]==0) cmax[grid[i][j]]=j+1;
	            else cmax[grid[i][j]]=max(cmax[grid[i][j]],j+1);
	            if(cmin[grid[i][j]]==0) cmin[grid[i][j]]=j+1;
	            else cmin[grid[i][j]]=min(cmin[grid[i][j]],j+1);

	        }
	    }
	    int p,q;
	    memset(gr,0,sizeof(gr));
	    for(i=0;i<dist.size();i++)
	    {
	        for(p=rmin[dist[i]]-1;p<rmax[dist[i]];p++)
	        {
	            for(q=cmin[dist[i]]-1;q<cmax[dist[i]];q++)
	            {
	                if(grid[p][q]=='.') return "ERROR!";
	                if(grid[p][q]!=dist[i]) gr[pos[dist[i]]][pos[grid[p][q]]]=1;
	            }
	        }
	    }
	    int indeg[150]={0};
	    v=dist.size();
	    for(i=1;i<=v;i++)
	    {
	        for(j=1;j<=v;j++)
	        {
	            if(gr[i][j]) indeg[j]++;
	        }
	    }
		//for(i=0;i<dist.size();i++) cout<<dist[i]<<" ";
		/*for(i=1;i<=v;i++)
	    {
	        for(j=1;j<=v;j++) cerr<<gr[i][j];
	        cerr<<endl;
	    }*/
	    //memset(vis,0,sizeof(vis));
	    //if(!dfs(1)) return "ERROR!";

	    set<char> pq;
	    for(i=1;i<=v;i++) if(indeg[i]==0) pq.insert(ch[i]);
	    string ret="";
	    while(!pq.empty())
	    {
	        char cc=*(pq.begin());
	        pq.erase(pq.begin());
	        int x=pos[cc];
            ret+=cc;
            for(i=1;i<=v;i++) if(gr[x][i])
            {
                indeg[i]--;
                if(indeg[i]==0) pq.insert(ch[i]);
            }
	    }
	    if(ret.size()==dist.size()) return ret;
	    else return "ERROR!";
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
			string grid[]             = {"..AA..", ".CAAC.", ".CAAC."};
			string expected__         = "CA";

			clock_t start__           = clock();
			string received__         = TopView().findOrder(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string grid[]             = {"..47..", "..74.."} ;
			string expected__         = "ERROR!";

			clock_t start__           = clock();
			string received__         = TopView().findOrder(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string grid[]             = {"bbb666", ".655X5", "a65AA5", "a65AA5", "a65555"};
			string expected__         = "65AXab";

			clock_t start__           = clock();
			string received__         = TopView().findOrder(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string grid[]             = {"aabbaaaaaaaaaaaaaaaaaa", "aabbccccccccccccccaaaa", "aab11111ccccccccccaaaa", "aab12221ccccccccccaaaa", "aab12221ccccccccccaaaa", "aab12221ccccccccccaaaa", "aab12221ccccccccccaaaa", "aab12221ccccccccccaaaa", "aab12221ddddddddddaaaa", "aab13331DDDDDDDDDDaaaa", "aab13331DDDDDDDDDDaaaa", "aa.11111DDDDDDDDDDaaaa", "aaaaaaaaaaaaaaaaaaaaaa"};
			string expected__         = "ERROR!";

			clock_t start__           = clock();
			string received__         = TopView().findOrder(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/

		// custom cases

      case 0: {
			string grid[]             = {".................bbbbbbbbbbbbb......", ".................bbbbbbbbbbbbb......", ".................bbbbbbbbbbbbb....KK", "kkkkkkkkkkkkkkkkkbbbbbbbbbbbbb....KK", "kkkkkkkkkkkkkkkkkbbbbbbbbbbbbb....KK", "kkkkkkkkkmkkkkkkkbbbbbbbbbbbbb....KK", "kkkAkkkkkkkkkkkkkbbbbbbbbbbbbb....KK", "kkkkkkkkkkkkkkkkkbbbbbbbbbbbbb....KK", "kkkkkkkkkkkkkkkkkbbbbbbbbbbbbbOO..KK", "kkkkkkkkkkkkWWWWobbbbbbbbbbbbbOO..KK", "kkkkkkkkkkkkWWWWWbbbbbbbbbbbbbOO..KK", "kkkkkkkkkkkkWWWWrbbbbbbbbbbbbbOO..KK", "kkkkkkkkkkkkWWWWWbbbbbbbbbbbbbOO.PPP", "kkkkkkkkkkkkWWWWWbbbbbbbbbbbbbOO.PPP", "kkkkkkkkkkk666666bbbbbbbbbbbbbOO.PPP", "kkkkkkkkkkk666666bbbbbbbbbbbbbOO.PPP", "kkkkkkkkkkk666666bbbbbbbbbbbbbOO.PPP", "kkkkkkkkkkk666666bbbbbbbbbbbbbOO.PPP", "kkkkkkkkkkk666666bbbbbbbbbbbbbOO.PPP", "kkkkkkkkkkk666666bbbbbbbbbbbbbOO.PPP", "kkkkkkkkkkk666666bbbbbbbbbbbbbOO.PPP", "kkkkkkkk333666666bbbbbbbbbbbbbOO.PPP", "ooooooooooooooooobbbbbbbbbbbbbOO.PPP", "oooooVVVVVVVVVVVVbbbbbbbbbbbbbOOZPPP", "oooooVVVVVVVVVVVVbbbbbbbbbbbbbOOppPP", "ooooooooooooooooobbbbbbbbbbbbbOOppPP", "oooooooooooooooo2bbbbbbbbbbbbbOOppPP", "ooooooooooooooooobbbbbbbbbbbbbOOppPP", "ooooooomooooooooobbbbbbbbbbbbbOOppPP", "ooooooooooooooooobbbbbbbbbbbbbOOppPP", "ooooooooooooooooobbbbbbbbbbbbbOOppPP", "ooooooooooooooooobbbbbbbbbbbbbOOppPP", "ooooooooooooooooobbbbbbbbbbbbbppppKK", "ooooooooooooooooobbbbbbbbbbbbbppppKK", "ooooooooooooooooobbbbbbbbbbbbbppppKK", "ooooooooooooooooobbbbbbbbbbbbbppppKK", "ooooooooooooooooobbbbbbbbbbbbbppppKK", "ooooooooooooooooobbbbbbbbbbbbbppppKK", "ooooooooooooooooobbbbbbbbbbbbbppppKK", "ooooooooooooooooobbbbbbbbbbbbbppppKK", "ooooooooooooooooobbbbbbbbbbbbbppppKK", "ooooooooooooooooobbbbbbbbbbbbbppppKK", "ooooooooooooooooobbbbbbbbbbbbbZZZQKK", "...9999999999999qbbbbbbbbbbbbb....KK", "...9999999999999qbbbbbbbbbbbbb....KK", ".................bbbbbbbbbbbbb......"};
			string expected__         = "ERROR!";

			clock_t start__           = clock();
			string received__         = TopView().findOrder(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 5: {
			string grid[]             = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TopView().findOrder(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string grid[]             = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TopView().findOrder(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
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
