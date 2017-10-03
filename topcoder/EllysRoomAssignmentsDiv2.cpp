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
#include<utility>
#include<ctime>
#include<set>
#include<string>
#include<bitset>
#include<iomanip>
#include<complex>
#include<numeric>
#include<valarray>
#include<sstream>
#include<deque>


#define ll long long
#define ull unsigned ll
#define pb push_back
#define mkp make_pair
using namespace std;
bool cmp(int a,int b)
	{
	    return a>b;
	}
class EllysRoomAssignmentsDiv2 {
	public:
	double getProbability(vector <string> ratings) {
	    vector<int> arr;
	    int i,j,k;
	    string st="";
	    for(i=0;i<ratings.size();i++) st+=ratings[i];
	    stringstream ss(st);
	    while(ss>>j) arr.pb(j);
	    k=arr[0];
	    sort(arr.begin(),arr.end(),cmp);
	    int pos;
	    for(i=0;i<arr.size();i++) if(arr[i]==k)
	    {
	        pos=i+1;
	        break;
	    }
	    //for(i=0;i<arr.size();i++) cout<<arr[i]<<' ';
	    //cout<<endl;
	    int room;
	    cout<<arr.size()<<' ';
	    if(arr.size()%20==0)
	    {
	        room=arr.size()/20;
	    }
	    else
	    {
	        room=arr.size()/20+1;
	    }
	    //cout<<room<<' '<<pos<<endl;
	    if(pos==1) return 1;
	    else if(pos<=room) return 0;
	    //return (double)1/room;
	    double ret=(double) 1/room;
	    ret=ret*ret;
	    ret=ret*room;
	    return ret;
	}
	//return 0.0;

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
			string ratings[]          = {"724 42 13 17 1199 577 1001 1101 483 845 196 1163 3", "60 985 296 1044 917 1007 898 119 1016 23 56 1159 1", "194 372 951 991 947 1053 433 1017 1011 391 110 9 2", "30 245 788 830 747 2 3"};
			double expected__         = 0.3333333333333333;

			clock_t start__           = clock();
			double received__         = EllysRoomAssignmentsDiv2().getProbability(vector <string>(ratings, ratings + (sizeof ratings / sizeof ratings[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string ratings[]          = {"42 911 666 17 13 1 1155 1094 815 5 1000 540"};
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = EllysRoomAssignmentsDiv2().getProbability(vector <string>(ratings, ratings + (sizeof ratings / sizeof ratings[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string ratings[]          = {"1168 196 440 643 227 1194 1149 372 878 23 767 296 ", "110 52 840 367 790 884 620 676 380 1007 304 262 10", "63 917 230 951 635 898 894 319 724 597 470 1143 62", "7 1175 436 484 457 991 433 747 8 94 830 1044 1053 ", "360 1167 391 364 1120 192 56 528 366 712 480 83 11", "59 483 949 356 1163 9 845 750 781 784 1016 985 346", " 466 947 73 911 690 630 609 866 788 98 1017 410 11", "9 617 245 801 205"};
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = EllysRoomAssignmentsDiv2().getProbability(vector <string>(ratings, ratings + (sizeof ratings / sizeof ratings[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string ratings[]          = {"470 840 410 1168 637 464 498 1118 276 1013 989 874", " 64 192 296 611 44 999 583 365 1195 20 838 274 425", " 236 960 1116 857 630 664 98 1046 807 1111 529 47 ", "31 676 1112 42 376 56 1105 814 6 871 364 319 1145 ", "491 199 1121 713 353 956 579 445 1031 627 618 202 ", "763 271 188 1140 1044 311 895 1175 74 465 454 708 ", "1181 866 387 99 784 700 308 853 977 253 62 782 371", " 8 908 1151 83 932 55 1077 897 517 767 990 567 869", " 607 603 499 356 772 310 332 357 845 1159 1128 104", "2 783 953 315 1020 360 696 793 847 1 716 731 1097 ", "660 302 761 484 23 89 609 161 978 312 87 363 879 6", "02 635 409 749 475 106 632 961 1053 414 422 1146 6", "51 970 907 719 110 118 218 471 334 747 645 575 757", " 156 137 101 150 1084 48 859 1016 396 779 791 195 ", "1148 138 141 304 523 1129 940 569 1058 113 949 967", " 261 1017 433 126 205 679 998 325 831 239 774 245 ", "992 407 991 667 489 580 628 1055 383 924 706 369 8", "37 380 596 392 734 183 397 1165 911 657 1028 617 1", "45 105 870 707 447 281 841 526 367 297 66 851 643 ", "1142 168 480 3 347 1101 737 1025 647 588 1049 458 ", "508 759 654 927 744 937 402 440 1158 620 1067 528 ", "1001 1186 705 124 511 597 395 1063 399 753 1093 10", "05 717 1173 278 81 762 71 51 801 890 1185 413 674 ", "252 805 775 52 612 1075 1187 131 559 72 1141 298 8", "5 640 1184 290 1127 423 925 1108 114 864 605 802 1", "39 962 104 817 289 816 359 323 1068 368 477 1022 2", " 377 512 688 1029 340 28 1193 910 417 984 1163 385", " 858 212 119 898 9 473 180 140 346 262 971 170 564", " 226 123 698 196 10 466 1174 446 248 1194 227 94 3", "09 850 1179 1035 680 750 67 650 765 61 982 412 736", " 149 822 933 621 117 1062 678 929 693 125 836 852 ", "694 711 275 358 524 825 997 372 781 873 725 818 57", "1 1041 460 796 287 723 142 322 691 220 830 778 116", "7 68 1059 1011 958 324 200 947 29 216 57 443 488 9", "85 666 690 1182 230 1114 153 73 1086 191 1010 586 ", "250 96 211 40 217 1155 82 641 1066 1131 896 154 22", "4 5 951 917 1189 709 777 1034 724 436 626 270 1052", " 593 50 926 901 634 1082 943 894 721 945 366 391 4", "27 646 1076 712 496 868 435 1120 177 1149 330 483 ", "1152 351 176 457 1126 235 1143 790 780 1166 686 80", " 121 222 305 355 581 476 34 533 147 316 881 539 45", " 146 263 22 788 527 519 1069 710 59 148 234 661 81", "3 1081 133 884 548 405 344 451 887 789 1007 295 39", "8 728 553 642 878 77 293 684 877 554 478"};
			double expected__         = 0.037037037037037035;

			clock_t start__           = clock();
			double received__         = EllysRoomAssignmentsDiv2().getProbability(vector <string>(ratings, ratings + (sizeof ratings / sizeof ratings[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string ratings[]          = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = EllysRoomAssignmentsDiv2().getProbability(vector <string>(ratings, ratings + (sizeof ratings / sizeof ratings[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string ratings[]          = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = EllysRoomAssignmentsDiv2().getProbability(vector <string>(ratings, ratings + (sizeof ratings / sizeof ratings[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string ratings[]          = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = EllysRoomAssignmentsDiv2().getProbability(vector <string>(ratings, ratings + (sizeof ratings / sizeof ratings[0])));
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
