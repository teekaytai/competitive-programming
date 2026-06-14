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

const ll INF = 1e16;

void solve() {
    int n; cin >> n;
    vvi g(n, vi(n));
    forn(i, n) forn(j, n) {
        cin >> g[i][j];
    }
    vvi g2(n, vi(n));
    forn(i, n) forn(j, n) {
        g2[i][j] = (j > 0 ? g[i][j - 1] : 0) + (j < n - 1 ? g[i][j + 1] : 0);
    }
    vector<vll> dp1(n, vll(n));
    forn(i, n) forn(j, n) {
        dp1[i][j] = g2[i][j] + (i == 0 ? 0 : min(j > 0 ? dp1[i - 1][j - 1] : INF, j < n - 1 ? dp1[i - 1][j + 1] : INF));
    }
    vector<vll> dp2(n, vll(n));
    rforn(i, n) forn(j, n) {
        dp2[i][j] = g2[i][j] + (i == n - 1 ? 0 : min(j > 0 ? dp2[i + 1][j - 1] : INF, j < n - 1 ? dp2[i + 1][j + 1] : INF));
    }
    vll ans(n);
    forn(i, n) {
        forn(j, n) {
            ans[j] = min(
                j > 0 ? dp1[i][j - 1] + dp2[i][j - 1] - g2[i][j - 1] : INF,
                j < n - 1 ? dp1[i][j + 1] + dp2[i][j + 1] - g2[i][j + 1] : INF
            );
        }
        print(all(ans));
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
