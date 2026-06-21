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

typedef pair<ll, int> T;

void solve() {
    int n, m, y; cin >> n >> m >> y;
    vector<vpii> g(n);
    forn(_, m) {
        int u, v, w; cin >> u >> v >> w; --u; --v;
        g[u].eb(v, w);
        g[v].eb(u, w);
    }
    vi xs(n);
    forn(i, n) cin >> xs[i];
    vi I(n);
    iota(all(I), 0);
    sort(all(I), [&](int i1, int i2) {return xs[i1] < xs[i2]; });
    const ll INF = 4e9;
    vll ds(n, INF);
    ds[0] = 0;
    priority_queue<T, vector<T>, greater<>> pq;
    pq.emplace(0, 0);
    ll z = xs[0] + y;
    int i = 0;
    int left = n;
    while (left) {
        int u;
        ll d;
        while (i < n && ds[I[i]] <= (d = z + xs[I[i]])) ++i;
        if (i < n && (pq.empty() || d < pq.top().fi)) {
            u = I[i];
            ds[I[i]] = d;
            ++i;
        } else {
            auto [a, b] = pq.top();
            pq.pop();
            d = a; u = b;
        }
        if (d != ds[u]) continue;
        --left;
        for (auto [v, w] : g[u]) {
            ll d2 = d + w;
            if (d2 < ds[v]) {
                ds[v] = d2;
                pq.emplace(d2, v);
            }
        }
        cmin(z, ds[u] + xs[u] + y);
    }
    print(ds.begin() + 1, ds.end());
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
