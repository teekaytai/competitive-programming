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
const ll MOD = (ll) 1e9 + 7;

char g[5000 * 5000];

void solve() {
    int n, k; cin >> n >> k;
    memset(g, 0, n * n);
    forn (_, k) {
        int l, r, c; cin >> l >> r >> c;
        --r; --c;
        g[r*n+c] = 'H';
        if (l > 1) {
            string s; cin >> s;
            for (char d : s) {
                if (d == 'R') ++c;
                else ++r;
                g[r*n+c] = d;
            }
        }
    }
    queue<pii> q;
    q.emplace(0, 1);
    ll ans = 1;
    forn (i, n) {
        int L = len(q);
        forn (_, L) {
            auto [lo, hi] = q.front();
            q.pop();
            int r = i - lo;
            int c = lo;
            int j = lo;
            int x = -1;
            forn (_, hi - lo) {
                if (g[r*n+c]) {
                    x = j;
                    break;
                }
                --r; ++c; ++j;
            }
            if (x == -1) {
                ans = ans * (hi - lo) % MOD;
                q.emplace(lo, hi + 1);
            } else if (g[r*n+c] == 'H') {
                q.emplace(lo, x + 1);
                q.emplace(x + 1, hi + 1);
            } else if (g[r*n+c] == 'R') {
                q.emplace(x + 1, hi + 1);
            } else  {
                q.emplace(lo, x + 1);
            }
        }
    }
    print(ans);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
