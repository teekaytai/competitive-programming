#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
#define umap unordered_map
#define uset unordered_set
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forn1(i, n) for (int i = 1; i <= (n); ++i)
#define rforn(i, n) for (int i = (n) - 1; i >= 0; --i)
#define rforn1(i, n) for (int i = (n); i > 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define len(x) (int) (x).size()
#define LSB(x) ((x) & -(x))
inline int MSB(int x) { return x ? 1 << (31 - __builtin_clz(x)) : 0; }
inline ll MSB(ll x) { return x ? 1ll << (63 - __builtin_clzll(x)) : 0ll; }
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

template <typename... Ts>
inline void print(const Ts&... args) {
    const char* sep = "";
    (((cout << sep << args), sep = " "), ...);
    cout << "\n";
}
template <typename T>
inline void print(const vector<T>& v) {
    for (auto x : v) cout << x << " ";
    cout << "\n";
}
template <typename... Ts>
inline void printerr(const Ts&... args) {
    const char* sep = "";
    cerr << "\u001B[31m";
    (((cerr << sep << args), sep = " "), ...);
    cerr << "\u001B[0m" << endl;
}
template <typename T>
inline void printerr(const vector<T>& v) {
    cerr << "\u001B[31m";
    for (auto x : v) cerr << x << " ";
    cerr << "\u001B[0m" << endl;
}

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;

void solve() {
    int n, m; cin >> n >> m;
    vvi g(n+1, vi(m+1));
    forn(r, n) {
        int x = 0;
        forn(c, m) {
            cin >> g[r][c];
            x ^= g[r][c];
        }
        g[r][m] = x;
    }
    forn(c, m + 1) {
        int x = 0;
        forn(r, n) {
            x ^= g[r][c];
        }
        g[n][c] = x;
    }
    vector<vll> rs(n+1, vll(n+1));
    forn (r1, n+1) forn(r2, r1) {
        ll t = 0;
        forn (c, m+1) {
            t += abs(g[r1][c] - g[r2][c]);
        }
        rs[r1][r2] = t;
        rs[r2][r1] = t;
    }
    vector<vll> cs(m+1, vll(m+1));
    forn (c1, m+1) forn(c2, c1) {
        ll t = 0;
        forn (r, n+1) {
            t += abs(g[r][c1] - g[r][c2]);
        }
        cs[c1][c2] = t;
        cs[c2][c1] = t;
    }
    ll T = LONG_LONG_MAX;
    forn(R, n+1) {
        vi rows(n);
        forn(i, n) rows[i] = i + (i >= R);
        forn(C, m+1) {
            vi cols(m);
            forn(i, m) cols[i] = i + (i >= C);

            vector<vll> dp(n, vll(1 << n));
            forn1(s, (1 << n) - 1) {
                forn(i, n) if (!(s & (1 << i))) {
                    ll mn = LONG_LONG_MAX;
                    int S = s;
                    while (S) {
                        int b = MSB(S);
                        int j = __builtin_ctz(b);
                        mn = min(mn, dp[j][s - b] + rs[rows[i]][rows[j]] - abs(g[rows[i]][C] - g[rows[j]][C]));
                        S -= b;
                    }
                    dp[i][s] = mn;
                }
            }
            vector<vll> dp2(m, vll(1 << m));
            forn1(s, (1 << m) - 1) {
                forn(i, m) if (!(s & (1 << i))) {
                    ll mn = LONG_LONG_MAX;
                    int S = s;
                    while (S) {
                        int b = MSB(S);
                        int j = __builtin_ctz(b);
                        mn = min(mn, dp2[j][s - b] + cs[cols[i]][cols[j]] - abs(g[R][cols[i]] - g[R][cols[j]]));
                        S -= b;
                    }
                    dp2[i][s] = mn;
                }
            }
            ll mn = LONG_LONG_MAX;
            forn (i, n) {
                mn = min(mn, dp[i][(1 << n) - 1 - (1 << i)]);
            }
            ll mn2 = LONG_LONG_MAX;
            forn (i, m) {
                mn2 = min(mn2, dp2[i][(1 << m) - 1 - (1 << i)]);
            }
            T = min(T, mn + mn2);
        }
    }
    print(T);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
