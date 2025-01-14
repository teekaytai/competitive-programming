#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef tuple<int, int, int> t3i;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()

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

    int onion(int i, int j) {
        int r1 = find(i);
        int r2 = find(j);
        if (r1 == r2) return false;
        if (sizes[r2] > sizes[r1]) swap(r1, r2);
        pars[r2] = r1;
        int p = sizes[r1] * sizes[r2];
        sizes[r1] += sizes[r2];
        num_sets -= 1;
        return p - 1;
    }
};

void solve() {
    int n; cin >> n;
    vector<t3i> e;
    forn(i, n-1) {
        int u, v, w; cin >> u >> v >> w;
        --u; --v;
        e.emplace_back(w, u, v);
    }
    sort(all(e));
    UF uf(n);
    ll t = 0;
    for (auto [w, u, v] : e) {
        t += (ll)(w + 1) * uf.onion(u, v) + w;
    }
    cout << t << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
