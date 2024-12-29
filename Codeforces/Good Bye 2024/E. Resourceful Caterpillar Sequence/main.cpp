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

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;

int n;
vvi g;
vb isl;
vb is1l;
vb is2l;
vi c2l;

void dfs1(int u, int p = -1) {
    if (p != -1 && isl[p]) {
        is1l[u] = len(g[u]) > 1;
        is2l[u] = false;
    }
    for (int v : g[u]) if (v != p) {
        dfs1(v, u);
        c2l[u] += c2l[v];
        if (isl[v]) {
            is1l[u] = len(g[u]) > 1;
            is2l[u] = false;
        }
    }
    c2l[u] += is2l[u];
}

ll dfs2(int u, int c, int p = -1) {
    ll t = 0;
    if (p != -1 && !isl[p] && is1l[u]) {
        t += c2l[u] - is2l[u];
    }
    for (int v : g[u]) if (v != p) {
        t += dfs2(v, c + c2l[u] - c2l[v], u);
        if (!isl[v] && is1l[u]) {
            t += c + c2l[u] - c2l[v] - is2l[u];
        }
    }
    return t;
}

void solve() {
    cin >> n;
    g.assign(n, vi());
    forn(_, n-1) {
        int u, v; cin >> u >> v;
        --u; --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    isl.assign(n, false);
    is1l.assign(n, false);
    is2l.assign(n, true);
    c2l.assign(n, 0);
    forn(i, n) if (len(g[i]) == 1) {
        isl[i] = true;
        is2l[i] = false;
    }
    dfs1(0);
    int tl = 0;
    for (bool b : isl) tl += b;
    print(dfs2(0, 0) + (ll) tl * (n - tl));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
