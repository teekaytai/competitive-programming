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


const int INF = 1e9;
const int MAXN = 2e5;

int a[MAXN];
int cols[MAXN];
vvi g;
ll total = 0;

void dfs(int v, int p) {
    int c = cols[a[v]];
    total += c;
    for (int u : g[v]) if (u != p) {
        cols[a[v]] = 1;
        dfs(u, v);
    }
    cols[a[v]] = c+1;
}

void solve() {
    int n; cin >> n;
    total = 0;
    forn(i, n) cin >> a[i], --a[i];
    g.assign(n, vi());
    memset(cols, 0, sizeof(cols));
    forn(i, n-1) {
        int u, v; cin >> u >> v;
        --u;--v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0, 0);
    cout << total << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
