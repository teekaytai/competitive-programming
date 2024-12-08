#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<bool> vb;
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

vvi g;
vi ps;
vi es;

void dfs(int u, int p = -1) {
    ps[u] = p;
    es[u] = 2 * (len(g[u]) - 1) + 1;
    for (int v : g[u]) if (v != p) {
        dfs(v, u);
    }
}

void solve() {
    int n, q; cin >> n >> q;
    g.assign(n, vi());
    ps.resize(n);
    es.resize(n);
    forn(i, n-1) {
        int u, v; cin >> u >> v;
        --u; --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0);
    forn(i, q) {
        int v, c; cin >> v >> c;
        --v;
        priority_queue<int, vi, greater<>> pq;
        int t = 0;
        int m = 0;
        int o = 0;
        while (v != 0) {
            if (o) {
                t += es[v];
                pq.push(es[v] - 1);
                m += es[v] - 1;
                if (len(pq) > c) {
                    m -= pq.top();
                    pq.pop();
                }
            } else ++t;
            v = ps[v];
            o = 1 - o;
        }
        print(t - m);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
