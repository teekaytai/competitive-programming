#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
#define umap unordered_map
#define uset unordered_set
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forn1(i, n) for (int i = 1; i <= (n); ++i)
#define rforn(i, n) for (int i = (n) - 1; i >= 0; --i)
#define rforn1(i, n) for (int i = (n); i > 0; --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define len(x) (int) x.size()
#define LSB(x) ((x) & -(x))
inline int MSB(int x) { return x ? 1 << (31 - __builtin_clz(x)) : 0; }
#define pb push_back
#define x first
#define y second

template <typename... Ts>
inline void print(const Ts&... args) {
    const char* sep = "";
    (((cout << sep << args), sep = " "), ...);
    cout << "\n";
}
template <typename... Ts>
inline void printerr(const Ts&... args) {
    const char* sep = "";
    cerr << "\u001B[31m";
    (((cerr << sep << args), sep = " "), ...);
    cerr << "\u001B[0m" << endl;
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

    void add_edge(int u, int v, ll cost = 0, ll cap = 1, bool directed = true) {
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
        ds.assign(V, INF);
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
                tc += f * ds[t];
            }
        }
    }

    pll min_cost_flow(int s, int t, ll mf = INF) {
        dinic(s, t, mf);
        return {tf, tc};
    }

    pair<vi, vi> min_cut(int s, int t) {
        dinic(s, t);
        pair<vi, vi> cut;
        forn (u, V) (ds[u] != -1 ? cut.x : cut.y).pb(u);
        return cut;
    }

    pair<ll, vector<tuple<int, int, ll>>> min_cost_flow_edges(int s, int t, ll mf = INF) {
        dinic(s, t, mf);
        vector<tuple<int, int, ll>> flows;
        forn (u, V) {
            for (int idx : AL[u]) {
                auto [v, cost, cap, flow] = EL[idx];
                if (flow > 0) flows.emplace_back(u, v, flow);
            }
        }
        return {tf, flows};
    }

    vector<pii> min_cut_edges(int s, int t) {
        dinic(s, t);
        vector<pii> cut_edges;
        forn (u, V) if (ds[u] != -1) {
            for (int idx : AL[u]) {
                auto [v, cost, cap, flow] = EL[idx];
                if (cap > 0 && ds[v] == -1) cut_edges.emplace_back(u, v);
            }
        }
        return cut_edges;
    }
};


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m, r; cin >> n >> m >> r;
    MCF mcf(n+m+2);
    int s = -2;
    int t = -1;
    forn(i, n) mcf.add_edge(s, i);
    forn(i, m) mcf.add_edge(n+i, t);
    forn(i, r) {
        int a, b, c; cin >> a >> b >> c;
        mcf.add_edge(a-1, n+b-1, -c);
    }
    auto [mf, mc] = mcf.min_cost_flow(s, t);
    print(n-mf, -mc);
}
