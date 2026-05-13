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
const ll INF = 1e18;
const int MAXN = 3e5;
const ll MOD = 998244353;

struct ST {
    struct T {
        ll s;
        ll l;
        ll m;
        ll r;
    };
    static constexpr T ID = {0, -INF, -INF, -INF};

    inline T comb(T a, T b) {
        return {
            a.s + b.s,
            max(a.l, a.s + b.l),
            max({a.m, b.m, a.r + b.l}),
            max(b.r, a.r + b.s),
        };
    }

    int n;
    vector<T> tree;

    ST(int n, T v = ID) : n(n), tree(2 * n, v) {
        for (int i = n - 1; i >= 0; --i) {
            tree[i] = comb(tree[i * 2], tree[i * 2 + 1]);
        }
    }

    ST(const vector<int>& A) : n(len(A)), tree(2 * len(A)) {
        forn(i, n) {
            int v = A[i] == 0 ? -1 : A[i];
            int x = max(v, 0);
            tree[n + i] = {v, x, x, x};
        }
        rforn (i, n) {
            tree[i] = comb(tree[i * 2], tree[i * 2 + 1]);
        }
    }

    // Half-open interval [L, R)
    T query(int L, int R) {
        T ra = ID, rb = ID;
        for (L += n, R += n; L < R; L /= 2, R /= 2) {
            if (L % 2) ra = comb(ra, tree[L++]);
            if (R % 2) rb = comb(tree[--R], rb);
        }
        return comb(ra, rb);
    }

    void update(int pos, int d) {
        pos += n;
        int x = max(d, 0);
        tree[pos] = {d, x, x, x};
        for (; pos /= 2;) {
            tree[pos] = comb(tree[pos * 2], tree[pos * 2 + 1]);
        }
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vi a(n);
    ll t = 0;
    forn(i, n) {
        cin >> a[i];
        t += a[i];
    }
    ST st(a);
    forn(_, q) {
        int i, v; cin >> i >> v; --i;
        t += v - a[i];
        a[i] = v;
        st.update(i, v == 0 ? -1 : v);
        print(t - st.query(0, n).m);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
