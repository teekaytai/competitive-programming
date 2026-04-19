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

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;
const ll MOD = 998244353;

vvi g;
vi cs;

vector<umap<int, int>> ks(1);
vector<map<int, int>> vs(1);

ll ans = 0;

void dfs(int u = 0, int i = 0) {
    pii mx = {-INF, i};
    int l = len(g[u]);
    int L = len(ks);
    int j = L;
    forn(_, l) ks.eb(), vs.eb();
    for (int v : g[u]) {
        dfs(v, j);
        cmax(mx, {len(ks[j]), j});
        ++j;
    }
    int w = mx.se;
    ks[i] = std::move(ks[w]);
    vs[i] = std::move(vs[w]);
    int t = ks[i][cs[u]]++;
    if (t && --vs[i][t] == 0) vs[i].erase(t);
    ++vs[i][t + 1];
    for(int j = L; j < L + l; ++j) if (j != w) {
        for (auto [x, y] : ks[j]) {
            int t = ks[i][x];
            ks[i][x] += y;
            if (t && --vs[i][t] == 0) vs[i].erase(t);
            ++vs[i][t + y];
        }
    }
    auto it = vs[i].rbegin();
    ans = (ans + ((ll) (it->fi ^ (u + 1)) * (it->se ^ (u + 1)))) % MOD;
    forn(_, l) ks.pop_back(), vs.pop_back();
}

void solve() {
    ll seed, F;
    int n, M; cin >> n >> seed >> M >> F;
    vi qs(M);
    vi ds(M);
    forn(i, M - 1) cin >> qs[i];
    forn(i, M) cin >> ds[i];
    g.assign(n, vi());
    cs.resize(n);
    ks.reserve(n);
    vs.reserve(n);

    ll state = seed;
    for (int i = 2; i <= n; ++i) {
        int p;
        if (i <= M) p = qs[i - 2];
        else {
            p = state % (i - 1) + 1;
            state = (state * 1103515245 + 12345) % (1ll << 31);
        }
        g[p - 1].pb(i - 1);
    }
    for (int i = 1; i <= n; ++i) {
        int c;
        if (i <= M) c = ds[i - 1];
        else {
            c = (int) (state % F) + 1;
            state = (state * 1103515245 + 12345) % (1ll << 31);
        }
        cs[i - 1] = c - 1;
    }
    dfs();
    print(ans);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
