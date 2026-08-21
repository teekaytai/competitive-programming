#include <bits/stdc++.h>
using namespace std;

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
        if (d <= tree[pos]) return;
        tree[pos] = d;
        for (; pos /= 2;) {
            tree[pos] = comb(tree[pos * 2], tree[pos * 2 + 1]);
        }
    }
};

void solve() {
    int n; cin >> n;
    ST st(1000001);
    int ans = 0;
    forn(_, n) {
        int x; cin >> x;
        int v = st.query(x + 1, 1000001);
        st.update(x, v + 1);
        ans = max(ans, v + 1);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
