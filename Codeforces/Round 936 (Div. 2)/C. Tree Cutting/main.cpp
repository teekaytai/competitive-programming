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
#define x first
#define y second

template <typename... Ts>
inline void print(const Ts&... args) {
    const char* sep = "";
    (((cout << sep << args), sep = " "), ...);
    cout << "\n";
}
template <typename... Ts>
inline void printerr(const Ts&... args) {
    const char* sep = "";
    cerr << "\u001B[31m";
    (((cerr << sep << args), sep = " "), ...);
    cerr << "\u001B[0m" << endl;
}

const double EPS = 1e-8;
const int INF = 1e9;
const int MAXN = 3e5;

vvi g;
int t;
int dfs(int u, int p, int x) {
    int s = 1;
    for (int v : g[u]) if (v != p) {
        s += dfs(v, u, x);
    }
    if (s >= x) {
        ++t;
        return 0;
    }
    return s;
}

void solve() {
    int n, k; cin >> n >> k;
    g.assign(n, vi());
    forn(i, n - 1) {
        int u, v; cin >> u >> v;
        --u; --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int lo = 1;
    int hi = n/k;
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        t = 0;
        dfs(0, -1, mid);
        if (t >= k+1) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    print(lo);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
