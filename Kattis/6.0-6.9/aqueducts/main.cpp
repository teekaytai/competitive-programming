#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define len(x) (int) x.size()

double EPS = 1e-6;

struct MCF {
    static constexpr ll INF = 1e18;

    int V;
    vvi AL;
    vector<tuple<int, double, ll, ll>> EL;
    vector<double> ds;
    vector<bool> vis;
    vi last;

    int last_s, last_t;
    ll last_mf;
    double tc; ll tf;

    MCF(int initial_V) : V(initial_V) {
        AL.assign(V, vi());
        EL.clear();
        vis.assign(V, false);
        last_s = last_t = -1;
    }

    void add_edge(int u, int v, double cost = 0, ll cap = 1, bool directed = true) {
        if (u < 0) u += V;
        if (v < 0) v += V;
        if (u == v) return;
        AL[u].push_back(len(EL));
        EL.emplace_back(v, cost, cap, 0);
        AL[v].push_back(len(EL));
        EL.emplace_back(u, -cost, 0, 0);
        if (!directed) add_edge(v, u, cost, cap);
        last_s = last_t = -1;
    }

    bool bf(int s, int t) {
        ds.assign(V, INFINITY);
        ds[s] = 0;
        vis[s] = true;
        queue<int> q({s});
        while (!q.empty()) {
            int u = q.front(); q.pop();
            vis[u] = false;
            for (int idx : AL[u]) {
                auto [v, cost, cap, flow] = EL[idx];
                double d = ds[u] + cost;
                if (cap > flow && ds[v] - d > EPS) {
                    ds[v] = d;
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }
        return ds[t] != INFINITY;
    }

    ll dfs(int u, int t, ll f) {
        if ((u == t) || (f == 0)) return f;
        vis[u] = true;
        for (int& i = last[u]; i < len(AL[u]); ++i) {
            auto& [v, cost, cap, flow] = EL[AL[u][i]];
            if (vis[v] || (ds[u] + cost - ds[v]) > EPS) continue;
            if (ll pushed = dfs(v, t, min(f, cap - flow))) {
                flow += pushed;
                auto& rflow = get<3>(EL[AL[u][i]^1]);
                rflow -= pushed;
                vis[u] = false;
                return pushed;
            }
        }
        vis[u] = false;
        return 0;
    }

    void dinic(int s, int t, ll mf = INF) {
        if (s < 0) s += V;
        if (t < 0) t += V;
        if (s == last_s && t == last_t && mf == last_mf) return;
        last_s = s; last_t = t; last_mf = mf;

        for (auto& [v, cost, cap, flow] : EL) flow = 0;
        tf = 0; tc = 0;
        while (tf < mf && bf(s, t)) {
            last.assign(V, 0);
            while (ll f = dfs(s, t, mf - tf)) {
                tf += f;
                tc += double(f) * ds[t];
            }
        }
    }

    pair<ll, double> min_cost_flow(int s, int t, ll mf = INF) {
        dinic(s, t, mf);
        return {tf, tc};
    }
};

tuple<int, int, int> a[500];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, S, T, q; cin >> n >> S >> T >> q;
    int s = -1;
    int t = -2;
    MCF mcf(n+2);
    forn(i, n) {
        int x, y, h; cin >> x >> y >> h;
        a[i] = make_tuple(x, y, h);
    }
    forn(i, n) forn(j, i) {
        auto [x1, y1, h1] = a[i];
        auto [x2, y2, h2] = a[j];
        double d;
        if (h1 != h2 && (d = hypot(hypot(x1-x2, y1-y2), h1-h2)) - q <= EPS) {
            if (h1 < h2) mcf.add_edge(j, i, d, MCF::INF);
            else mcf.add_edge(i, j, d, MCF::INF);
        }
    }
    forn (i, S) {
        int x; cin >> x;
        mcf.add_edge(s, x-1);
    }
    forn (i, T) {
        int x; cin >> x;
        mcf.add_edge(x-1, t);
    }
    auto [mf, mc] = mcf.min_cost_flow(s, t);
    if (mf < T) cout << "IMPOSSIBLE\n";
    else cout << fixed << setprecision(7) << mc << "\n";
}
