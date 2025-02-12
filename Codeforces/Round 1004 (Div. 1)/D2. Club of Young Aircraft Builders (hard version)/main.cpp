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
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define len(x) (int) (x).size()
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
const int MOD = 1000000007;

ll modinv(ll x, ll mod = MOD) {
    return x <= 1 ? x : mod - mod / x * modinv(mod % x, mod) % mod;
}

constexpr int N = 102;
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

void solve() {
    int n, c, m; cin >> n >> c >> m;
    vi cs(n + 1, 0);
    vi last(n + 1, -1);
    vvi pp(n + 1, vi(m, 0));
    forn(i, m) {
        int x; cin >> x;
        ++cs[x];
        last[x] = i;
        pp[x][i] = 1;
    }
    rforn1(i, n) {
        if (i < n) pp[i][0] += pp[i + 1][0];
        forn1(j, m - 1) {
            pp[i][j] += pp[i][j - 1] + (i < n ? pp[i + 1][j] - pp[i + 1][j - 1] : 0);
        }
    }
    vll dp1(m + 1, 0);
    vll dp2(m + 1, 0);
    dp1[0] = 1;
    forn1 (h, n) {
        for (int i = 0; i <= min(m, h * c); ++i) {
            ll t = 0;
            for (int j = max(cs[h], c + i - m); j <= min({c, i, c + i - last[h] - 1}); ++j) {
                t = (t + comb(c - pp[h][c + i - j - 1], j - cs[h]) * dp1[i - j]) % MOD;
            }
            dp2[i] = t;
        }
        swap(dp1, dp2);
    }
    print(dp1[m]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    init();
    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
