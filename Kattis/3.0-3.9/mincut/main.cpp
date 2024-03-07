#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define len(x) (int) x.size()
#define pb push_back
#define x first
#define y second

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

    void add_edge(int u, int v, ll cap, bool directed = true) {
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

    pair<vi, vi> min_cut(int s, int t) {
        dinic(s, t);
        pair<vi, vi> cut;
        forn (u, V) (ds[u] != -1 ? cut.x : cut.y).pb(u);
        return cut;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m, s, t;
    cin >> n >> m >> s >> t;
    MF mf(n);
    forn (i, m) {
        int u, v, c; cin >> u >> v >> c;
        mf.add_edge(u, v, c);
    }

    vi source_cut = mf.min_cut(s, t).x;
    print(len(source_cut));
    for (int v : source_cut) print(v);
}
