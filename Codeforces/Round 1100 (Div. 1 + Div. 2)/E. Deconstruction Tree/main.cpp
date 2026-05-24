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
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define len(x) int(size(x))
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
const int INF = 1e9;
const int MAXN = 3e5;
const ll MOD = 998244353;

vvi g;
vi mxs;
vll dp;
vll pdp;
int mxleaf;

int dfs(int u, int p = -1) {
    bool c = false;
    for (int v : g[u]) if (v != p) {
        c = true;
        cmax(mxs[u], dfs(v, u));
    }
    if (!c) {
        cmax(mxleaf, u);
    }
    return max(mxs[u], u);
}

ll dfs2(int u, int x, int p = -1) {
    ll ans = x < u ? dp[u] : 0;
    for (int v : g[u]) if (v != p) {
        ans = (ans + dfs2(v, x, u)) % MOD;
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    g.assign(n, vi());
    mxs.assign(n, -1);
    mxleaf = -1;
    forn(_, n - 1) {
        int u, v; cin >> u >> v; --u; --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    if (len(g[n - 1]) == 1) {
        print(1);
        return;
    }
    dfs(n - 1);
    pii mx1 = {-1, -1};
    pii mx2 = {-1, -1};
    for (int v : g[n - 1]) {
        cmax(mx2, {max(v, mxs[v]), v});
        if (mx2 > mx1) swap(mx2, mx1);
    }
    dp.assign(n, 0);
    pdp.assign(n + 1, 0);
    dp[mxleaf] = 1;
    pdp[mxleaf + 1] = 1;
    for(int i = mxleaf + 1; i < n - 1; ++i) {
        int l = mxs[i];
        if (l < i) {
            dp[i] = (pdp[i] - pdp[l + 1] + MOD) % MOD;
        }
        pdp[i + 1] = (pdp[i] + dp[i]) % MOD;
    }
    ll ans = dfs2(mx1.se, mx2.fi);
    for (int v : g[n - 1]) if (v != mx1.se) {
        ans = (ans + dfs2(v, mx1.fi, n - 1)) % MOD;
    }
    print(ans);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
