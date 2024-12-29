#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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

map<int, int> c(vvi& g, int i) {
    map<int, int> m;
    for (int x : g[i]) ++m[x];
    return m;
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vvi g(n, vi(m, -1));
    forn(i, n) forn(j, m) {
        cin >> g[i][j];
    }
    map<int, int> c1 = c(g, 0);
    vll dp(k + 1, 0);
    ll d = 0;
    ll a = 0;
    ll t = 0;
    ll mx = 0;
    forn1(i, n - 1) {
        map<int, int> c2 = c(g, i);
        int x1 = c1[-1];
        int x2 = c2[-1];
        for (auto [k, v] : c2) if (k != -1) {
            dp[k] = max(d - a, dp[k]) + (ll) v * x1;
            cmax(mx, dp[k]);
            auto it = c1.find(k);
            if (it != c1.end()) t += (ll) v * it->second;
        }
        d = max(d + (ll) x1 * x2, mx + a);
        a += (ll) x1 * x2;
        for (auto [k, v] : c1) if (k != -1) {
            dp[k] = max(d - a, dp[k]) + (ll) v * x2;
            cmax(mx, dp[k]);
        }
        c1 = move(c2);
    }
    print(t + max(d, mx + a));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
