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
const int MAXN = 1e5+1;

int a[MAXN];
int x[MAXN];
int p[32][MAXN];

void solve() {
    int n; cin >> n;
    x[0] = 0;
    forn(i, n) {
        cin >> a[i];
        x[i+1] = x[i] ^ a[i];
    }
    int b = 1;
    forn(i, 32) {
        forn(j, n) p[i][j+1] = p[i][j] + ((x[j+1] & b) > 0);
        b <<= 1;
    }
    // printerr(vi(a, a+n));
    // printerr(vi(x, x+n+1));
    ll t = 0;
    forn(i, n) {
        int b = MSB(a[i]);
        int j = __builtin_ctz(b);
        // printerr(vi(p[j], p[j] + n+1));
        int l1 = p[j][i]; int l0 = i+1-l1;
        if (x[i] & b) swap(l0, l1);
        int r1 = p[j][n] - p[j][i]; int r0 = n - i - r1;
        if (x[i+1] & b) swap(r0, r1);
        // printerr(l0, l1, r0, r1);
        t += (ll)l1 * r0 + (ll)l0 * r1;
    }
    print(t);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
