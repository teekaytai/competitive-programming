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

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;

void solve() {
    int n, m; cin >> n >> m;
    int mx = 0;
    vector<pii> a(n);
    forn(i, n) {
        cin >> a[i].se;
        mx = max(mx, a[i].se);
    }
    vi p(mx+1, INF);
    forn(i, n) {
        cin >> a[i].fi;
        a[i].fi = a[i].se - a[i].fi;
        p[a[i].se] = min(p[a[i].se], a[i].fi);
    }
    pii mn = *min_element(all(a));
    // printerr(p);
    forn1(i, mx) p[i] = min(p[i], p[i-1]);
    // printerr(p);
    vll dp(mx+1, 0);
    forn1(i, mx) {
        dp[i] = p[i] < INF ? dp[i-p[i]] + 2 : dp[i-1];
    }
    // printerr(dp);
    ll t = 0;
    forn(i, m) {
        int x; cin >> x;
        int d = (max(x - mx, 0) + mn.fi - 1) / mn.fi;
        x -= d * mn.fi;
        // printerr(x, d, a[0].fi);
        t += dp[x] + 2*d;
    }
    print(t);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    // int tc; cin >> tc;
    // while (tc--) {
    solve();
    // }
}
