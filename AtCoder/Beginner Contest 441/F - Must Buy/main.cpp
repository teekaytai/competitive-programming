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
    int n, m; cin >> n >> m;
    vpii a;
    forn(i, n) {
        int p, v; cin >> p >> v;
        a.eb(p, v);
    }
    vector<vector<pair<ll, int>>> dp(n + 1, vector<pair<ll, int>>(m + 1, {0, 1}));
    forn1(i, n) {
        auto [p, v] = a[i - 1];
        forn1(j, m) {
            dp[i][j] = {dp[i - 1][j].fi, 1};
            if (j >= p) {
                ll v2 = dp[i - 1][j - p].fi + v;
                if (v2 > dp[i][j].fi) {
                    dp[i][j] = {v2, 2};
                } else if (v2 == dp[i][j].fi) {
                    dp[i][j].se = 3;
                }
            }
        }
    }
    ll mx = 0;
    for (auto [v, _] : dp[n]) {
        cmax(mx, v);
    }
    vvb bs(n + 1, vb(m + 1, false));
    forn (j, m + 1) {
        bs[n][j] = dp[n][j].fi == mx;
    }
    vi ans(n, 0);
    rforn1(i, n) {
        forn(j, m + 1) if (bs[i][j]) {
            int d = dp[i][j].se;
            ans[i - 1] |= d;
            if (d & 1) bs[i - 1][j] = true;
            if (d & 2) bs[i - 1][j - a[i - 1].fi] = true;
        }
    }
    for (int x : ans) {
        cout << "CCAB"[x];
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();
}
