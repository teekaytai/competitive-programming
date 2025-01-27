#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> t3i;
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
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define len(x) (int) (x).size()
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

vi W;
map<int, set<int>> mp;
pii ans;
vvi g;
void dfs(int u, int p = -1) {
    auto it = mp.find(W[u]);
    // if (it != mp.begin()) printerr("hmm", u, len(prev(it)->se));
    if (it != mp.begin() && !prev(it)->se.empty()) {
        // printerr(u, W[u], it->fi, prev(it)->fi, "boop");
        // printerr(vi(all(prev(it)->se)));
        ans = max(ans, {W[u], *(prev(it)->se.begin())});
    }
    mp[W[u]].erase(u);
    for (int v : g[u]) if (v != p) {
        dfs(v, u);
    }
    mp[W[u]].insert(u);
}

void solve() {
    int n; cin >> n;
    ans = {-1, -1};
    W.assign(n, -1);
    mp.clear();
    forn (i, n) {
        cin >> W[i];
        // printerr(vi(all(mp[W[i]])));
        mp[W[i]].insert(i);
        // printerr()
        // printerr("boop", i, W[i]);
        // printerr(vi(all(mp[W[i]])));
    }
    // for (auto [w, v] : mp) {
    //     printerr(w);
    //     printerr(vi(all(v)));
    // }
    g.assign(n, vi());
    forn (i, n - 1) {
        int u, v; cin >> u >> v;
        --u; --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0);
    print(ans.se + 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
