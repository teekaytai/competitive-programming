#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> t3i;
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
    const char* sep = "";
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
    const char* sep = "";
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

void solve() {
    int n, k; cin >> n >> k;
    vi ws(n);
    vi cs(n);
    vvi g(n, vi());
    forn(i, n) cin >> ws[i];
    forn(i, n) cin >> cs[i];
    forn(i, n - 1) {
        int u, v; cin >> u >> v;
        --u; --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    ll ans = 0;
    vector<uset<int>> ss(n);
    auto dfs = [&](auto& dfs, int u = 0, int p = -1) -> void {
        pii mx = {0, -1};
        if (len(g[u]) == 1 && g[u][0] == p) {
            if (cs[u] != 0) ss[u].insert(cs[u]);
            return;
        }
        for (int v : g[u]) if (v != p) {
            dfs(dfs, v, u);
            cmax(mx, {len(ss[v]), v});
        }
        int j = mx.se;
        bool b = false;
        for (int v : g[u]) if (v != p && v != j) {
            for (int x : ss[v]) {
                if (!b && ss[j].contains(x) && cs[u] != x) {
                    if (cs[u] == 0) cs[u] = x;
                    else b = true;
                }
                ss[j].insert(x);
            }
        }
        if (b) ans += ws[u];
        if (cs[u] == 0 && !ss[j].empty()) cs[u] = *ss[j].begin();
        if (cs[u] != 0) ss[j].insert(cs[u]);
        ss[u] = move(ss[j]);
    };
    dfs(dfs);
    if (cs[0] == 0) cs[0] = 1;
    auto dfs2 = [&](auto& dfs2, int c, int u = 0, int p = -1) -> void {
        if (cs[u] != 0) c = cs[u];
        else cs[u] = c;
        for (int v : g[u]) if (v != p) {
            dfs2(dfs2, c, v, u);
        }
    };
    dfs2(dfs2, cs[0]);
    print(ans);
    print(all(cs));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
