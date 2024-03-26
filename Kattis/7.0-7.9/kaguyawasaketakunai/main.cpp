#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define len(x) (int) x.size()
#define pb push_back

template <typename... Ts>
inline void print(const Ts&... args) {
    const char* sep = "";
    (((cout << sep << args), sep = " "), ...);
    cout << "\n";
}

struct MF {
    static const ll INF = 1e18;
    typedef tuple<int, ll, ll> edge;

    int V;
    vvi AL;
    vector<edge> EL;
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
        mf = 0;
        while (bfs(s, t)) {
            last.assign(V, 0);
            while (ll f = dfs(s, t)) {
                mf += f;
            }
        }
    }

    vector<pii> min_cut_edges(int s, int t) {
        dinic(s, t);
        vector<pii> cut_edges;
        forn (u, V) if (ds[u] != -1) {
            for (int idx : AL[u]) {
                auto [v, cap, flow] = EL[idx];
                if (ds[v] == -1 && cap > 0) cut_edges.emplace_back(u, v);
            }
        }
        return cut_edges;
    }
};

ll INF = 1e18;

vector<vector<pii>> g;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m, s, t; cin >> n >> m >> s >> t;
    g.assign(n+1, vector<pii>());
    forn (i, m) {
        int u, v, w; cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    MF mf(n+1);
    vll ds(n+1, INF);
    vvi pars(n+1);
    ds[s] = 0;
    pars[s].pb(s);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.emplace(0, s);
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > ds[u]) continue;
        for (int p : pars[u]) mf.add_edge(p, u);
        if (u == t) break;
        for (auto [v, w] : g[u]) {
            ll d2 = d + w;
            if (d2 > ds[v]) continue;
            if (d2 < ds[v]) {
                ds[v] = d2;
                pars[v].clear();
                pq.emplace(d2, v);
            }
            pars[v].pb(u);
        }
    }

    vector<pii> mc = mf.min_cut_edges(s, t);
    print(len(mc));
    for (auto [u, v] : mc) print(u, v, 1);
}
