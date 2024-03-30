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
#define x first
#define y second

template <typename... Ts>
inline void print(const Ts&... args) {
    const char* sep = "";
    (((cout << sep << args), sep = " "), ...);
    cout << "\n";
}
template <typename... Ts>
inline void printerr(const Ts&... args) {
    const char* sep = "";
    cerr << "\u001B[31m";
    (((cerr << sep << args), sep = " "), ...);
    cerr << "\u001B[0m" << endl;
}

const double EPS = 1e-8;
const int INF = 1e9;
const int MAXN = 1e3;

int a[MAXN][MAXN];
vi dp[MAXN];
int n, k;
void f(vi& res, int i) {
    priority_queue<tuple<int, int, int>> pq;
    pq.emplace(a[i+1][n-1], i, 0);
    for (int j = i+1; j < n; ++j) {
        pq.emplace((j > i+1 ? a[i+1][j-1] : 0) + dp[j][0], j, 0);
    }
    forn(_, k) {
        if (pq.empty()) break;
        auto [s, j, k] = pq.top(); pq.pop();
        res.pb(s);
        if (j > i && ++k < len(dp[j])) {
            pq.emplace((j > i+1 ? a[i+1][j-1] : 0) + dp[j][k], j, k);
        }
    }
}

void solve() {
    cin >> n >> k;
    forn(i, n) forn(j, n-i) {
        cin >> a[i][i+j];
    }
    vi res = {0};
    rforn(i, n) {
        dp[i] = res;
        res = vi();
        f(res, i-1);
    }
    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
