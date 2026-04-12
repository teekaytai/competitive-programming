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
const int MAXN = 2e5 + 10;
const ll MOD = 998244353;

const int B = 450;

struct Page {
    ll t = 0;
    array<int, B> a = {0};

    void set(int i, int v) {
        t += v - a[i];
        a[i] = v;
    }
};

vector<Page> pages;

void solve() {
    int n, m, q; cin >> n >> m >> q;
    pages.reserve(q);
    pages.eb();
    int K = (m + B - 1) / B;
    int pi = 1;
    vvi tab(n, vi(K, 0));
    forn(_, q) {
        int t; cin >> t;
        if (t == 1) {
            int x, y; cin >> x >> y; --x; --y;
            forn(i, K) {
                tab[x][i] = tab[y][i];
            }
        } else if (t == 2) {
            int x, y, z; cin >> x >> y >> z; --x; --y;
            int q = y / B;
            int r = y % B;
            pages.eb(pages[tab[x][q]]);
            tab[x][q] = pi++;
            pages.back().set(r, z);
        } else {
            int x, l, r; cin >> x >> l >> r; --x; --l; --r;
            ll ans = 0;
            int lo = l / B;
            int hi = r / B;
            if (lo == hi) for (int i = l % B; i <= r % B; ++i) {
                ans += pages[tab[x][lo]].a[i];
            } else {
                for(int i = l % B; i < B; ++i) {
                    ans += pages[tab[x][lo]].a[i];
                }
                for (int i = lo + 1; i < hi; ++i) {
                    ans += pages[tab[x][i]].t;
                }
                for(int i = 0; i <= r % B; ++i) {
                    ans += pages[tab[x][hi]].a[i];
                }
            }
            print(ans);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
