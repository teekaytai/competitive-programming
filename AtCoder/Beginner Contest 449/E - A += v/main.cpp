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

#include <bits/extc++.h>
using namespace __gnu_pbds;
template<class T>
using OST = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order, order_of_key

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;
const ll MOD = 998244353;

void solve() {
    int n, m; cin >> n >> m;
    vi cs(m + 11, 0);
    vi a(n);
    forn(i, n) {
        cin >> a[i];
        ++cs[a[i]];
    }
    int q; cin >> q;
    vll qs(q);
    vi ans(q, -1);
    forn(i, q) {
        cin >> qs[i]; --qs[i];
        if (qs[i] < n) ans[i] = a[qs[i]];
    }
    vi I(q);
    iota(all(I), 0);
    sort(all(I), [&](int i1, int i2) { return qs[i1] < qs[i2]; });
    vpii E;
    forn1(i, m) {
        E.eb(cs[i], i);
    }
    sort(all(E));
    OST<int> ost;
    ll oi = n;
    int qi = 0;
    while (qi < q && qs[I[qi]] < n) ++qi;
    forn(ei, len(E)) {
        auto [v, k] = E[ei];
        ost.insert(k);
        if (ei < len(E) - 1 && E[ei + 1].fi == v) continue;
        ll oi2 = ei < len(E) - 1 ? oi + (ll) (E[ei + 1].fi - v) * len(ost) : LLONG_MAX;
        while (qi < q && qs[I[qi]] < oi2) {
            int j = (qs[I[qi]] - oi) % len(ost);
            ans[I[qi]] = *ost.find_by_order(j);
            ++qi;
        }
        oi = oi2;
    }
    for (int x : ans) {
        assert(x != -1);
        print(x);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
