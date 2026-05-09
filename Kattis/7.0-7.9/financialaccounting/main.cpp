#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef array<int, 3> a3i;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
#define umap unordered_map
#define uset unordered_set
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forn1(i, n) for (int i = 1; i <= (n); ++i)
#define rforn(i, n) for (int i = (n) - 1; i >= 0; --i)
#define rforn1(i, n) for (int i = (n); i > 0; --i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define len(x) int(size(x))
#define LSB(x) ((x) & -(x))
inline int MSB(int x) { return x ? 1 << (31 - __builtin_clz(x)) : 0; }
inline ll MSB(ll x) { return x ? 1ll << (63 - __builtin_clzll(x)) : 0ll; }
template<class T> constexpr void cmin(T& a, T b) { a = min(a, b); }
template<class T> constexpr void cmax(T& a, T b) { a = max(a, b); }
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

template <typename... Ts>
inline void print(const Ts&... args) {
    [[maybe_unused]] const char* sep = "";
    (((cout << sep << args), sep = " "), ...);
    cout << "\n";
}
template <typename It, typename = enable_if_t<is_base_of_v<input_iterator_tag, typename iterator_traits<It>::iterator_category>>>
inline void print(It b, It e) {
    for (auto it = b; it != e; ++it) cout << *it << " ";
    cout << "\n";
}
template <typename... Ts>
inline void printerr(const Ts&... args) {
    [[maybe_unused]] const char* sep = "";
    cerr << "\u001B[31m";
    (((cerr << sep << args), sep = " "), ...);
    cerr << "\u001B[0m" << endl;
}
template <typename It, typename = enable_if_t<is_base_of_v<input_iterator_tag, typename iterator_traits<It>::iterator_category>>>
inline void printerr(It b, It e) {
    cerr << "\u001B[31m{";
    if (b != e) {
        cerr << *b;
        for (auto it = next(b); it != e; ++it) cerr << ", " << *it;
    }
    cerr << "}\u001B[0m" << endl;
}

struct MF {
    static constexpr ll INF = 1e18;

    int V;
    vvi AL;
    vector<tuple<int, ll, ll>> EL;
    vi ds;
    vi last;

    ll mf = 0;

    MF(int _V) : V(_V) {
        AL.assign(V, vi());
        EL.clear();
    }

    void add_edge(int u, int v, ll cap = 1, bool directed = true) {
        if (u < 0) u += V;
        if (v < 0) v += V;
        if (u == v) return;
        AL[u].push_back(len(EL));
        EL.eb(v, cap, 0);
        AL[v].push_back(len(EL));
        EL.eb(u, directed ? 0 : cap, 0);
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

    pair<vi, vi> min_cut(int s, int t) {
        dinic(s, t);
        pair<vi, vi> cut;
        forn (u, V) (ds[u] != -1 ? cut.fi : cut.se).pb(u);
        return cut;
    }

    vector<tuple<int, int, ll>> max_flow_edges(int s, int t) {
        dinic(s, t);
        vector<tuple<int, int, ll>> flows;
        forn (u, V) {
            for (int idx : AL[u]) {
                auto [v, cap, flow] = EL[idx];
                if (flow > 0) flows.eb(u, v, flow);
            }
        }
        return flows;
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
const ll MOD = 998244353;

void solve() {
    int n, m; cin >> n >> m;
    vi p(n);
    vi q(n);
    vll psp = {0};
    vll psq = {0};
    forn(i, n) {
        cin >> p[i];
        psp.pb(psp.back() + p[i]);
    }
    ll ans = 0;
    forn(i, n) {
        cin >> q[i];
        psq.pb(psq.back() + q[i]);
        ans += (ll) p[i] * q[i];
    }
    MF mf(102);
    int s = -2;
    int t = -1;
    vpii ran(m);
    vi xs(m);
    forn(i, m) {
        int l, r, x; cin >> l >> r >> x;
        --l; --r;
        ran[i] = {l, r};
        xs[i] = x;
        ll sp = psp[r + 1] - psp[l];
        ll sq = psq[r + 1] - psq[l];
        mf.add_edge(s, i, (ll) x * sp);
        mf.add_edge(i, t, (ll) x * sq);
        forn(j, i) {
            if (ran[j].fi <= r && l <= ran[j].se) {
                mf.add_edge(i, j, ((ll)x * xs[j]) * (min(r, ran[j].se) - max(l, ran[j].fi) + 1), false);
            }
        }
    }
    print(ans + mf.max_flow(s, t));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    // int tc; cin >> tc;
    // while (tc--) {
    solve();
    // }
}
