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

vector<vpii> sts(MAXN);
vvi g;
vvi cs;
vector<uset<int>> ds;
int t;
map<pii, int> m;

void dfs(int u, int p = -1) {
    for (int c : cs[u]) {
        int d;
        if (!sts[c].empty() && sts[c].back().fi == p) {
            d = sts[c].back().se;
        } else {
            d = t++;
        }
        ds[u].insert(d);
        sts[c].eb(u, d);
    }
    for (int v : g[u]) if (v != p) {
        dfs(v, u);
    }
    for (int c : cs[u]) {
        sts[c].pop_back();
    }
}

void solve() {
    int n, k, s, q; cin >> n >> k >> s >> q;
    t = 0;
    g.assign(n, vi());
    cs.assign(n, vi());
    ds.assign(n, {});
    m.clear();
    forn(i, n - 1) {
        int u, v; cin >> u >> v;
        --u; --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    forn(i, s) {
        int v, c; cin >> v >> c;
        --v; --c;
        cs[v].pb(c);
    }
    dfs(0);
    forn(_, q) {
        int u, v; cin >> u >> v;
        --u; --v;
        if (u == v) {
            cout << len(ds[u]) << " ";
            continue;
        }
        if (u > v) swap(u, v);
        auto it = m.find({u, v});
        if (it == m.end()) {
            int x = 0;
            uset<int>& d1 = ds[u];
            uset<int>& d2 = ds[v];
            if (len(d1) <= len(d2)) for (int d : d1) x += d2.contains(d);
            else for (int d : d2) x += d1.contains(d);
            m[{u, v}] = x;
            cout << x << " ";
        } else {
            cout << it->se << " ";
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
