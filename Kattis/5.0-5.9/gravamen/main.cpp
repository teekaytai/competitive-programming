#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define len(x) (int) (x).size()
#define eb emplace_back

struct MF {
    static constexpr ll INF = 1e18;

    int V;
    vvi AL;
    vector<tuple<int, ll, ll>> EL;
    vi ds;
    vi last;

    ll mf;

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

    vector<pii> max_flow_edges(int s, int t, int k) {
        dinic(s, t);
        vector<pii> flows;
        forn (u, k) {
            for (int idx : AL[u]) {
                auto [v, cap, flow] = EL[idx];
                if (flow > 0) flows.eb(v, u);
            }
        }
        sort(all(flows));
        return flows;
    }
};

void solve() {
    int n, m, l; cin >> n >> m >> l;
    int s = -1;
    int t = -2;
    MF mf(n + m + l + 2);
    forn(i, n + m) mf.add_edge(s, i);
    forn(i, l) mf.add_edge(n + m + i, t);
    forn(i, l) {
        int u, v; cin >> u >> v;
        --u; --v;
        mf.add_edge(u, n + m + i);
        mf.add_edge(n + v, n + m + i);
    }
    int lo = 1;
    int hi = l;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        for (int i = 0; i < 2 * (n + m); i += 2) get<1>(mf.EL[i]) = mid;
        if (mf.max_flow(s, t) == l) hi = mid;
        else lo = mid + 1;
    }
    for (int i = 0; i < 2 * (n + m); i += 2) get<1>(mf.EL[i]) = lo;
    for (auto [_, u] : mf.max_flow_edges(s, t, n + m)) {
        if (u < n) cout << "INDV " << u + 1 << "\n";
        else cout << "CORP " << u - n + 1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
