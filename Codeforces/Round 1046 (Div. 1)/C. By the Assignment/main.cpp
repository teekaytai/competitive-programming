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
const ll MOD = 998244353;

vi w;

struct UF {
    vector<int> pars;
    vector<int> sizes;
    int num_sets;

    UF(int n) {
        pars.assign(n, -1);
        sizes.assign(n, 1);
        num_sets = n;
    }

    int find(int i) {
        return pars[i] < 0 ? i : (pars[i] = find(pars[i]));
    }

    bool onion(int i, int j) {
        int r1 = find(i);
        int r2 = find(j);
        if (r1 == r2) return true;
        if (sizes[r2] > sizes[r1]) swap(r1, r2);
        pars[r2] = r1;
        sizes[r1] += sizes[r2];
        num_sets -= 1;
        if (w[r1] != -1 && w[r2] != -1 && w[r1] != w[r2]) {
            return false;
        }
        if (w[r1] == -1) w[r1] = w[r2];
        return true;
    }

    bool is_same_set(int i, int j) { return find(i) == find(j); }
    int set_size(int i) { return sizes[find(i)]; }
};

void solve() {
    int n, m, V; cin >> n >> m >> V;
    vvi g(n, vi());
    w.resize(n);
    forn(i, n) cin >> w[i];
    forn(i, m) {
        int u, v; cin >> u >> v;
        --u; --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    UF uf(n);
    stack<int> st;
    vi sti(n, -1);
    vpii s;
    bool can = true;
    vb seen(n, false);
    auto dfs = [&](auto& dfs, int u = 0, int p = -1) -> void {
        seen[u] = true;
        sti[u] = len(st);
        st.push(u);
        for (int v : g[u]) if (v != p) {
            if (sti[v] == -1) {
                if (!seen[v]) dfs(dfs, v, u);
            } else {
                pii x = {sti[v], sti[u]};
                while (!s.empty() && s.back().se >= x.fi) {
                    x.fi = min(x.fi, s.back().fi);
                    s.pop_back();
                }
                s.pb(x);
                if ((sti[u] - sti[v]) % 2 == 0) {
                    int r = uf.find(u);
                    can &= w[r] == 0 || w[r] == -1;
                    w[r] = 0;
                }
            }
        }
        if (!s.empty() && s.back().se == len(st) - 1) {
            can &= uf.onion(u, p);
            --s.back().se;
            if (s.back().se == s.back().fi) s.pop_back();
        }
        st.pop();
        sti[u] = -1;
    };
    dfs(dfs);
    if (!can) {
        print(0);
        return;
    }
    ll ans = 1;
    forn (v, n) if (uf.find(v) == v) {
        if (w[v] == -1) {
            ans = ans * V % MOD;
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
