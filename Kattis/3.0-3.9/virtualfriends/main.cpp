#include <bits/stdc++.h>
using namespace std;

#define umap unordered_map
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define all(x) x.begin(), x.end()
#define len(x) (int) x.size()

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

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;

void solve() {
    int n; cin >> n;
    umap<string, int> m;
    UF uf(2*n);
    forn(_, n) {
        string s, t; cin >> s >> t;
        m.try_emplace(s, len(m));
        m.try_emplace(t, len(m));
        int i = m[s];
        int j = m[t];
        uf.onion(i, j);
        cout << uf.set_size(i) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
