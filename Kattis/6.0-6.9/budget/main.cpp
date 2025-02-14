#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define len(x) (int) (x).size()
template<class T> constexpr void cmin(T& a, T b) { a = min(a, b); }
template<class T> constexpr void cmax(T& a, T b) { a = max(a, b); }
#define pb push_back
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

struct MFD {
    int V, S, T;
    MF mf;
    ll total_dem = 0;
    vll dems;

    // V includes s and t, but not the new S and T
    MFD(int _V, int s, int t) : V(_V), S(_V), T(_V + 1), mf(_V + 2) {
        forn (v, V) {
            mf.add_edge(S, v, 0);
            mf.add_edge(v, T, 0);
        }
        if (s < 0) s += V;
        if (t < 0) t += V;
        assert(s != t);
        mf.add_edge(t, s, MF::INF);
    }

    void add_edge(int u, int v, ll cap = 1, ll dem = 0) {
        assert(cap >= dem);
        if (u < 0) u += V;
        if (v < 0) v += V;
        if (u == v) return;
        mf.add_edge(u, v, cap - dem);
        if (dem > 0) {
            get<1>(mf.EL[4 * v]) += dem; // increase cap of edge (S, v)
            get<1>(mf.EL[4 * u + 2]) += dem; // increase cap of edge (u, T)
        }
        total_dem += dem;
        dems.pb(dem);
    }

    bool has_valid_flow() { return mf.max_flow(S, T) == total_dem; }

    pair<bool, vector<tuple<int, int, ll>>> valid_flow_edges() {
        if (mf.max_flow(S, T) < total_dem) return {false, {}};
        vector<tuple<int, int, ll>> flows;
        int special_edge_count = 2 * (2 * V + 1);
        forn (u, V) {
            for (int idx : mf.AL[u]) if (idx >= special_edge_count && idx % 2 == 0) {
                auto [v, cap, flow] = mf.EL[idx];
                flow += dems[(idx - special_edge_count) / 2];
                if (flow > 0) flows.eb(u, v, flow);
            }
        }
        return {true, flows};
    }
};

void solve() {
    int n, m; cin >> n >> m;
    int s = -1; int t = -2;
    MFD mfd(n + m + 2, s, t);
    forn(r, n) {
        ll x; cin >> x;
        mfd.add_edge(s, r, x, x);
    }
    forn(c, m) {
        ll x; cin >> x;
        mfd.add_edge(n + c, t, x, x);
    }
    int k; cin >> k;
    vector<vll> mxs(n, vll(m, MF::INF));
    vector<vll> mns(n, vll(m, 0));
    forn(_, k) {
        int r, c; cin >> r >> c;
        char o; cin >> o;
        ll x; cin >> x;
        for (int i = r ? r - 1 : 0; i < (r ? r : n); ++i) {
            for (int j = c ? c - 1 : 0; j < (c ? c : m); ++j) {
                if (o == '<') cmin(mxs[i][j], x - 1);
                else if (o == '>') cmax(mns[i][j], x + 1);
                else cmin(mxs[i][j], x), cmax(mns[i][j], x);
            }
        }
    }
    forn(i, n) forn(j, m) {
        ll mn = mns[i][j];
        ll mx = mxs[i][j];
        if (mn > mx) {
            cout << "IMPOSSIBLE\n\n";
            return;
        }
        mfd.add_edge(i, n + j, mx, mn);
    }
    auto [can, edges] = mfd.valid_flow_edges();
    if (!can) cout << "IMPOSSIBLE\n\n";
    else {
        vector<vll> ans(n, vll(m, 0));
        for (auto [u, v, f] : edges) if (u < n) {
            ans[u][v - n] = f;
        }
        for (auto& row : ans) {
            for (ll x : row) cout << x << " ";
            cout << "\n";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
