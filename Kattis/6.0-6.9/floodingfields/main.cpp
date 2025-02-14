#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define len(x) (int) (x).size()
#define eb emplace_back

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

array<pii, 5> DIRS = {{{0, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}}};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, k, h; cin >> n >> k >> h;
    int s = -1;
    int t = -2;
    MF mf(n * n * (h + 1) * 2 + 2);
    int O = n * n * (h + 1);
    vvi g(n, vi(n));
    forn(i, n) forn(j, n) {
        cin >> g[i][j];
        mf.add_edge(O + n*n*h+i*n+j, t);
    }
    forn(_, k) {
        int r, c; cin >> r >> c;
        mf.add_edge(s, O + r * n + c);
    }
    vi hs(h);
    forn(i, h) cin >> hs[i];
    forn(l, h) forn(i, n) forn(j, n) {
        mf.add_edge(n*n*(l+1)+i*n+j, O + n*n*(l+1)+i*n+j);
        for (auto [di, dj] : DIRS) {
            int i2 = i + di;
            int j2 = j + dj;
            if (0 <= i2 && i2 < n && 0 <= j2 && j2 < n && g[i2][j2] > hs[l])
                mf.add_edge(O + n*n*l+i*n+j, n*n*(l+1)+i2*n+j2);
        }
    }
    cout << mf.max_flow(s, t) << "\n";
}
