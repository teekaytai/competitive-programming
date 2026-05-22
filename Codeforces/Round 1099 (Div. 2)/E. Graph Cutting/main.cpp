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

int n, d;
vvi g;
ll ans;
vector<vll> dp1;
vector<vll> dp2;

void dfs(int u, int p = -1) {
    int mx1 = 1;
    int mx2 = 1;
    for (int v : g[u]) if (v != p) {
        dfs(v, u);
        cmax(mx1, len(dp1[v]) + 1);
        cmax(mx2, len(dp2[v]) + 1);
    }
    cmax(mx2, mx1);
    for (int v : g[u]) if (v != p) for (int w : g[u]) if (w != p && w > v) cmax(mx2, len(dp1[v]) + len(dp1[w]) + 1);
    dp1[u].assign(mx1, 0);
    dp2[u].assign(mx2, 0);
    for (int v : g[u]) if (v != p) {
        forn(i, len(dp1[v])) {
            dp1[u][i + 1] += dp1[v][i];
            dp2[u][i + 1] += dp1[v][i];
        }
        if (d - 1 < len(dp2[v])) ans += dp2[v][d - 1];
        forn(i, len(dp2[v])) {
            dp2[u][i + 1] += dp2[v][i];
        }
    }
    ll temp = 0;
    for (int v : g[u]) if (v != p) {
        for (int w : g[u]) if (w != p && w > v) {
            forn(i, len(dp1[v])) {
                int j = d - 2 - i;
                if (j >= 0 && j < len(dp2[w])) ans += dp1[v][i] * dp2[w][j];
                forn(j, len(dp1[w])) {
                    if (i + j + 2 == d) ans += dp1[v][i] * dp1[w][j];
                    else {
                        dp2[u][i + j + 2] += dp1[v][i] * dp1[w][j];
                        int k = d - i - j - 2;
                        if (k >= 0 && k < len(dp1[u])) {
                            ll x = dp1[u][k] - (k - 1 < len(dp1[v]) ? dp1[v][k - 1] : 0) - (k - 1 < len(dp1[w]) ? dp1[w][k - 1] : 0);
                            temp += dp1[v][i] * dp1[w][j] * x;
                        }
                    }
                }
            }
            forn(i, len(dp1[w])) {
                int j = d - 2 - i;
                if (j >= 0 && j < len(dp2[v])) ans += dp1[w][i] * dp2[v][j];
            }
        }
    }
    ans += temp / 3;
    ++dp1[u][0];
    if (len(dp1[u]) > d) dp1[u].resize(d);
    if (len(dp2[u]) > d) dp2[u].resize(d);
}

void solve() {
    cin >> n >> d; --d;
    g.assign(n, vi());
    forn(_, n - 1) {
        int u, v; cin >> u >> v;
        --u; --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    ans = 0;
    dp1.assign(n, vll());
    dp2.assign(n, vll());
    dfs(0);
    print(ans);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
