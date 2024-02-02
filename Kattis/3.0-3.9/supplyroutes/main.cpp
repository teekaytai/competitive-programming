#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forn1(i, n) for (int i = 1; i <= (n); ++i)
#define rforn(i, n) for (int i = (n) - 1; i >= 0; --i)
#define rforn1(i, n) for (int i = (n); i > 0; --i)
#define all(x) x.begin(), x.end()
#define len(x) (int) x.size()
#define LSB(x) ((x) & -(x))
#define pb push_back
#define x first
#define y second

struct UF {
    vector<int> pars;
    vector<int> sizes;
    int num_sets;

    UF(int n) {
        pars.resize(n);
        iota(all(pars), 0);
        sizes.assign(n, 0);
        num_sets = n;
    }

    int find(int i) {
        return pars[i] == i ? i : (pars[i] = find(pars[i]));
    }

    void onion(int i, int j) {
        int r1 = find(i);
        int r2 = find(j);
        if (r1 != r2) {
            if (sizes[r2] > sizes[r1]) swap(r1, r2);
            pars[r2] = r1;
            sizes[r1] += sizes[r2];
            num_sets -= 1;
        }
    }

    bool is_same_set(int i, int j) { return find(i) == find(j); }
    int set_size(int k) { return sizes[find(k)]; }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m, q; cin >> n >> m >> q;
    set<pii> edges;
    forn(_, m) {
        int u, v; cin >> u >> v;
        edges.emplace(u, v);
    }
    vector<tuple<int, int, int>> queries;
    forn(_, q) {
        int t, u, v; cin >> t >> u >> v;
        queries.emplace_back(t, u, v);
        if (t == 0) edges.erase({u, v});
    }
    UF uf(n);
    for (auto [u, v] : edges) {
        uf.onion(u, v);
    }
    vector<string> ans;
    rforn(i, q) {
        auto [t, u, v] = queries[i];
        if (t == 0) {
            uf.onion(u, v);
        } else {
            ans.pb((uf.is_same_set(u, v) ? "safe\n" : "unsafe\n"));
        }
    }
    rforn(i, len(ans)) {
        cout << ans[i];
    }

    return 0;
}
