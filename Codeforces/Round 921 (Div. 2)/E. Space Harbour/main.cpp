#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
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
#define x first
#define y second

const int INF = 1e9;

struct ST {
    int n;
    vector<ll> A;
    vector<ll> tree;
    vector<ll> lazy_a;
    vector<ll> lazy_d;

    inline int l(int p) { return p * 2; }
    inline int r(int p) { return p * 2 + 1; }

    ST(int n, ll v = 0ll) : n(n), A(n, v), tree(4*n, v), lazy_a(4*n, 0), lazy_d(4*n, 0) {}

    ST(const vector<ll>& initial_A) : ST(len(initial_A)) {
        A = initial_A;
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

    inline ll comb(ll x, ll y) {
        return x + y;
    }

    void push(int p, int tl, int tr) {
        int x = tr - tl + 1;
        tree[p] += (lazy_a[p] + lazy_a[p] + (x - 1) * lazy_d[p]) * x / 2;
        if (tl != tr) {
            lazy_a[l(p)] += lazy_a[p] + lazy_d[p] * ((tr - tl + 1) / 2);
            lazy_d[l(p)] += lazy_d[p];
            lazy_a[r(p)] += lazy_a[p];
            lazy_d[r(p)] += lazy_d[p];
        } else {
            A[tl] += lazy_a[p];
        }
        lazy_a[p] = 0;
        lazy_d[p] = 0;
    }

    ll query(int ql, int qr) { return query(1, 0, n-1, ql, qr); }
    ll query(int p, int tl, int tr, int ql, int qr) {
        push(p, tl, tr);
        if (ql > qr) return 0;  // Identity value
        if (ql <= tl && qr >= tr) return tree[p];
        int m = (tl + tr) / 2;
        return comb(
            query(l(p), tl, m, ql, min(m, qr)),
            query(r(p), m+1, tr, max(ql, m+1), qr)
        );
    }

    void update(int ql, int qr, ll a, ll d) { update(1, 0, n-1, ql, qr, a, d); }
    void update(int p, int tl, int tr, int ql, int qr, ll a, ll d) {
        push(p, tl, tr);
        if (qr < tl || ql > tr) return;
        if (ql <= tl && qr >= tr) {
            lazy_a[p] = a + (d * (qr - tr));
            lazy_d[p] = d;
            push(p, tl, tr);
            return;
        }
        int m = (tl + tr) / 2;
        update(l(p), tl, m, ql, qr, a, d);
        update(r(p), m+1, tr, ql, qr, a, d);
        tree[p] = comb(tree[l(p)], tree[r(p)]);
    }
};

const int MAXN = 3e5;
set<pii> s;
int X[MAXN];
int V[MAXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m, q; cin >> n >> m >> q;
    forn(i, m) {
        cin >> X[i];
        --X[i];
    }
    forn(i, m) {
        cin >> V[i];
        s.emplace(X[i], V[i]);
    }
    vector<ll> A(n);
    int lo = 0;
    ll pv = 0;
    for (auto [x, v] : s) {
        while (lo <= x) {
            A[lo] = pv * (x - lo);
            ++lo;
        }
        pv = v;
    }
    ST st(A);
    forn(i, q) {
        int t; cin >> t;
        if (t == 1) {
            int x, v; cin >> x >> v;
            --x;
            auto it = s.lower_bound({x, v});
            int hi = it->x;
            auto [lo, pv] = *--it;
            st.update(lo+1, x, ll(-pv) * (hi - x), 0);
            st.update(x+1, hi, 0, v - pv);
            s.emplace(x, v);
        } else {
            int l, r; cin >> l >> r;
            cout << st.query(l - 1, r - 1) << "\n";
        }
    }
}
