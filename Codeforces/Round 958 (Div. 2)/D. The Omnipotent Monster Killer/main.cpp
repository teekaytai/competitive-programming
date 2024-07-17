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
const ll INF = 4e18;
const int MAXN = 3e5;

vll a;
vvi g;

vll dfs(int u, int p = -1) {
    vll dp(20, 0);
    forn(i, 20) dp[i] += a[u] * (i + 1);
    for (int v : g[u]) if (v != p) {
        vll dp2 = dfs(v, u);
        forn (i, 20) {
            ll mn = INF;
            forn (j, 20) if (j != i) {
                mn = min(mn, dp2[j]);
            }
            dp[i] += mn;
        }
    }
    return dp;
}

void solve() {
    int n; cin >> n;
    a.resize(n);
    forn(i, n) cin >> a[i];
    g.assign(n, vi());
    forn(i, n-1) {
        int u, v; cin >> u >> v; --u; --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vll res = dfs(0);
    print(*min_element(all(res)));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
