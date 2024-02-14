#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define forn(i, n) for (int i = 0; i < (n); ++i)

const ll INF = 2000000001;

int a[3000];
ll memo[3000][3000];

ll dp(int i, int s) {
    if (i==0) return a[0];
    if (i<s) return -INF;
    ll& m = memo[i][s];
    if (m==-INF) m = max(a[i]+dp(i-s,s), dp(i,s+1));
    return m;
}

int main() {
    int n; cin >> n;
    forn (i, n) cin >> a[i];
    forn (i, n) forn (j, n) memo[i][j] = -INF;
    cout << dp(n-1, 1) << "\n";
}
