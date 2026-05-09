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

const int POW_3_10 = 59049;

ll dp[POW_3_10] = {0};
int ms[POW_3_10];
int ms2[POW_3_10];

int cs[10];

void solve() {
    int n; cin >> n;
    vi a(n);
    forn(i, n) {
        int x; cin >> x;
        if (x == 0) continue;
        int y = x;
        memset(cs, 0, sizeof(cs));
        bool can = true;
        while (y) {
            int d = y % 10;
            if (++cs[d] == 3) {
                can = false;
                break;
            };
            y /= 10;
        }
        if (!can) continue;
        int m = 0;
        for (int c : cs) {
            m = 3 * m + c;
        }
        // printerr(m);
        rforn(j, POW_3_10) if ((ms2[m] & ms[j]) == 0) {
            cmax(dp[m + j], dp[j] + x);
        }
    }
    print(*max_element(all(dp)));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    forn(i, POW_3_10) {
        int m = i;
        int c = 0;
        int c2 = 0;
        forn(j, 10) {
            int d = m % 3;
            m /= 3;
            c = c * 4 + (d == 0 ? 0 : d == 1 ? 1 : 3);
            c2 = c2 * 4 + (d == 0 ? 0 : d == 1 ? 2 : 3);
        }
        ms[i] = c;
        ms2[i] = c2;
    }

    // int tc; cin >> tc;
    int tc = 1;
    while (tc--) {
        solve();
    }
}
