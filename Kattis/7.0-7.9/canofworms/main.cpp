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
#define pb push_back
#define x first
#define y second

template<typename T>
inline T MSB(T x) {
    T b = 1;
    while (b * 2 < x) b *= 2;
    return b;
}

const int INF = 1e9;

struct ST {
    int n;
    vector<pii> A, tree;

    inline int l(int p) { return p * 2; }
    inline int r(int p) { return p * 2 + 1; }

    // Initialise lazy with flag to indicate no updates necessary
    ST(int n, pii v = {0, 0}) : n(n), A(n, v), tree(4*n, v) {}

    ST(const vector<pii>& initial_A) : ST(len(initial_A)) {
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

    inline pii comb(pii x, pii y) {
        return {min(x.x, y.x), max(x.y, y.y)};
    }

    pii query(int ql, int qr) { return query(1, 0, n-1, ql, qr); }
    pii query(int p, int tl, int tr, int ql, int qr) {
        if (ql > qr) return {INF, -INF};  // Identity value
        if (ql <= tl && qr >= tr) return tree[p];
        int m = (tl + tr) / 2;
        return comb(
            query(l(p), tl, m, ql, min(m, qr)),
            query(r(p), m+1, tr, max(ql, m+1), qr)
        );
    }

    void update(int q, pii d) { update(1, 0, n-1, q, q, d); }
    void update(int p, int tl, int tr, int ql, int qr, pii d) {
        if (ql > qr) return;
        if (ql <= tl && qr >= tr) {
            tree[p] = d;
            A[ql] = d;
            return;
        }
        int m = (tl + tr) / 2;
        update(l(p), tl, m, ql, min(m, qr), d);
        update(r(p), m+1, tr, max(ql, m+1), qr, d);
        tree[p] = comb(tree[l(p)], tree[r(p)]);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vi A(n);
    vi R(n);
    forn(i, n) {
        int x, r; cin >> x >> r;
        A[i] = x;
        R[i] = r;
    }
    vi I(n);
    iota(all(I), 0);
    sort(all(I),[&](int i1, int i2){return A[i1] < A[i2];});
    sort(all(A));
    vector<pii> P;
    forn(i, n) {
        int lo = int(lower_bound(all(A), A[i] - R[I[i]]) - A.begin());
        int hi = int(upper_bound(all(A), A[i] + R[I[i]]) - A.begin()) - 1;
        P.emplace_back(lo, hi);
    }
    ST st(P);
    vi res(n);
    forn(i, n) {
        pii ans = P[i];
        pii ans2;
        while ((ans2 = st.query(ans.x, ans.y)) != ans) {
            ans = ans2;
        }
        st.update(i, ans);
        res[I[i]] = ans.y - ans.x + 1;
    }
    for (int v : res) cout << v << " ";
    return 0;
}
