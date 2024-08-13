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
    int n, q; cin >> n >> q;
    vi a(n, n);
    vvi g(n);
    forn1(i, n - 1) {
        cin >> a[i]; --a[i];
        g[i].pb(a[i]);
        g[a[i]].pb(i);
    }
    vi p(n);
    vi ip(n);
    vector<set<int>> s(n + 1);
    vi sz(n + 1, 0);
    forn(i, n) {
        cin >> p[i]; --p[i];
        ip[p[i]] = i;
        s[a[p[i]]].insert(i);
    }
    auto dfs = [&](auto dfs, int u, int t) -> int {
        for (int v : g[u]) if (v != t) {
            sz[u] += dfs(dfs, v, u);
        }
        return sz[u] + 1;
    };
    dfs(dfs, 0, -1);
    sz[n] = 1;
    auto check = [&](int i) -> bool {
        int v = p[i];
        if (s[v].empty()) return true;
        int mn = *s[v].begin();
        int mx = *s[v].rbegin();
        return mn > i && mx + sz[p[mx]] <= i + sz[v];
    };
    int c = 0;
    forn(i, n) {
        c += check(i);
    }
    forn(i, q) {
        int x, y; cin >> x >> y; --x; --y;
        set<int> e({x, y});
        if (p[x]) e.insert(ip[a[p[x]]]);
        if (p[y]) e.insert(ip[a[p[y]]]);
        for (int j : e) c -= check(j);
        s[a[p[x]]].erase(x);
        s[a[p[y]]].erase(y);
        s[a[p[x]]].insert(y);
        s[a[p[y]]].insert(x);
        swap(ip[p[x]], ip[p[y]]);
        swap(p[x], p[y]);
        for (int j : e) c += check(j);
        print(c == n ? "YES" : "NO");
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
