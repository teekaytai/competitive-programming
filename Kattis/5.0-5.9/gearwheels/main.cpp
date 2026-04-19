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
#define eb emplace_back
#define fi first
#define se second

template <typename... Ts>
inline void print(const Ts&... args) {
    const char* sep = "";
    (((cout << sep << args), sep = " "), ...);
    cout << "\n";
}
template <typename T>
inline void print(const vector<T>& v) {
    for (auto x : v) cout << x << " ";
    cout << "\n";
}
template <typename... Ts>
inline void printerr(const Ts&... args) {
    const char* sep = "";
    cerr << "\u001B[31m";
    (((cerr << sep << args), sep = " "), ...);
    cerr << "\u001B[0m" << endl;
}
template <typename T>
inline void printerr(const vector<T>& v) {
    cerr << "\u001B[31m";
    for (auto x : v) cerr << x << " ";
    cerr << "\u001B[0m" << endl;
}

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

    pair<vi, vi> min_cut(int s, int t) {
        dinic(s, t);
        pair<vi, vi> cut;
        forn (u, V) (ds[u] != -1 ? cut.fi : cut.se).pb(u);
        return cut;
    }

    vector<pii> max_flow_edges(int s, int t) {
        dinic(s, t);
        s += V;
        t += V;
        vector<pii> edges;
        function<void(int)> dfs = [&](int u) {
            for (int idx : AL[u]) {
                auto [v, cap, flow] = EL[idx];
                if (flow > 0) {
                    edges.eb(u, v);
                    dfs(v);
                }
            }
        };
        dfs(s);
        return edges;
    }

    vector<pii> min_cut_edges(int s, int t) {
        dinic(s, t);
        vector<pii> cut_edges;
        forn (u, V) if (ds[u] != -1) {
            for (int idx : AL[u]) {
                auto [v, cap, flow] = EL[idx];
                if (cap > 0 && ds[v] == -1) cut_edges.eb(u, v);
            }
        }
        return cut_edges;
    }
};

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vll a(n);
    forn(i, n) cin >> a[i];
    vi dp(n, 1);
    MF mf(2*n+2);
    int s = -2;
    int t = -1;
    int mx = 0;
    forn(i, n) {
        mf.add_edge(2*i, 2*i+1);
        forn(j, i) {
            if (a[i] == a[j] || a[i] < a[j] && a[j] / a[i] * a[i] == a[j] || a[j] < a[i] && a[i] / a[j] * a[j] == a[i]) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        if (dp[i] == 1) mf.add_edge(s, 2*i);
        else forn(j, i) {
            if (a[i] == a[j] || a[i] < a[j] && a[j] / a[i] * a[i] == a[j] || a[j] < a[i] && a[i] / a[j] * a[j] == a[i]) {
                if (dp[i] == dp[j]+1) mf.add_edge(2*j+1, 2*i);
            }
        }
        mx = max(mx, dp[i]);
    }
    forn(i, n) if (dp[i] == mx) mf.add_edge(2*i+1, t);
    auto v = mf.max_flow_edges(s, t);
    print(mx, mf.mf);
    int l = 2*mx+1;
    forn(i, mf.mf) {
        forn(j, mx) {
            cout << v[i*l+2*j].se/2+1 << " ";
        }
        cout << "\n";
    }
}
