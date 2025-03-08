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
    cerr << "\u001B[31m{";
    if (!v.empty()) cerr << v[0];
    forn1 (i, len(v) - 1) cerr << ", " << v[i];
    cerr << "}\u001B[0m" << endl;
}

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;
const int MOD = 998244353;

vi xs;
vb seen;
vector<vpii> g;
vi cs(31, 0);
vi st;

int dfs(int u, int p = -1) {
    st.pb(u);
    int t = 1;
    for (auto [v, w] : g[u]) if (v != p) {
        if (seen[v]) {
            if ((xs[u] ^ xs[v]) != w) return 0;
            continue;
        }
        seen[v] = true;
        int x = xs[u] ^ w;
        xs[v] = x;
        int i = 0;
        while (x) {
            cs[i] += x & 1;
            x >>= 1;
            ++i;
        }
        int c = dfs(v, u);
        if (!c) return 0;
        t += c;
    }
    return t;
}

void solve() {
    int n, m; cin >> n >> m;
    xs.assign(n, 0);
    seen.assign(n, false);
    g.assign(n, vpii());
    forn(i, m) {
        int u, v, w; cin >> u >> v >> w;
        --u; --v;
        g[u].eb(v, w);
        g[v].eb(u, w);
    }
    forn(i, n) if (!seen[i]) {
        seen[i] = true;
        st.clear();
        int c = dfs(i);
        if (!c) {
            print(-1);
            return;
        }
        int x = 0;
        for (int i = 0, b = 1; i < len(cs); ++i, b<<=1) {
            if (cs[i] > c - cs[i]) x |= b;
            cs[i] = 0;
        }
        for (int u : st) xs[u] ^= x;
    }
    print(xs);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    // int tc; cin >> tc;
    // while (tc--) {
    solve();
    // }
}
