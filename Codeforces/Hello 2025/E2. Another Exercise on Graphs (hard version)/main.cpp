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

void solve() {
    int n, m, q; cin >> n >> m >> q;
    vvi ds(n, vi(n, INF));
    forn(i, n) ds[i][i] = 0;
    vector<tuple<int, int, int>> edges;
    forn(_, m) {
        int u, v, w; cin >> u >> v >> w;
        --u; --v;
        ds[u][v] = 1;
        ds[v][u] = 1;
        edges.emplace_back(w, u, v);
    }
    sort(all(edges));
    forn(k, n) forn(i, n) forn(j, n) cmin(ds[i][j], ds[i][k] + ds[k][j]);
    vector<vector<vpii>> qs(n, vector<vpii>(n, vpii()));
    forn(i, q) {
        int a, b, k; cin >> a >> b >> k;
        --a; --b;
        qs[a][b].emplace_back(k, i);
    }
    forn(i, n) forn(j, n) sort(all(qs[i][j]));
    vi ans(q);
    for (auto [w, u, v] : edges) if (ds[u][v]) {
        ds[u][v] = 0;
        ds[v][u] = 0;
        forn(i, n) forn(j, n) {
            cmin(ds[i][j], min(ds[i][u] + ds[v][j], ds[i][v] + ds[u][j]));
            while (!qs[i][j].empty() && qs[i][j].back().fi > ds[i][j]) {
                ans[qs[i][j].back().se] = w;
                qs[i][j].pop_back();
            }
        }
    }
    print(ans);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
