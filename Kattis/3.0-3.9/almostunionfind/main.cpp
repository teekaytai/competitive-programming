#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define all(x) begin(x), end(x)

struct UF {
    vector<int> pars;
    vector<int> sizes;
    vector<int> vals;
    vector<ll> sums;

    UF(int n) {
        pars.assign(n, -1);
        sizes.assign(n, 1);
        vals.resize(n);
        iota(all(vals), 0);
        sums.resize(n);
        iota(all(sums), 0);
    }

    int find(int i) {
        return pars[i] < 0 ? i : (pars[i] = find(pars[i]));
    }

    bool onion(int i, int j) {
        int r1 = find(i);
        int r2 = find(j);
        if (r1 == r2) return false;
        if (sizes[r2] > sizes[r1]) swap(r1, r2);
        pars[r2] = r1;
        sizes[r1] += sizes[r2];
        sums[r1] += sums[r2];
        return true;
    }

    void move(int i, int j) {
        int r = find(i);
        --sizes[r];
        sums[r] -= vals[i];
        vals[j] = vals[i];
        sums[j] = vals[j];
    }

    pair<int, ll> query(int i) {
        int r = find(i);
        return {sizes[r], sums[r]};
    }
};

void solve(int n) {
    int q; cin >> q;
    vi a(n + 1);
    iota(all(a), 0);
    UF uf(n + q + 1);
    int c = n;
    forn(_, q) {
        int t, u, v; cin >> t;
        if (t == 1) {
            cin >> u >> v;
            uf.onion(a[u], a[v]);
        } else if (t == 2) {
            cin >> u >> v;
            uf.move(a[u], ++c);
            uf.onion(c, a[v]);
            a[u] = c;
        } else {
            cin >> u;
            auto [s, x] = uf.query(a[u]);
            cout << s << " " << x << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    while (cin >> n) {
        solve(n);
    }
}
