#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<bool> vb;
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

int n, m;
vvi A, B;
vector<vb> in;
vector<vector<vb>> seen;
bool dfs(int r, int c, int b, bool o) {
    if (in[r][c]) return false;
    int x = __builtin_ctz(b);
    if (seen[r][c][x]) {
        return true;
    }
    seen[r][c][x] = true;
    in[r][c] = true;
    if (o) {
        forn (i, n) {
            if ((B[i][c] & b) == 0) {
                if (!dfs(i, c, b, !o)) return false;
            }
            seen[i][c][x] = true;
        }
    } else {
        forn (j, m) {
            if ((B[r][j] & b) > 0) {
                if (!dfs(r, j, b, !o)) return false;
            }
            seen[r][j][x] = true;
        }
    }
    in[r][c] = false;
    return true;
}

void solve() {
    cin >> n >> m;
    A.assign(n, vi(m, 0));
    B.assign(n, vi(m, 0));
    seen.assign(n, vector<vb>(m, vb(32, false)));
    in.assign(n, vb(m, false));
    forn(i, n) forn(j, m) cin >> A[i][j];
    forn(i, n) forn(j, m) cin >> B[i][j];
    forn(i, n) forn(j, m) {
        int x = A[i][j];
        int y = B[i][j];
        int mask = x ^ y;
        while (mask) {
            int b = LSB(mask);
            if (!seen[i][j][__builtin_ctz(b)] && !dfs(i, j, b, (y & b) > 0)) {
                print("No");
                return;
            }
            mask -= b;
        }
    }
    print("Yes");
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
