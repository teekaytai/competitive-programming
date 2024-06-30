#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define all(x) x.begin(), x.end()
#define len(x) (int) x.size()
#define fi first
#define se second

const int INF = 2e9;

struct ST {
    int n;
    vector<int> A;
    vector<pii> tree;
    vector<int> lazy;

    inline int l(int p) { return p * 2; }
    inline int r(int p) { return p * 2 + 1; }

    ST(const vector<int>&& _A) : n(len(_A)), A(_A), tree(4*n), lazy(4*n, -1) {
        build();
    }

    void build() { build(1, 0, n-1); }
    void build(int p, int tl, int tr) {
        if (tl == tr) {
            tree[p] = {A[tl], tl};
            return;
        }
        int m = (tl + tr) / 2;
        build(l(p), tl, m);
        build(r(p), m+1, tr);
        tree[p] = comb(tree[l(p)], tree[r(p)]);
    }

    inline pii comb(pii x, pii y) {
        return min(x, y);
    }

    void push(int p, int tl, int tr) {
        if (lazy[p] == -1) return;
        tree[p] = {lazy[p], tl};
        if (tl != tr) {
            lazy[l(p)] = lazy[p];
            lazy[r(p)] = lazy[p];
        } else {
            A[tl] = lazy[p];
        }
        lazy[p] = -1;
    }

    // Both ql and qr inclusive, zero-indexed
    pii query(int ql, int qr) { return query(1, 0, n-1, ql, qr); }
    pii query(int p, int tl, int tr, int ql, int qr) {
        push(p, tl, tr);
        if (ql > qr) return {INF, -1};
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

int tshirt(int N, int L[], int H[], int T[]) {
    vector<pii> a(N);
    forn(i, N) a[i] = {L[i], H[i]};
    sort(all(a));
    vi b(N);
    forn(i, N) b[i] = a[i].se;
    ST st(move(b));
    sort(T, T + N);
    int t = 0;
    forn (i, N) {
        auto it = lower_bound(all(a), make_pair(T[i] + 1, -1));
        auto [h, idx] = st.query(0, it - a.begin() - 1);
        while (h < T[i]) {
            st.update(idx, idx, INF);
            tie(h, idx) = st.query(0, it - a.begin() - 1);
        }
        if (h < INF) {
            ++t;
            st.update(idx, idx, INF);
        }
    }
    return t;
}
