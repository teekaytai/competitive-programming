#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); ++i)
#define len(x) (int) x.size()

string s;
int memo[200][200];

int dp(int l, int r) {
    if (l == r) return 2;
    int& mn = memo[l][r];
    if (mn >= 0) return mn;
    mn = 3 + dp(l+1, r);
    if (s[l] == s[l+1]) mn = min(mn, 1+dp(l+1, r));
    for (int m = l+2; m <= r; ++m) if (s[l] == s[m]) {
        mn = min(mn, 2+dp(l+1, m-1)+dp(m, r));
    }
    return mn;
}

int main() {
    int n; cin >> n;
    cin.ignore();
    forn (i, n) {
        getline(cin, s);
        memset(memo, -1, sizeof(memo));
        cout << (1+dp(0, len(s)-1)) << "\n";
    }
}
