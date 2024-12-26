#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vb> vvb;
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
template<class T> constexpr void cmin(T& a, T b) { a = min(a, b); }
template<class T> constexpr void cmax(T& a, T b) { a = max(a, b); }
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

const int MOD = 998244353;
const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;

void solve() {
    int n, q; cin >> n >> q;
    vi a(n);
    forn(i, n) cin >> a[i];
    vector<array<int, 51>> ps(n + 1);
    forn(i, n) {
        ps[i + 1] = ps[i];
        ++ps[i + 1][a[i]];
    }
    forn(_, q) {
        int l, r; cin >> l >> r;
        array<int, 51> c;
        forn(i, 51) c[i] = ps[r][i] - ps[l - 1][i];
        pii dp[2][64];
        pii dp2[2][64];
        memset(&dp, -1, sizeof(dp));
        dp[0][0] = {0, 1};
        forn(i, 51) {
            int x1 = c[i];
            if (x1 == 0) continue;
            int x2 = (ll) x1 * (x1 - 1) / 2 % MOD;
            memset(&dp2, -1, sizeof(dp2));
            forn(j, 2) forn (k, 64) if (dp[j][k].fi >= 0) {
                auto [u, v] = dp[j][k];
                pii& d1 = dp2[j][k];
                if (u + x1 > d1.fi) d1 = {u + x1, v};
                else if (u + x1 == d1.fi) d1.se = (d1.se + v) % MOD;
                pii& d2 = dp2[1][k ^ i];
                if (u + x1 - 1 > d2.fi) d2 = {u + x1 - 1, (ll) v * x1 % MOD};
                else if (u + x1 - 1 == d2.fi) d2.se = (d2.se + (ll) v * x1 % MOD) % MOD;
                if (x1 > 1) {
                    pii& d3 = dp2[1][k];
                    if (u + x1 - 2 > d3.fi) d3 = {u + x1 - 2, (ll) v * x2 % MOD};
                    else if (u + x1 - 2 == d3.fi) d3.se = (d3.se + (ll) v * x2 % MOD) % MOD;
                }
            }
            swap(dp, dp2);
        }
        dp[1][0].fi >= 0 ? print(dp[1][0].fi, dp[1][0].se) : print(-1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    // int tc; cin >> tc;
    // while (tc--) {
    solve();
    // }
}
