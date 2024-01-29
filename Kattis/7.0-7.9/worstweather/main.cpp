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

const int INF = 2e9;

struct ST {
    int n;
    vector<int> A, tree;

    inline int l(int p) { return p * 2; }
    inline int r(int p) { return p * 2 + 1; }

    // Initialise lazy with flag to indicate no updates necessary
    ST(int N, int v = 0) : n(N), A(N, v), tree(4*N, v) {}

    ST(const vector<int>& initial_A) : ST(len(initial_A)) {
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

    inline int comb(int x, int y) {
        return max(x, y);
    }

    int query(int ql, int qr) { return query(1, 0, n-1, ql, qr); }
    int query(int p, int tl, int tr, int ql, int qr) {
        if (ql > qr) return -INF;  // Identity value
        if (ql <= tl && qr >= tr) return tree[p];
        int m = (tl + tr) / 2;
        return comb(
            query(l(p), tl, m, ql, min(m, qr)),
            query(r(p), m+1, tr, max(ql, m+1), qr)
        );
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    while (1) {
        int n; cin >> n;
        if (n == 0) {
            cin >> n;
            break;
        }
        vector<int> ys(n);
        vector<int> rs(n);
        forn(i, n) {
            cin >> ys[i] >> rs[i];
        }
        ST st(rs);
        int m; cin >> m;
        forn(i, m) {
            int lo, hi; cin >> lo >> hi;
            int i1 = upper_bound(all(ys), lo) - ys.begin() - 1;
            int i2 = lower_bound(all(ys), hi) - ys.begin();
            bool in1 = i1 >= 0 && ys[i1] == lo;
            bool in2 = i2 < n && ys[i2] == hi;
            if (!in1 && !in2) {
                cout << "maybe" << "\n";
                continue;
            }
            int r2 = in2 ? rs[i2] : rs[i1];
            if (in1 && rs[i1] < r2) {
                cout << "false" << "\n";
            } else {
                cout << (st.query(i1+1, i2-1) < r2 ? (in1 && in2 && i2 - i1 == hi - lo ? "true" : "maybe") : "false") << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}
