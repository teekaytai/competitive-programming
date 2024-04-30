#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
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
        if (u < 0) u += V;
        if (v < 0) v += V;
        if (u == v) return;
        AL[u].push_back(len(EL));
        EL.emplace_back(v, cap, 0);
        AL[v].push_back(len(EL));
        EL.emplace_back(u, directed ? 0 : cap, 0);
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

const int INF = 1e9;
const int MAXN = 3e5;
pii ps[10000];
int g[100][100];
int R[100][100];
int C[100][100];

void solve() {
    int H, W, P; cin >> H >> W >> P;
    forn(i, P) {
        int r, c; cin >> r >> c; --r, --c;
        ps[i] = make_pair(r, c);
    }
    int k; cin >> k;
    forn(i, k) {
        int r, c; cin >> r >> c; --r, --c;
        g[r][c] = 1;
    }
    int curr = 0;
    forn(r, H) {
        forn(c, W) {
            R[r][c] = curr;
            curr += g[r][c];
        }
        ++curr;
    }
    curr = 0;
    forn(c, W) {
        forn(r, H) {
            C[r][c] = curr;
            curr += g[r][c];
            g[r][c] = 0;
        }
        ++curr;
    }
    int Y = R[H-1][W-1]+1;
    int X = C[H-1][W-1]+1;
    int s = -2, t = -1;
    MF mf(X+Y+2);
    forn(i, Y) mf.add_edge(s, i);
    forn(i, X) mf.add_edge(Y+i, t);
    forn(i, P) {
        auto [r, c] = ps[i];
        mf.add_edge(R[r][c], Y+C[r][c]);
    }
    cout << mf.max_flow(s, t) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
