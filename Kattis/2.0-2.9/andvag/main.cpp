#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()

struct UF {
    vector<int> pars;
    vector<int> sizes;
    vector<int> ms;
    int num_sets;

    UF(int n) {
        pars.resize(n);
        iota(all(pars), 0);
        sizes.assign(n, 1);
        ms.assign(n, 0);
        num_sets = n;
    }

    int find(int i) {
        return pars[i] == i ? i : (pars[i] = find(pars[i]));
    }

    bool onion(int i, int j, int m) {
        int r1 = find(i);
        int r2 = find(j);
        ms[r1] |= m;
        if (r1 == r2) return false;
        if (sizes[r2] > sizes[r1]) swap(r1, r2);
        pars[r2] = r1;
        sizes[r1] += sizes[r2];
        ms[r1] |= ms[r2];
        num_sets -= 1;
        return true;
    }

    int is_same_set(int i, int j) { return find(i) == find(j) ? __builtin_popcount(ms[find(i)]) : -1; }
};


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m, q; cin >> n >> m >> q;
    UF uf(n);
    forn(_, m) {
        int u, v, x; cin >> u >> v >> x;
        --u; --v;
        uf.onion(u, v, x);
    }
    forn(_, q) {
        int u, v; cin >> u >> v;
        --u; --v;
        cout << uf.is_same_set(u, v) << "\n";
    }
}
