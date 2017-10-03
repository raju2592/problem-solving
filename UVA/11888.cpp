#include<bits/stdc++.h>
using namespace std;

int zssrev[400009], zrevss[400009];

void calcz(string &str, int *z) {
    int n = str.size();
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(r < i) {
            l = r = i;
            while(r < n && str[r] == str[r - l]) r++;
            z[i] = r-l; r--;
        } else {
            if(z[i - l] < r - i + 1) z[i] = z[i - l];
            else {
                l = i;
                while(r < n && str[r] == str[r - l]) r++;
                z[i] = r-l; r--;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string ss;
        cin >> ss;
        string rev = ss;
        reverse(ss.begin(), ss.end());
        string ssrev = ss + "*" + rev;
        string revss = rev + "*" + ss;
        calcz(ssrev, zssrev);
        calcz(revss, zrevss);
        bool alindrome = false;
        int n = ss.size();
        int x = 2 * n + 1;
        for(int i = 0; i < n - 1; i++) {
            bool prefixpal = false, suffixpal = false;
            if(zssrev[x - i - 1] >= (i + 1) / 2) prefixpal = true;
            if(zrevss[n + i + 2] >= (n - i - 1) / 2) suffixpal = true;
            if(prefixpal && suffixpal) {
                alindrome = true;
                break;
            }
        }
        if(alindrome) cout << "alindrome\n";
        else {
            bool palindrome = true;
            for(int i = 0, j = n - 1; i < j; i++, j--)
                if(ss[i] != ss[j]) palindrome = false;
            if(palindrome) cout << "palindrome\n";
            else cout << "simple\n";
        }
    }
    return 0;
}
