#pragma GCC optimize("O3,unroll-loops")
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

const ll MOD = 998244353;

void solve() {
    int n, m; cin >> n >> m;
    int zero = 2 * n;
    vvi g(2 * n + 1);
    vi indegs(2 * n + 1, 0);
    forn(i, m) {
        int o, u, v; cin >> o >> u >> v;
        --u; --v;
        if (u == v) {
            if (o == 1) {
                g[zero].pb(u);
                ++indegs[u];
                g[u + n].pb(zero);
                ++indegs[zero];
            } else {
                g[u].pb(zero);
                ++indegs[zero];
                g[zero].pb(u + n);
                ++indegs[u + n];
            }
        } else {
            if (o == 1) {
                g[v + n].pb(u);
                ++indegs[u];
                g[u + n].pb(v);
                ++indegs[v];
            } else {
                g[u].pb(v + n);
                ++indegs[v + n];
                g[v].pb(u + n);
                ++indegs[u + n];
            }
        }
    }
    vi st;
    forn (i, 2 * n + 1) if (indegs[i] == 0) {
        st.pb(i);
    }
    int INF = -10000000;
    vi ans(2 * n + 1, INF + 1);
    ans[zero] = 0;
    vb locked(2 * n + 1, false);
    locked[zero] = true;
    forn(i, 2 * n + 1) {
        if (st.empty()) {
            print("NO");
            return;
        }
        int u = st.back();
        st.pop_back();
        if (u != zero) {
            locked[u] = true;
            locked[u < n ? u + n : u - n] = true;
            if (u >= n) ans[u - n] = -ans[u];
            else ans[u + n] = -ans[u];
        }
        for (int v : g[u]) {
            if (!locked[v]) cmax(ans[v], ans[u] + 1);
            else {
                assert(ans[v] > ans[u]);
            }
            if (--indegs[v] == 0) st.pb(v);
        }
    }
    print("YES");
    print(ans.begin(), ans.begin() + n);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
