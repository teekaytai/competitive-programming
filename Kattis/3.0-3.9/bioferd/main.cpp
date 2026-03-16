#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define len(x) (int) x.size()

struct MF {
    static constexpr ll INF = 1e18;

    int V;
    vvi AL;
    vector<tuple<int, ll, ll>> EL;
    vi ds;
    vi last;

    int last_s, last_t;
    ll mf;

    MF(int initial_V) : V(initial_V) {
        AL.assign(V, vi());
        EL.clear();
        last_s = last_t = -1;
    }

    void add_edge(int u, int v, ll cap = 1, bool directed = true) {
        if (u == v) return;
        AL[u].push_back(len(EL));
        EL.emplace_back(v, cap, 0);
        AL[v].push_back(len(EL));
        EL.emplace_back(u, directed ? 0 : cap, 0);
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
        if (s == last_s && t == last_t) return;
        last_s = s; last_t = t;
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

    vector<tuple<int, int, ll>> max_flow_edges(int s, int t) {
        dinic(s, t);
        vector<tuple<int, int, ll>> flows;
        forn (u, V) {
            for (int idx : AL[u]) {
                auto [v, cap, flow] = EL[idx];
                if (flow > 0) flows.emplace_back(u, v, flow);
            }
        }
        return flows;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    MF mf(2*n+2);
    int s = 2*n;
    int t = 2*n+1;
    forn(i, n) {
        int k; cin >> k;
        mf.add_edge(s, i);
        mf.add_edge(n+i, t);
        forn(j, k) {
            int x; cin >> x;
            mf.add_edge(i, n+x-1);
        }
    }
    if (mf.max_flow(s, t) != n) {
        cout << "Neibb\n";
    } else {
        vector<int> ans(n);
        for (auto [u, v, _] : mf.max_flow_edges(s, t)) {
            if (u < n) ans[v-n] = u+1;
        }
        for (int x : ans) cout << x << " ";
        cout << "\n";
    }
}
