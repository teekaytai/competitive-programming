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

const ll MOD = 998244353;

int mat[2500][2500] = {{1, 0, 0, 1}, {0, 0, 1, 1}, {0, 1, 1, 0}, {1, 1, 0, 0}};;

int a0[4][4] = {{0, 1, 2, 3}, {1, 0, 3, 2}, {2, 3, 0, 1}, {3, 2, 1, 0}};
int a1[4][4] = {{0, 2, 1, 3}, {2, 1, 3, 0}, {1, 3, 0, 2}, {3, 0, 2, 1}};
int a2[4][4] = {{0, 1, 2, 3}, {1, 2, 3, 0}, {2, 3, 0, 1}, {3, 0, 1, 2}};
int a3[4][4] = {{0, 1, 3, 2}, {1, 3, 2, 0}, {3, 2, 0, 1}, {2, 0, 1, 3}};

void init() {
    int c = 4;
    while (c * 2 < 2500) {
        forn (i, c) forn(j, c) {
            mat[i][c + j] = 1 - mat[i][j];
            mat[c + i][j] = 1 - mat[i][j];
            mat[c + i][c + j] = mat[i][j];
        }
        c *= 2;
    }
}

void solve() {
    int n, x; cin >> n >> x;
    if (__builtin_popcount(n) != 1) {
        print(-1);
        return;
    }
    if (n == 2) {
        if (x == 1) {
            print(-1);
            return;
        }
        print("0 1\n1 0");
        return;
    }
    vvi ans(n, vi(n));
    int m = x & 3;
    auto& a = m == 0 ? a0 : m == 1 ? a1 : m == 2 ? a2 : a3;
    forn(i, 4) forn(j, 4) {
        ans[i][j] = a[i][j];
    }
    int msb = MSB(n - 1);
    int b = 4;
    while (b <= msb) {
        forn(i, b) forn(j, b) {
            ans[i][b + j] = ans[i][j];
            ans[b + i][j] = ans[i][j];
            ans[b + i][b + j] = ans[i][j];
        }
        if ((x & b) == 0) {
            forn(i, b) forn(j, b) {
                ans[i][j] |= b;
                ans[b + i][b + j] |= b;
            }
        } else {
            forn(i, 2 * b) forn(j, 2 * b) if (mat[i][j]) {
                ans[i][j] |= b;
            }
        }
        b *= 2;
    }
    forn(i, n - 1) forn(j, n - 1) {
        assert(ans[i][j] ^ ans[i][j+1] ^ ans[i+1][j] ^ ans[i+1][j+1] == x);
    }
    for (auto& row : ans) print(all(row));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    init();

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
