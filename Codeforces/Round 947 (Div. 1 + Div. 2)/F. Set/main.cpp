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

int n;
vvi a;
vi ans;

void dfs(int i, int v) {
    if (i == 0) {
        if (a[i][0]) ans.pb(v);
        return;
    }
    int b = 1 << (i-1);
    if (a[i][b] & 1) {
        forn (j, b) a[i-1][j] = a[i][j] & a[i][b+j];
        dfs(i-1, v);
    }
    if (a[i][b] & 2) {
        forn (j, b) a[i-1][j] = a[i][j] & a[i][b+j]>>1;
        dfs(i-1, v+b);
    }
}

void solve() {
    cin >> n;
    a.resize(n+1);
    forn(i, n+1) a[i].resize(1<<i);
    a[n][0] = 1;
    forn1(i, (1<<n)-1) cin >> a[n][i];
    dfs(n, 0);
    print(len(ans));
    for (int x : ans) print(x);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();
}
