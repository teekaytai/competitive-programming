#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define umap unordered_map
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define len(x) int(size(x))
#define eb emplace_back
#define fi first
#define se second

struct MF {
    static constexpr ll INF = 1e18;

    int V;
    vvi AL;
    vector<tuple<int, ll, ll>> EL;
    vi ds;
    vi last;

    int last_s, last_t;
    ll mf;

    MF(int _V) : V(_V) {
        AL.assign(V, vi());
        EL.clear();
        last_s = last_t = -1;
    }

    void add_edge(int u, int v, ll cap = 1, bool directed = true) {
        if (u < 0) u += V;
        if (v < 0) v += V;
        if (u == v) return;
        AL[u].push_back(len(EL));
        EL.eb(v, cap, 0);
        AL[v].push_back(len(EL));
        EL.eb(u, directed ? 0 : cap, 0);
        last_s = last_t = -1;
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
};

void solve() {
    int n, k, m; cin >> n >> k >> m;
    cin.ignore();
    umap<string, int> ma;
    MF mf(n + 2*k + m + 2);
    int s = -2;
    int t = -1;
    forn(i, n) {
        mf.add_edge(s, i);
        string line; getline(cin, line);
        stringstream ss(line);
        string s;
        while (ss >> s) {
            int j = ma.try_emplace(s, len(ma)).fi->se;
            mf.add_edge(i, n + j);
        }
    }
    forn(i, k) mf.add_edge(n + i, n + i + k);
    forn(i, m) {
        string line; getline(cin, line);
        stringstream ss(line);
        int c; ss >> c;
        mf.add_edge(-3 - i, t, c);
        string s;
        while (ss >> s) {
            int j = ma.try_emplace(s, len(ma)).fi->se;
            mf.add_edge(n + k + j, -3 - i);
        }
    }
    cout << mf.max_flow(s, t) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();
}
