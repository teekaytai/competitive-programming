#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forn1(i, n) for (int i = 1; i <= (n); ++i)
#define len(x) int(size(x))
#define LSB(x) ((x) & -(x))
inline int MSB(int x) { return x ? 1 << (31 - __builtin_clz(x)) : 0; }
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

struct FT {
    vector<ll> tree;

    FT(int n) { tree.assign(n + 1, 0); }

    FT(const vector<ll>& a) { build(a); }

    void build(const vector<ll>& a) {
        int n = len(a);
        tree.assign(n + 1, 0);
        forn1(i, n) {
            tree[i] += a[i - 1];
            if (i + LSB(i) <= n) {
                tree[i + LSB(i)] += tree[i];
            }
        }
    }

    ll query(int k) {
        ll t = 0;
        for (int i = min(k + 1, len(tree) - 1); i > 0; i -= LSB(i)) {
            t += tree[i];
        }
        return t;
    }

    ll query(int lo, int hi) {
        return query(hi) - query(lo - 1);
    }

    void update(int k, ll d) {
        assert(k >= 0 && k < len(tree) - 1);
        for (int i = k + 1; i < len(tree); i += LSB(i)) {
            tree[i] += d;
        }
    }
};

int m[100000];

void solve() {
    int n; cin >> n;

    vll a(n, 1);
    FT ft(a);
    forn(i, n) {
        int x; cin >> x; --x;
        m[x] = i;
    }
    int l = 0;
    int h = n - 1;
    while (l <= h) {
        int i = m[l];
        cout << ft.query(0, i - 1) << "\n";
        ft.update(i, -1);
        ++l;
        if (l > h) break;
        i = m[h];
        cout << ft.query(i + 1, n - 1) << "\n";
        ft.update(i, -1);
        --h;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    // int tc; cin >> tc;
    // while (tc--) {
    solve();
    // }
}
