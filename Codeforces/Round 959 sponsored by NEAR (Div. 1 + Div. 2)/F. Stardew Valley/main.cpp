#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
#define umap unordered_map
#define uset unordered_set
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forn1(i, n) for (int i = 1; i <= (n); ++i)
#define rforn(i, n) for (int i = (n) - 1; i >= 0; --i)
#define rforn1(i, n) for (int i = (n); i > 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define len(x) (int) (x).size()
#define LSB(x) ((x) & -(x))
inline int MSB(int x) { return x ? 1 << (31 - __builtin_clz(x)) : 0; }
inline ll MSB(ll x) { return x ? 1ll << (63 - __builtin_clzll(x)) : 0ll; }
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

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;

void solve() {
    int n, m; cin >> n >> m;
    int M = m;
    vvi g(n);
    vvi g2(n);
    vi edges(m);
    vi deg(n);
    vector<bool> del(m, false);
    forn(i, m) {
        int u, v, c; cin >> u >> v >> c;
        --u; --v;
        edges[i] = u ^ v;
        ++deg[u];
        ++deg[v];
        g[u].pb(i);
        g[v].pb(i);
        if (c == 0) {
            g2[u].pb(i);
            g2[v].pb(i);
        }
    }
    vector<bool> seen(n, false);
    auto dfs = [&](auto dfs, int u) -> bool {
        for (int id : g2[u]) {
            int v = edges[id] ^ u;
            if (seen[v]) continue;
            seen[v] = true;
            if (dfs(dfs, v)) {
                del[id] = true;
                --M;
                --deg[u]; --deg[v];
            }
        }
        return deg[u] % 2 != 0;
    };
    forn(i, n) if (!seen[i]) {
        seen[i] = true;
        if (dfs(dfs, i)) {
            print("NO");
            return;
        }
    }
    print("YES");
    print(M);
    stack<int> st({0});
    while (!st.empty()) {
        int u = st.top();
        while (!g[u].empty() && del[g[u].back()]) g[u].pop_back();
        if (g[u].empty()) {
            cout << u + 1 << " ";
            st.pop();
            continue;
        }
        int id = g[u].back();
        g[u].pop_back();
        del[id] = true;
        int v = edges[id] ^ u;
        st.push(v);
    }
    print();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
