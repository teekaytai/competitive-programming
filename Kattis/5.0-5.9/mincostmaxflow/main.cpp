#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define len(x) (int) x.size()

template <typename... Ts>
inline void print(const Ts&... args) {
    const char* sep = "";
    (((cout << sep << args), sep = " "), ...);
    cout << "\n";
}

struct MCF {
    static constexpr ll INF = 1e18;

    int V;
    vvi AL;
    vector<tuple<int, ll, ll, ll>> EL;
    vll ds;
    vector<bool> vis;
    vi last;

    int last_s, last_t;
    ll last_mf;
    ll tc; ll tf;

    MCF(int initial_V) : V(initial_V) {
        AL.assign(V, vi());
        EL.clear();
        vis.assign(V, false);
        last_s = last_t = -1;
    }

    void add_edge(int u, int v, ll cost, ll cap = 1, bool directed = true) {
        if (u == v) return;
        AL[u].push_back(len(EL));
        EL.emplace_back(v, cost, cap, 0);
        AL[v].push_back(len(EL));
        EL.emplace_back(u, -cost, 0, 0);
        if (!directed) add_edge(v, u, cost, cap);
    }

    bool bf(int s, int t) {
        ds.assign(V, MCF::INF);
        ds[s] = 0;
        vis[s] = true;
        queue<int> q({s});
        while (!q.empty()) {
            int u = q.front(); q.pop();
            vis[u] = false;
            for (int idx : AL[u]) {
                auto [v, cost, cap, flow] = EL[idx];
                ll d = ds[u] + cost;
                if (cap > flow && d < ds[v]) {
                    ds[v] = d;
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }
        return ds[t] != INF;
    }

    ll dfs(int u, int t, ll f) {
        if ((u == t) || (f == 0)) return f;
        vis[u] = true;
        for (int& i = last[u]; i < len(AL[u]); ++i) {
            auto& [v, cost, cap, flow] = EL[AL[u][i]];
            if (vis[v] || ds[u] + cost != ds[v]) continue;
            if (ll pushed = dfs(v, t, min(f, cap - flow))) {
                tc += pushed * cost;
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
        if (s == last_s && t == last_t && mf == last_mf) return;
        last_s = s; last_t = t; last_mf = mf;
        for (auto& [v, cost, cap, flow] : EL) flow = 0;
        tf = 0; tc = 0;
        while (tf < mf && bf(s, t)) {
            last.assign(V, 0);
            while (ll f = dfs(s, t, mf - tf)) {
                tf += f;
            }
        }
    }

    pll min_cost_flow(int s, int t, ll mf = INF) {
        dinic(s, t, mf);
        return {tf, tc};
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m, s, t;
    cin >> n >> m >> s >> t;
    MCF mcf(n);
    forn (i, m) {
        int u, v, c, w; cin >> u >> v >> c >> w;
        mcf.add_edge(u, v, w, c);
    }

    auto [mf, mc] = mcf.min_cost_flow(s, t);
    print(mf, mc);
}
