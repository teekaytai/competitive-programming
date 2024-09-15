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
    int l, n, m; cin >> l >> n >> m;
    vi a(l);
    forn(i, l) cin >> a[i], --a[i];
    vvi g(n, vi(m));
    vvi rm(n, vi(7, -1));
    vvi cm(m, vi(7, -1));
    forn (r, n) {
        forn (c, m) {
            cin >> g[r][c];
            --g[r][c];
            rm[r][g[r][c]] = c;
            cm[c][g[r][c]] = r;
        }
    }
    // for (auto& r : rm) printerr(r);
    // for (auto& c : cm) printerr(c);
    map<tuple<int, int, int>, bool> dp;
    auto f = [&](auto f, int r, int c, int i) {
        if (i == len(a)) {
            dp[{r, c, i}] = false;
            return false;
        }
        auto it = dp.find({r, c, i});
        if (it != dp.end()) {
            return it->se;
        }
        int v = a[i];
        for (int R = r + 1; R < n; ++R) {
            int C = rm[R][v];
            if (C == -1 || C <= c || cm[C][v] > R) continue;
            if (!f(f, R, C, i + 1)) {
                dp[{r, c, i}] = true;
                return true;
            }
        }
        dp[{r, c, i}] = false;
        return false;
    };
    print(f(f, -1, -1, 0) ? 'T' : 'N');
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
