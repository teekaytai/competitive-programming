#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define forn(i, n) for (int i = 0; i < (n); ++i)

struct UF {
    vector<int> pars;
    vector<int> sizes;
    int num_sets;

    UF(int n) {
        pars.assign(n, -1);
        sizes.assign(n, 1);
        num_sets = n;
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
        num_sets -= 1;
        return true;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    UF uf(n);
    forn(_, m) {
        int u, v; cin >> u >> v; --u; --v;
        uf.onion(u, v);
    }
    ll ans = 0;
    forn(i, n) if (uf.pars[i] == -1) {
        ans += (ll) uf.sizes[i] * (uf.sizes[i] - 1);
    }
    cout << fixed << setprecision(7) << (double) ans / ((ll) n * (n - 1)) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
