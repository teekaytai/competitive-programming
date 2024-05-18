#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
#define umap unordered_map
#define uset unordered_set
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forn1(i, n) for (int i = 1; i <= (n); ++i)
#define rforn(i, n) for (int i = (n) - 1; i >= 0; --i)
#define rforn1(i, n) for (int i = (n); i > 0; --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define len(x) (int) x.size()
#define LSB(x) ((x) & -(x))
inline int MSB(int x) { return x ? 1 << (31 - __builtin_clz(x)) : 0; }
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

struct ST {
    static constexpr int INF = 1e9;

    int n;
    vector<int> A;
    vector<int> tree;
    vector<int> lazy;

    inline int l(int p) { return p * 2; }
    inline int r(int p) { return p * 2 + 1; }

    // Initialise lazy with flag to indicate no updates necessary
    ST(int n, int v = 0) : n(n), A(n, v), tree(4*n, v), lazy(4*n, -1) {}

    ST(const vector<int>& _A) : ST(len(_A)) {
        A = _A;
        build();
    }

    void build() { build(1, 0, n-1); }
    void build(int p, int tl, int tr) {
        if (tl == tr) {
            tree[p] = A[tl];
            return;
        }
        int m = (tl + tr) / 2;
        build(l(p), tl, m);
        build(r(p), m+1, tr);
        tree[p] = comb(tree[l(p)], tree[r(p)]);
    }

    inline int comb(int x, int y) {
        return x|y;
    }

    void push(int p, int tl, int tr) {
        if (lazy[p] == -1) return;
        tree[p] = lazy[p];
        if (tl != tr) {
            lazy[l(p)] = lazy[p];
            lazy[r(p)] = lazy[p];
        } else {
            A[tl] = lazy[p];
        }
        lazy[p] = -1;
    }

    int query(int ql, int qr) { return query(1, 0, n-1, ql, qr); }
    int query(int p, int tl, int tr, int ql, int qr) {
        push(p, tl, tr);
        if (ql > qr) return 0;  // Identity value
        if (ql <= tl && qr >= tr) return tree[p];
        int m = (tl + tr) / 2;
        return comb(
            query(l(p), tl, m, ql, min(m, qr)),
            query(r(p), m+1, tr, max(ql, m+1), qr)
        );
    }

    void update(int ql, int qr, int d) { update(1, 0, n-1, ql, qr, d); }
    void update(int p, int tl, int tr, int ql, int qr, int d) {
        push(p, tl, tr);
        if (ql > qr) return;
        if (ql <= tl && qr >= tr) {
            lazy[p] = d;
            push(p, tl, tr);
            return;
        }
        int m = (tl + tr) / 2;
        update(l(p), tl, m, ql, min(m, qr), d);
        update(r(p), m+1, tr, max(ql, m+1), qr, d);
        tree[p] = comb(tree[l(p)], tree[r(p)]);
    }
};


const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;

void solve() {
    int n; cin >> n;
    vi a(n);
    forn(i, n) cin >> a[i];
    ST st(a);
    int lo = 1;
    int hi = n;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        int x = st.query(0, mid-1);
        bool can = true;
        forn(j, n-mid+1) {
            if (st.query(j, j+mid-1) != x) {
                can = false;
                break;
            }
        }
        if (can) hi = mid;
        else lo = mid + 1;
    }
    print(lo);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
