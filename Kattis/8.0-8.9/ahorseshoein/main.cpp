#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forn1(i, n) for (int i = 1; i <= (n); ++i)
#define fi first
#define se second

const ll INF = LLONG_MAX;
const int MAXN = 4000;
const int MAXK = 80;

pll pts[MAXN + MAXK + 2];
ll A[MAXN + MAXK][MAXK + 1];
ll best = 0;
int best_i = -1;
int best_ps[MAXN + 1][MAXK + 1];
ll dp[MAXN][MAXK + 1];
int ps[MAXN + 1][MAXK + 1];

ll area(pll& p1, pll& p2, pll& p3) {
    return p1.fi * p2.se - p1.se * p2.fi + p2.fi * p3.se - p2.se * p3.fi + p3.fi * p1.se - p3.se * p1.fi;
}

void solve() {
    int n, K; cin >> n >> K;
    K = n - K;
    if (K == 0) {
        forn1(i, n) cout << i << " ";
        cout << "\n";
        return;
    }
    forn(i, n) cin >> pts[i].fi >> pts[i].se;
    forn(i, K + 2) pts[n + i] = pts[i];
    for(int i = K; i < n + K; ++i) {
        ll ta = 0;
        forn1(j, K) {
            ta += area(pts[i + 1], pts[i - j + 1], pts[i - j]);
            A[i][j] = ta;
        }
    }
    forn(i, K) copy(A[n + i], A[n + i] + K + 1, A[i]);
    forn(i, K) for(int k = i + 1; k <= K; ++k) dp[i][k] = -INF;
    forn(i, K + 1) {
        forn1(j, n - 1) {
            forn1(k, min(j, K)) {
                ll mx = dp[j - 1][k];
                int best_p = 0;
                forn1(p, k) {
                    ll x = dp[max(j - p - 1, 0)][k - p] + A[i + j - 1][p];
                    if (x > mx) {
                        mx = x;
                        best_p = p;
                    }
                }
                dp[j][k] = mx;
                ps[j][k] = best_p;
            }
        }
        if (dp[n - 1][K] > best) {
            best = dp[n - 1][K];
            best_i = i;
            swap(best_ps, ps);
        }
    }
    int x = n - 1;
    int y = K;
    while (x >= 0) {
        int p = best_ps[x][y];
        if (p == 0) {
            cout << (best_i + x - 1 + n) % n + 1 << " ";
            --x;
        } else {
            x -= p + 1;
            y -= p;
            cout << (best_i + x + n) % n + 1 << " ";
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
