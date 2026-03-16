#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define all(x) begin(x), end(x)
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
    ll mf = 0;

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
    int n, m, k; cin >> n >> m >> k;
    vector<vpii> g(n);
    vi ps(n);
    MF mf((1 << k) + k + 2);
    int s = -2;
    int t = -1;
    forn(i, 1 << k) mf.add_edge(s, i);
    forn(i, 1 << k) {
        int ma = i;
        while (ma) {
            int b = ma & -ma;
            ma -= b;
            mf.add_edge(i, (1 << k) + __builtin_ctz(b), MF::INF);
        }
    }
    ll T = 0;
    forn(i, n) {
        cin >> ps[i];
        T += ps[i];
    }
    forn(i, m) {
        int u, v, w; cin >> u >> v >> w; --u; --v;
        g[u].eb(v, w);
        g[v].eb(u, w);
    }
    vector<tuple<ll, int, int>> E;
    vll ds(n);
    forn(i, k) {
        int x, c; cin >> x >> c; --x;
        mf.add_edge((1 << k) + i, t, c);
        fill(all(ds), LLONG_MAX);
        ds[x] = 0;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
        pq.emplace(0, x);
        int left = n;
        while (left > 0) {
            auto [d, u] = pq.top();
            pq.pop();
            if (ds[u] != d) continue;
            E.eb(d, u, i);
            --left;
            for (auto [v, w] : g[u]) {
                ll d2 = d + w;
                if (d2 < ds[v]) {
                    ds[v] = d2;
                    pq.emplace(d2, v);
                }
            }
        }
    }
    sort(all(E));
    vi cs(n, 0);
    vll ts(1 << k, 0);
    ll lo = 0;
    ll hi = get<0>(E.back());
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        fill(all(cs), 0);
        fill(all(ts), 0);
        for (auto [d, u, i] : E) {
            if (d > mid) break;
            cs[u] |= 1 << i;
        }
        forn(u, n) ts[cs[u]] += ps[u];
        forn(i, 1 << k) get<1>(mf.EL[2 * i]) = ts[i];
        if (mf.max_flow(s, t) == T) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
