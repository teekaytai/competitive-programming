#include <bits/stdc++.h>
using namespace std;

#define umap unordered_map
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define len(x) int(size(x))
#define fi first
#define se second

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

    int set_size(int i) { return sizes[find(i)]; }
};

void solve() {
    int n; cin >> n;
    umap<string, int> m;
    UF uf(2 * n);
    forn(_, n) {
        string s, t; cin >> s >> t;
        int u = m.try_emplace(s, len(m)).fi->se;
        int v = m.try_emplace(t, len(m)).fi->se;
        uf.onion(u, v);
        cout << uf.set_size(u) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();
}
