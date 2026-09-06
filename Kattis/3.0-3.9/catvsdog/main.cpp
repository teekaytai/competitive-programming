#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define len(x) int(size(x))
#define pb push_back
#define eb emplace_back

struct MF {
    static constexpr ll INF = 1e18;

    int V;
    vvi AL;
    vector<tuple<int, ll, ll>> EL;
    vi ds;
    vi last;

    ll mf = 0;

    MF(int _V) : V(_V) {
        AL.assign(V, vi());
        EL.clear();
    }

    void add_edge(int u, int v, ll cap = 1, bool directed = true) {
        if (u < 0) u += V;
        if (v < 0) v += V;
        if (u == v) return;
        AL[u].push_back(len(EL));
        EL.eb(v, cap, 0);
        AL[v].push_back(len(EL));
        EL.eb(u, directed ? 0 : cap, 0);
    }

    bool bfs(int s, int t) {
        ds.assign(V, -1);
        int d = 0;
        ds[s] = d;
        queue<int> q({s});
        while (!q.empty()) {
            d += 1;
            int i = len(q);
            while (i--) {
                int u = q.front(); q.pop();
                for (int idx : AL[u]) {
                    auto [v, cap, flow] = EL[idx];
                    if (cap > flow && ds[v] == -1) {
                        ds[v] = d;
                        q.push(v);
                    }
                }
            }
            if (ds[t] != -1) return true;
        }
        return false;
    }

    ll dfs(int u, int t, ll f = INF) {
        if ((u == t) || (f == 0)) return f;
        for (int& i = last[u]; i < len(AL[u]); ++i) {
            auto& [v, cap, flow] = EL[AL[u][i]];
            if (ds[v] != ds[u] + 1) continue;
            if (ll pushed = dfs(v, t, min(f, cap - flow))) {
                flow += pushed;
                auto& rflow = get<2>(EL[AL[u][i]^1]);
                rflow -= pushed;
                return pushed;
            }
        }
        return 0;
    }

    void dinic(int s, int t) {
        if (s < 0) s += V;
        if (t < 0) t += V;

        for (auto& [v, cap, flow] : EL) flow = 0;
        mf = 0;

        while (bfs(s, t)) {
            last.assign(V, 0);
            while (ll f = dfs(s, t)) {
                mf += f;
            }
        }
    }

    ll max_flow(int s, int t) {
        dinic(s, t);
        return mf;
    }
};

void solve() {
    int n, m, q; cin >> n >> m >> q;
    vvi c1(n);
    vvi c2(n);
    vvi d1(m);
    vvi d2(m);
    MF mf(q + 2);
    int s = -2;
    int t = -1;
    forn(i, q) {
        char k;
        int x, y;
        cin >> k >> x >> k >> y; --x; --y;
        if (k == 'D') {
            mf.add_edge(s, i);
            for(int j : c2[x]) mf.add_edge(i, j);
            for(int j : d2[y]) mf.add_edge(i, j);
            c1[x].pb(i);
            d1[y].pb(i);
        } else {
            mf.add_edge(i, t);
            for(int j : c1[y]) mf.add_edge(j, i);
            for(int j : d1[x]) mf.add_edge(j, i);
            c2[y].pb(i);
            d2[x].pb(i);
        }
    }
    cout << q - mf.max_flow(s, t) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
