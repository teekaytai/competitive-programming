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

const ll MOD = 1e9 + 7;

ll modinv(ll x, ll mod = MOD) {
    // Assumes 0 < x < mod and mod is prime
    return x <= 1 ? x : mod - mod / x * modinv(mod % x, mod) % mod;
}

ll moddiv(ll a, ll b, ll mod = MOD) {
    assert(b != 0);
    return a * modinv(b % mod, mod) % mod;
}

const int N = 500010;
ll fac[N + 1], invfac[N + 1];
void init() {
    fac[0] = 1;
    forn1 (i, N) fac[i] = fac[i - 1] * i % MOD;
    invfac[N] = modinv(fac[N], MOD);
    rforn1 (i, N) invfac[i - 1] = invfac[i] * i % MOD;
}

ll comb(int n, int k) {
    if (k > n || k < 0) return 0;
    return fac[n] * invfac[k] % MOD * invfac[n - k] % MOD;
}

ll ans;
vll a;

void f(int l, int r, int p = 0) {
    if (l == r) return;
    int x = l - p + 1;
    if (a[l] % x != 0) {
        ans = 0;
        return;
    }
    ll v = a[l] / x;
    ll i = l + v;
    if (i > r) {
        ans = 0;
        return;
    }
    ans = ans * comb((int) i - p - 1, l - p) % MOD;
    f(l + 1, (int) i, l + 1);
    f((int) i, r, p);
}

void solve() {
    int n; cin >> n;
    ans = 1;
    a.resize(n);
    forn(i, n) cin >> a[i];
    f(0, n);
    print(ans);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    init();

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
