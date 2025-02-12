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

struct T {
    int mn1 = -1;
    int mn2 = -1;
    int mx1 = -1;
    int mx2 = -1;
};

struct ST {
    int n;
    vector<int> A;
    vector<T> tree;

    inline int l(int p) { return p * 2; }
    inline int r(int p) { return p * 2 + 1; }

    // Initialise lazy with flag to indicate no updates necessary
    ST(int n, int v = 0) : n(n), A(n, v), tree(4*n) {}

    ST(const vector<int>& _A) : ST(len(_A)) {
        A = _A;
        build();
    }

    void build() { build(1, 0, n-1); }
    void build(int p, int tl, int tr) {
        if (tl == tr) {
            tree[p].mn1 = tl;
            tree[p].mx1 = tl;
            return;
        }
        int m = (tl + tr) / 2;
        build(l(p), tl, m);
        build(r(p), m+1, tr);
        tree[p] = comb(tree[l(p)], tree[r(p)]);
    }

    T comb(T& x, T& y) {
        if (y.mn1 == -1) return x;
        if (x.mn1 == -1) return y;
        T t;
        if (A[x.mn1] <= A[y.mn1]) {
            t.mn1 = x.mn1;
            t.mn2 = x.mn2 == -1 ? y.mn1 : A[x.mn2] <= A[y.mn1] ? x.mn2 : y.mn1;
        } else {
            t.mn1 = y.mn1;
            t.mn2 = y.mn2 == -1 ? x.mn1 : A[x.mn1] <= A[y.mn2] ? x.mn1 : y.mn2;
        }
        if (A[x.mx1] >= A[y.mx1]) {
            t.mx1 = x.mx1;
            t.mx2 = x.mx2 == -1 ? y.mx1 : A[x.mx2] >= A[y.mx1] ? x.mx2 : y.mx1;
        } else {
            t.mx1 = y.mx1;
            t.mx2 = y.mx2 == -1 ? x.mx1 : A[x.mx1] >= A[y.mx2] ? x.mx1 : y.mx2;
        }
        return t;
    }

    T query(int ql, int qr) { return query(1, 0, n-1, ql, qr); }
    T query(int p, int tl, int tr, int ql, int qr) {
        if (ql > qr) return {-1, -1, -1, -1};  // Identity value
        if (ql <= tl && qr >= tr) return tree[p];
        int m = (tl + tr) / 2;
        T t1 = query(l(p), tl, m, ql, min(m, qr));
        T t2 = query(r(p), m+1, tr, max(ql, m+1), qr);
        return comb(t1, t2);
    }
};

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vi a;
    a.resize(n);
    forn(i, n) {
        cin >> a[i];
    }
    ST st(a);
    forn(i, q) {
        int l, r; cin >> l >> r; --l; --r;
        T t = st.query(l+1, r-1);
        uset<int> s({t.mn1, t.mn2, t.mx1, t.mx2});
        s.erase(-1);
        vi v(all(s));
        ll mx = LONG_LONG_MIN;
        forn(x, len(v)) for(int y = x+1; y < len(v); ++y) {
            mx = max(mx, (ll)a[l]*a[r]*a[v[x]]*a[v[y]]);
        }
        print(mx);
    }
}
