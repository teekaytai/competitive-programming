#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef array<int, 3> a3i;
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
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define len(x) int(size(x))
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
    [[maybe_unused]] const char* sep = "";
    (((cout << sep << args), sep = " "), ...);
    cout << "\n";
}
template <typename It, typename = enable_if_t<is_base_of_v<input_iterator_tag, typename iterator_traits<It>::iterator_category>>>
inline void print(It b, It e) {
    for (auto it = b; it != e; ++it) cout << *it << " ";
    cout << "\n";
}
template <typename... Ts>
inline void printerr(const Ts&... args) {
    [[maybe_unused]] const char* sep = "";
    cerr << "\u001B[31m";
    (((cerr << sep << args), sep = " "), ...);
    cerr << "\u001B[0m" << endl;
}
template <typename It, typename = enable_if_t<is_base_of_v<input_iterator_tag, typename iterator_traits<It>::iterator_category>>>
inline void printerr(It b, It e) {
    cerr << "\u001B[31m{";
    if (b != e) {
        cerr << *b;
        for (auto it = next(b); it != e; ++it) cerr << ", " << *it;
    }
    cerr << "}\u001B[0m" << endl;
}

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;
const ll MOD = 998244353;

ll ans = 0;
vvi g;
vi ts;
vi szs;
vvi mas;

void dfs(int u) {
    if (g[u].empty()) {
        szs[u] = 1;
        mas[u] = {1};
        return;
    }
    pii mx = {-1, -1};
    int t = 0;
    for (int v : g[u]) {
        dfs(v);
        cmax(mx, {len(mas[v]), v});
        t += szs[v];
    }
    int vn = len(g[u]);
    int k = mx.se;
    if (vn > 1) {
        int l = -1;
        for(int i : g[u]) if (i != k) cmax(l, len(mas[i]));
        ts.assign(l, 0);
        for(int i : g[u]) {
            forn(j, min(len(mas[i]), l)) {
                ts[j] += mas[i][len(mas[i]) - j - 1];
            }
        }
        for(int i : g[u]) {
            int s = t;
            int sz = szs[i];
            forn(j, min(len(mas[i]), l)) {
                ans += (ll) mas[i][len(mas[i]) - j - 1] * (s - sz) * (j + 1);
                s -= ts[j];
                sz -= mas[i][len(mas[i]) - j - 1];
            }
        }
        forn(j, l) {
            mas[k][len(mas[k]) - j - 1] = ts[j];
        }
    }
    mas[k].pb(1);
    ++t;
    szs[u] = t;
    mas[u] = move(mas[k]);
}

void solve() {
    int n, m; cin >> n >> m;
    vi a(n - 1);
    forn(i, n - 1) a[i] = i + 1;
    forn(i, m) {
        int u, v; cin >> u >> v;
        --u; --v;
        cmax(a[u], v);
    }
    g.assign(n, vi());
    forn(v, n - 1) {
        g[a[v]].pb(v);
    }
    szs.resize(n);
    mas.resize(n);
    ans = 0;
    dfs(n - 1);
    print(ans);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
