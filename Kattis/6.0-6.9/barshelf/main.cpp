#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define len(x) (int) (x).size()
#define LSB(x) ((x) & -(x))
#define pb push_back
#define fi first
#define se second

struct FT {
    vector<ll> tree;

    FT(int n) { tree.assign(n + 1, 0); }

    FT(const vector<ll>& a) { build(a); }

    void build(const vector<ll>& a) {
        int n = len(a);
        tree.assign(n + 1, 0);
        forn(i, n) {
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

void solve() {
    int n; cin >> n;
    vi a;
    a.reserve(n);
    set<int> s;
    forn(_, n) {
        int x; cin >> x;
        a.pb(x);
        s.insert(x);
    }
    map<int, int> m;
    int i = 0;
    for (int x : s) {
        m[x] = i++;
    }
    FT ft(n);
    FT ft2(n);
    ll ans = 0;
    for(int x : a) {
        auto it = m.lower_bound(2 * x);
        int i = it == m.end() ? n : it->se;
        int j = m[x];
        ans += ft2.query(i, n - 1);
        ft2.update(j, ft.query(i, n - 1));
        ft.update(j, 1);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();
}
