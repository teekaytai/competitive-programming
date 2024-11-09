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

vector<set<int>> g;

void solve() {
    int n, m; cin >> n >> m;
    vector<tuple<int, int, int>> ops;
    g.assign(n, set<int>());
    forn(i, m) {
        int u, v; cin >> u >> v; --u; --v;
        g[u].insert(v);
        g[v].insert(u);
    }
    forn (i, n) {
        while (len(g[i]) >= 2) {
            int u = *g[i].begin();
            g[i].erase(u);
            g[u].erase(i);
            int v = *g[i].begin();
            g[i].erase(v);
            g[v].erase(i);
            auto it = g[u].find(v);
            if (it != g[u].end()) {
                g[u].erase(v);
                g[v].erase(u);
            } else {
                g[u].insert(v);
                g[v].insert(u);
            }
            ops.eb(i, u, v);
        }
    }
    int r = -1, s = -1;
    forn (i, n) {
        if (len(g[i])) {
            r = i;
            s = *g[i].begin();
            break;
        }
    }
    if (r == -1) {
        assert(len(ops) <= 2 * max(n, m));
        print(len(ops));
        for (auto [a, b, c] : ops) {
            print(a + 1, b + 1, c + 1);
        }
        return;
    }
    vb b(n, false);
    b[r] = true;
    b[s] = true;
    forn (i, n) if (!b[i]) {
        ops.eb(i, r, s);
        b[i] = true;
        if (!g[i].empty()) {
            b[*g[i].begin()] = true;
        }
        s = i;
    }
    assert(len(ops) <= 2 * max(n, m));
    print(len(ops));
    for (auto [a, b, c] : ops) {
        print(a + 1, b + 1, c + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
