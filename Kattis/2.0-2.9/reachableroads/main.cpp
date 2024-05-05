#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); ++i)
#define all(x) x.begin(), x.end()

struct UF {
    vector<int> pars;
    vector<int> sizes;
    int num_sets;

    UF(int n) {
        pars.resize(n);
        iota(all(pars), 0);
        sizes.assign(n, 1);
        num_sets = n;
    }

    int find(int i) {
        return pars[i] == i ? i : (pars[i] = find(pars[i]));
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

    bool is_same_set(int i, int j) { return find(i) == find(j); }
    int set_size(int i) { return sizes[find(i)]; }
};

void solve() {
    int n, m; cin >> n >> m;
    UF uf(n);
    forn(i, m) {
        int u, v; cin >> u >> v;
        uf.onion(u, v);
    }
    cout << uf.num_sets-1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
