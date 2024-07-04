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
const int MAXN = 5001;

ll ans;
int n;
ll a[MAXN];
vvi g;

pair<int, map<int, ll>> dfs(int u, int p) {
    if (len(g[u]) == 1 && g[u][0] == p) return {1, map<int, ll>()};
    map<int, ll> ss;
    int H = INF;
    ll d = a[u];
    for (int v : g[u]) if (v != p) {
        d -= a[v];
        auto [h, s] = dfs(v, u);
        H = min(H, h);
        for (auto [p, q] : s) {
            if (p >= H) break;
            ss[p+1] += q;
        }
    }
    while (!ss.empty() && (--ss.end())->fi > H) {
        ss.erase(--ss.end());
    }
    if (d < 0) {
        ss[1] = -d;
    }
    while (d > 0) {
        if (ss.empty()) {
            ans += d * H;
            d = 0;
        } else {
            auto it = ss.begin();
            auto& [p, q] = *it;
            ll m = min(d, q);
            ans += m * (p-1);
            d -= m;
            q -= m;
            if (q == 0) ss.erase(it);
        }
    }
    return {H+1, ss};
}

void solve() {
    ans = 0;
    cin >> n;
    forn(i, n) cin >> a[i];
    g.assign(n, vi());
    forn1(i, n-1) {
        int v; cin >> v;
        --v;
        g[i].pb(v);
        g[v].pb(i);
    }
    dfs(0, -1);
    print(ans);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
