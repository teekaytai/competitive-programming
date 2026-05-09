#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef array<int, 3> a3i;
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
#define all(x2) begin(x2), end(x2)
#define rall(x2) rbegin(x2), rend(x2)
#define len(x2) int(size(x2))
#define LSB(x2) ((x2) & -(x2))
inline int MSB(int x2) { return x2 ? 1 << (31 - __builtin_clz(x2)) : 0; }
inline ll MSB(ll x2) { return x2 ? 1ll << (63 - __builtin_clzll(x2)) : 0ll; }
template<class T> constexpr void cmin(T& a, T b) { a = min(a, b); }
template<class T> constexpr void cmax(T& a, T b) { a = max(a, b); }
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    return os << "(" << p.fi << ", " << p.se << ")";
}

template <typename... Ts>
inline void print(const Ts&... args) {
    [[maybe_unused]] const char* sep = "";
    (((cout << sep << args), sep = " "), ...);
    cout << "\n";
}
template <typename It, typename = enable_if_t<is_base_of_v<input_iterator_tag, typename iterator_traits<It>::iterator_category>>>
inline void print(It b, It e) {
    for (auto it = b; it != e; ++it) cout << *it << " ";
    cout << "\n";
}
template <typename... Ts>
inline void printerr(const Ts&... args) {
    [[maybe_unused]] const char* sep = "";
    cerr << "\u001B[31m";
    (((cerr << sep << args), sep = " "), ...);
    cerr << "\u001B[0m" << endl;
}
template <typename It, typename = enable_if_t<is_base_of_v<input_iterator_tag, typename iterator_traits<It>::iterator_category>>>
inline void printerr(It b, It e) {
    cerr << "\u001B[31m{";
    if (b != e) {
        cerr << *b;
        for (auto it = next(b); it != e; ++it) cerr << ", " << *it;
    }
    cerr << "}\u001B[0m" << endl;
}

const double EPS = 1e-9;
const ll INF = 1e18;
const int MAXN = 3e5;
const ll MOD = 998244353;

vll a;
vvi g;
vector<vector<pll>> dp;

void dfs(int u, int p = -1) {
    if (a[u] > 0) dp[u].eb(a[u], INF);
    else dp[u].eb(INF, a[u]);
    for (int v : g[u]) if (v != p) {
        dfs(v, u);
        vector<pll> dp2(len(dp[u]) + len(dp[v]), {INF, INF});
        forn(i, len(dp[v])) {
            auto [x2, y2] = dp[v][i];
            forn(j, len(dp[u])) {
                auto [x, y] = dp[u][j];
                cmin(dp2[i + j].fi, x + x2);
                cmin(dp2[i + j].se, min({x + y2, y + x2, y + y2}));
                if (x2 < INF || y2 < 0) {
                    cmin(dp2[i + j + 1].fi, x);
                    cmin(dp2[i + j + 1].se, y);
                }
            }
        }
        dp[u] = std::move(dp2);
    }
}

void solve() {
    int n; cin >> n;
    a.resize(n);
    g.assign(n, vi());
    dp.assign(n, vector<pll>());
    forn(i, n) cin >> a[i];
    forn(_, n - 1) {
        int u, v; cin >> u >> v;
        --u; --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0);
    forn(i, n) if (dp[0][i].fi < INF || dp[0][i].se < 0){
        print(i);
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
