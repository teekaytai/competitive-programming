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

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vi a;
    a.reserve(n);
    ll t = 0;
    forn(_, n) {
        int x; cin >> x;
        a.pb(x);
        t += x;
    }
    vi bb(m);
    forn(i, m) cin >> bb[i];
    vi bbb;
    bbb.reserve(1 << m);
    bbb.pb((1 << 30) - 1);
    vvi b(m, vi());
    forn1(i, (1 << m) - 1) {
        int lsb = LSB(i);
        bbb.pb(bbb[i - lsb] & bb[__builtin_ctz(lsb)]);
        b[__builtin_popcount(i) - 1].pb(bbb.back());
    }
    vi s;
    s.reserve(n*m);
    for (int x : a) {
        int p = x;
        int mn = x;
        forn(j, m) {
            for (int y : b[j]) cmin(mn, x & y);
            if (mn >= p) break;
            s.pb(mn - p);
            p = mn;
        }
    }
    if (k < len(s) && k > 0) nth_element(s.begin(), s.begin() + (k - 1), s.end());
    forn (i, min(k, len(s))) t += s[i];
    print(t);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
