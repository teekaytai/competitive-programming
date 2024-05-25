#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
#define umap unordered_map
#define uset unordered_set
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forn1(i, n) for (int i = 1; i <= (n); ++i)
#define rforn(i, n) for (int i = (n) - 1; i >= 0; --i)
#define rforn1(i, n) for (int i = (n); i > 0; --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define len(x) (int) x.size()
#define LSB(x) ((x) & -(x))
inline int MSB(int x) { return x ? 1 << (31 - __builtin_clz(x)) : 0; }
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

vvi g;
vi ps;
vi c;
vi xs;

void solve() {
    int n, q; cin >> n >> q;
    g.assign(n, vi());
    ps.resize(n);
    c.assign(n+1, 0);
    xs.assign(n+1, 0);
    forn(i, n) cin >> c[i];
    forn(i, n-1) {
        int u, v; cin >> u >> v;
        --u; --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    ps[0] = n;
    int b = 0;
    int wp = 0;
    set<int> t;
    auto dfs = [&](auto dfs, int u, int p) -> int {
        b += c[u];
        wp += c[u] & ~c[p];
        for (int v : g[u]) if (v != p) {
            ps[v] = u;
            xs[u] += dfs(dfs, v, u);
        }
        if (c[u] && xs[u] >= 2) t.insert(u);
        return c[u];
    };
    dfs(dfs, 0, n);
    forn(_, q) {
        int u; cin >> u; --u;
        int p = ps[u];
        if (c[u]) {
            --b;
            wp += xs[u] - (c[p]==0);
            if (xs[u] >= 2) t.erase(u);
            if (--xs[p] == 1 && c[p]) t.erase(p);
        } else {
            ++b;
            wp += (c[p]==0) - xs[u];
            if (xs[u] >= 2) t.insert(u);
            if (++xs[p] == 2 && c[p]) t.insert(p);
        }
        c[u] = 1 - c[u];
        print(b && wp == 1 && (t.empty() || len(t) == 1 && c[ps[*t.begin()]] == 0 && xs[*t.begin()] == 2) ? "Yes" : "No");
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
