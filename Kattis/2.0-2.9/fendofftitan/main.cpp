#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef tuple<int, int, int> t3i;
typedef tuple<int, int, ll, int> pqn;
typedef vector<bool> vb;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define eb emplace_back

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m, s, t; cin >> n >> m >> s >> t;
    --s; --t;
    vector<vector<t3i>> g(n, vector<t3i>());
    forn(_, m) {
        int u, v, w, c; cin >> u >> v >> w >> c;
        --u; --v;
        g[u].eb(v, w, c);
        g[v].eb(u, w, c);
    }
    priority_queue<pqn, vector<pqn>, greater<>> pq;
    pq.emplace(0, 0, 0, s);
    vb seen(n, false);
    while (!pq.empty()) {
        auto [c2, c1, d, u] = pq.top();
        pq.pop();
        if (seen[u]) continue;
        seen[u] = true;
        if (u == t) {
            cout << d << " " << c1 << " " << c2 << "\n";
            return 0;
        }
        for (auto [v, w, c] : g[u]) if (!seen[v]) {
            pq.emplace(c2 + (c==2), c1 + (c==1), d + w, v);
        }
    }
    cout << "IMPOSSIBLE\n";
}
