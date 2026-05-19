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

void solve() {
    int n; cin >> n;
    vi ps(n), cs(n);
    forn(i, n) cin >> ps[i];
    forn(i, n) cin >> cs[i];
    int m; cin >> m;
    vi tps(m), tcs(m), ds(m);
    forn(i, m) cin >> tps[i];
    forn(i, m) cin >> tcs[i];
    forn(i, m) cin >> ds[i];
    int mn = INF;
    forn(i, n) cmin(mn, ps[i] + cs[i]);
    vi ans(m, mn);
    auto f = [&] () {
        vi I(m); iota(all(I), 0);
        sort(all(I), [&](int i1, int i2){return tps[i1] < tps[i2];});
        vi J(n); iota(all(J), 0);
        sort(all(J), [&](int i1, int i2){return ps[i1] < ps[i2];});
        int mn = INF;
        int j = 0;
        for (int i : I) {
            int tp = tps[i];
            int tc = tcs[i];
            int d = ds[i];
            while (j < n && ps[J[j]] < tp) {
                cmin(mn, cs[J[j]]);
                j += 1;
            }
            if (mn < INF) cmin(ans[i], mn < tc ? 0 : min(mn, tc + d));
        }
        sort(all(I), [&](int i1, int i2){return tps[i1] + ds[i1] > tps[i2] + ds[i2];});
        mn = INF;
        j = n - 1;
        for (int i : I) {
            int tp = tps[i];
            int tc = tcs[i];
            int d = ds[i];
            int pd = tp + d;
            while (j >= 0 && ps[J[j]] >= pd) {
                cmin(mn, cs[J[j]]);
                j -= 1;
            }
            if (mn < INF) cmin(ans[i], pd + (mn < tc ? 0 : min(mn, tc + d)));
        }
    };
    f();
    swap(ps, cs);
    swap(tps, tcs);
    f();
    for (int v : ans) print(v);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
