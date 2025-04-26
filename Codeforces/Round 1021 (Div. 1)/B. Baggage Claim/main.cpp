#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> t3i;
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
    const char* sep = "";
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
    const char* sep = "";
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
const int MOD = 1e9+7;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vi ps;
    set<int> have;
    map<int, vi> g;
    forn (i, k + 1) {
        int x, y; cin >> x >> y;
        --x; --y;
        int p = x * 10000 + y;
        ps.pb(p);
    }
    forn (i, k) {
        int d = abs(ps[i] - ps[i + 1]);
        if (d != 2 && d != 20000 && d != 10001 && d != 9999) {
            print(0);
            return;
        }
        if (d == 2 || d == 20000) {
            int m = (ps[i] + ps[i + 1]) / 2;
            if (have.contains(m)) {
                print(0);
                return;
            }
            have.insert(m);
        } else {
            int x1, y1, x2, y2;
            x1 = ps[i] / 10000;
            y1 = ps[i] % 10000;
            x2 = ps[i + 1] / 10000;
            y2 = ps[i + 1] % 10000;
            int p1 = x1*10000+y2;
            int p2 = x2*10000+y1;
            g[p1].pb(p2);
            g[p2].pb(p1);
        }
    }
    auto dfs1 = [&](auto& dfs, int u, int p = -1) -> bool {
        if (!g.contains(u)) return true;
        for (int v : g[u]) if (v != p) {
            if (have.contains(v)) return false;
            have.insert(v);
            if (!dfs(dfs, v, u)) return false;
        }
        g.erase(u);
        return true;
    };
    for (int u : have) {
        if (!dfs1(dfs1, u)) {
            print(0);
            return;
        }
    }
    set<int> seen;
    long long t = 1;
    auto dfs = [&](auto& dfs, int u) -> pii {
        seen.insert(u);
        int t = 1;
        int e = len(g[u]);
        for (int v : g[u]) if (!seen.contains(v)) {
            auto [x, y] = dfs(dfs, v);
            t += x;
            e += y;
        }
        return {t, e};
    };
    for (auto& [s, _] : g) {
        if (seen.contains(s)) continue;
        auto [sz, es] = dfs(dfs, s);
        es /= 2;
        if (es > sz) {
            t = 0;
            break;
        }
        t = t * (es == sz ? 2 : sz) % MOD;
    }
    print(t);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
