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

ll modinv(ll x, ll mod = MOD) {
    // Assumes x < mod and mod is prime
    return x <= 1 ? x : mod - mod / x * modinv(mod % x, mod) % mod;
}

ll moddiv(ll a, ll b, ll mod = MOD) {
    return a * modinv(b, mod) % mod;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<tuple<int, int, ll, ll>> g;
    g.reserve(n);
    forn(i, n) {
        int l, r; ll p, q; cin >> l >> r >> p >> q;
        g.eb(l - 1, r - 1, p, q);
    }
    sort(all(g));
    vll ps(n + 1, 1);
    forn(i, n) {
        auto [l, r, p, q] = g[i];
        ps[i + 1] = ps[i] * moddiv(q - p, q) % MOD;
    }
    vll dp(m + 1, 0);
    dp[0] = 1;
    int le = 0;
    forn(i, m) {
        ll t = 1;
        while (le < n && get<0>(g[le]) == i) {
            auto [l, r, p, q] = g[le];
            int lo = le + 1;
            int hi = n;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (get<0>(g[mid]) <= r) {
                    lo = mid + 1;
                } else {
                    hi = mid;
                }
            }
            dp[r + 1] = (dp[r + 1] + dp[l] * t % MOD * moddiv(p, q) % MOD * moddiv(ps[lo], ps[le + 1]) % MOD) % MOD;
            t = t * moddiv(q - p, q) % MOD;
            ++le;
        }
    }
    print(dp[m]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();
}
