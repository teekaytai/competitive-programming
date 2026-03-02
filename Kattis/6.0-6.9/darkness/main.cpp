#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forn1(i, n) for (int i = 1; i <= (n); ++i)
#define len(x) int(size(x))
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

void solve() {
    int b, h, n, m; cin >> b >> h >> n >> m;
    vector<string> g(n);
    vvb bs(n, vb(m));
    forn(i, n) cin >> g[i];
    MF mf((n - 2) * (m - 2) + 2);
    int s = -2;
    int t = -1;
    forn(i, n) {
        forn(j, m) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                bs[i][j] = true;
                continue;
            }
            double t = 0;
            forn(r, n) forn(c, m) {
                int dx = i - r;
                int dy = j - c;
                t += (double) (g[r][c] - '0') / (dx*dx + dy*dy + h*h);
            }
            bs[i][j] = t >= b;
            if (!bs[i][j]) {
                mf.add_edge(s, (i - 1) * (m - 2) + j - 1, MF::INF);
            }
        }
    }
    forn1(i, n - 2) forn1(j, m - 1) {
        int u = (i - 1) * (m - 2) + j - 1;
        int v = j == 1 ? t : u - 1;
        if (j == m - 1) u = t;
        int bt = bs[i][j] + bs[i][j - 1];
        mf.add_edge(u, v, bt == 0 ? MF::INF : bt == 1 ? 11 : 43, false);
    }
    forn1(i, n - 1) forn1(j, m - 2) {
        int u = (i - 1) * (m - 2) + j - 1;
        int v = i == 1 ? t : u - (m - 2);
        if (i == n - 1) u = t;
        int bt = bs[i][j] + bs[i - 1][j];
        mf.add_edge(u, v, bt == 0 ? MF::INF : bt == 1 ? 11 : 43, false);
    }
    cout << mf.max_flow(s, t) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();
}
