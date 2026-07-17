#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define rforn(i, n) for (int i = (n) - 1; i >= 0; --i)

struct ST {
    typedef int T;
    static constexpr T ID = 0;

    inline T comb(T a, T b) {
        return max(a, b);
    }

    int n;
    vector<T> tree;

    ST(int n, T v = ID) : n(n), tree(2 * n, v) {
        rforn (i, n) {
            tree[i] = comb(tree[i * 2], tree[i * 2 + 1]);
        }
    }

    T query(int L, int R) {
        T ra = ID, rb = ID;
        for (L += n, R += n; L < R; L /= 2, R /= 2) {
            if (L % 2) ra = comb(ra, tree[L++]);
            if (R % 2) rb = comb(tree[--R], rb);
        }
        return comb(ra, rb);
    }

    void update(int pos, T d) {
        pos += n;
        tree[pos] += d;
        for (; pos /= 2;) {
            tree[pos] = comb(tree[pos * 2], tree[pos * 2 + 1]);
        }
    }
};

void solve(int t) {
    int n, p, q; cin >> n >> p >> q;
    n *= n; ++p; ++q;
    vi ra(n + 1, -1), b(q);
    forn(i, p) {
        int x; cin >> x;
        ra[x] = i;
    }
    forn(i, q) cin >> b[i];
    ST st(p);
    forn(i, q) {
        int x = b[i];
        if (ra[x] == -1) continue;
        int j = ra[x];
        int mx = st.query(0, j);
        st.update(j, mx + 1);
    }
    cout << "Case " << t << ": " << st.query(0, p) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    forn(i, tc) {
        solve(i + 1);
    }
}
