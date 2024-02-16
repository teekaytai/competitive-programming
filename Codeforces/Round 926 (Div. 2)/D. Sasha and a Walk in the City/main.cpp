#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
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

const int MOD = 998244353;

const int INF = 1e9;
const int MAXN = 3e5;
vvi g;

pair<ll, ll> dfs(int v, int p) {
    ll dd = 0; ll ss = 1;
    for (int u : g[v]) {
        if (u==p) continue;
        auto [d, s] = dfs(u, v);
        dd = (dd + d) % MOD;
        ss = ss * s % MOD;
    }
    return {(dd + ss) % MOD, (ss + 1) % MOD};
}

void solve() {
    int n; cin >> n;
    g.assign(n, vi());
    forn(i, n-1) {
        int u, v; cin >> u >> v;
        --u,--v;
        g[u].pb(v);
        g[v].pb(u);
    }
    cout << (1+dfs(0, 0).x)%MOD << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
