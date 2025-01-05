#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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
    cerr << "\u001B[31m";
    for (auto x : v) cerr << x << " ";
    cerr << "\u001B[0m" << endl;
}

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;

struct ST {
    struct T {
        int ans;
        int mx1;
        int mn1;
        int mx2;
        int mn2;
    };

    static constexpr T ID = {-INF, -INF, INF, -INF, INF}; // Identity value

    int n;
    vector<int> A;
    vector<T> tree;

    inline int l(int p) { return p * 2; }
    inline int r(int p) { return p * 2 + 1; }

    // Initialise lazy with flag to indicate no updates necessary
    ST(const vector<int>&& _A) : n(len(_A)), A(_A), tree(4*n) {
        build();
    }

    void build() { build(1, 0, n-1); }
    void build(int p, int tl, int tr) {
        if (tl == tr) {
            tree[p] = {0, A[tl] - tl, A[tl] - tl, A[tl] + tl, A[tl] + tl};
            return;
        }
        int m = (tl + tr) / 2;
        build(l(p), tl, m);
        build(r(p), m+1, tr);
        tree[p] = comb(tree[l(p)], tree[r(p)]);
    }

    inline T comb(T x, T y) {
        return {
            max({x.ans, y.ans, y.mx1 - x.mn1, x.mx2 - y.mn2}),
            max(x.mx1, y.mx1),
            min(x.mn1, y.mn1),
            max(x.mx2, y.mx2),
            min(x.mn2, y.mn2)
        };
    }

    // Both ql and qr inclusive, zero-indexed
    T query(int ql, int qr) { return query(1, 0, n-1, ql, qr); }
    T query(int p, int tl, int tr, int ql, int qr) {
        if (ql > qr) return ID;
        if (ql <= tl && qr >= tr) return tree[p];
        int m = (tl + tr) / 2;
        return comb(
            query(l(p), tl, m, ql, min(m, qr)),
            query(r(p), m+1, tr, max(ql, m+1), qr)
        );
    }

    void update(int ql, int qr, int d) { update(1, 0, n-1, ql, qr, d); }
    void update(int p, int tl, int tr, int ql, int qr, int d) {
        if (ql > qr) return;
        if (ql == tl && qr == tr) {
            tree[p] = {0, d - tl, d - tl, d + tl, d + tl};
            return;
        }
        int m = (tl + tr) / 2;
        update(l(p), tl, m, ql, min(m, qr), d);
        update(r(p), m+1, tr, max(ql, m+1), qr, d);
        tree[p] = comb(tree[l(p)], tree[r(p)]);
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vi a(n);
    forn(i, n) {
        cin >> a[i];
    }
    ST st(move(a));
    print(st.query(0, n-1).ans);
    forn (_, q) {
        int p, x; cin >> p >> x;
        --p;
        st.update(p, p, x);
        print(st.query(0, n-1).ans);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
