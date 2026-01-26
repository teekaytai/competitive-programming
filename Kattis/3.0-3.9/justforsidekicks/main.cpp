#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forn1(i, n) for (int i = 1; i <= (n); ++i)
#define len(x) int(size(x))
#define LSB(x) ((x) & -(x))

struct T {
    array<int, 6> a = {0};

    T& operator+=(const T& other) {
        forn(i, 6) a[i] += other.a[i];
        return *this;
    }

    T operator-(const T& other) {
        array<int, 6> b = {0};
        forn(i, 6) b[i] = a[i] - other.a[i];
        return {b};
    }
};

struct FT {
    vector<T> tree;

    FT(const string& s) { build(s); }

    void build(const string& s) {
        int n = len(s);
        tree.resize(n + 1);
        forn1(i, n) {
            ++tree[i].a[s[i - 1] - '1'];
            if (i + LSB(i) <= n) {
                tree[i + LSB(i)] += tree[i];
            }
        }
    }

    T query(int k) {
        T t;
        for (int i = min(k + 1, len(tree) - 1); i > 0; i -= LSB(i)) {
            t += tree[i];
        }
        return t;
    }

    T query(int lo, int hi) {
        return query(hi) - query(lo - 1);
    }

    void update(int k, T d) {
        assert(k >= 0 && k < len(tree) - 1);
        for (int i = k + 1; i < len(tree); i += LSB(i)) {
            tree[i] += d;
        }
    }
};

void solve() {
    int n, q; cin >> n >> q;
    array<int, 6> vs;
    forn(i, 6) cin >> vs[i];
    string s; cin >> s;
    FT ft(s);
    forn(_, q) {
        int t, x, y; cin >> t >> x >> y;
        if (t == 1) {
            --x; --y;
            array<int, 6> a = {0};
            a[s[x] - '1'] = -1;
            s[x] = (char) ('1' + y);
            a[y] = 1;
            ft.update(x, {a});
        } else if (t == 2) {
            vs[x - 1] = y;
        } else {
            auto a = ft.query(x - 1, y - 1).a;
            ll ans = 0;
            forn(i, 6) {
                ans += (ll) a[i] * vs[i];
            }
            cout << ans << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();
}
