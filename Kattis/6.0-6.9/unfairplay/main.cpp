#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define len(x) int(size(x))
#define pb push_back
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

void solve(int n) {
    int m; cin >> m;
    vi a(n);
    forn(i, n) cin >> a[i];
    MF mf(n + m + 2);
    int s = -2;
    int t = -1;
    vi ans(m);
    vi qs;
    forn(i, m) {
        int u, v; cin >> u >> v; --u, --v;
        if (u == n - 1) {
            a[u] += 2;
            ans[i] = 0;
        } else if (v == n - 1) {
            a[v] += 2;
            ans[i] = 2;
        } else {
            mf.add_edge(n + i, v, 2);
            mf.add_edge(n + i, u, 2);
            mf.add_edge(s, n + i, 2);
            qs.pb(i);
        }
    }
    forn(i, n - 1) {
        int c = a[n - 1] - a[i] - 1;
        if (c < 0) {
            cout << "NO\n";
            return;
        }
        mf.add_edge(i, t, c);
    }
    if (mf.max_flow(s, t) < len(qs) * 2) {
        cout << "NO\n";
        return;
    }
    forn (i, len(qs)) {
        ans[qs[i]] = (int) get<2>(mf.EL[6 * i]);
    }
    for (int x : ans) cout << x << " ";
    cout <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    while (true) {
        cin >> n;
        if (n == -1) break;
        solve(n);
    }
}
