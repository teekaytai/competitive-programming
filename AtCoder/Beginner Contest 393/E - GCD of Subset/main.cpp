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
    cerr << "\u001B[31m{";
    if (!v.empty()) cerr << v[0];
    forn1 (i, len(v) - 1) cerr << ", " << v[i];
    cerr << "}\u001B[0m" << endl;
}

vi primes;
vi ps;
void init() {
    int N = 1000002;
    ps.resize(N);
    iota(all(ps), 0);
    ps[0] = 1;
    ps[1] = 1;
    for (int i = 2; i < N; ++i) if (ps[i] == i) {
        primes.pb(i);
        for (int j = i * 2; j < N; j += i) if (ps[j] == j) {
            ps[j] = i;
        }
    }
}

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;
const int MOD = 998244353;

void solve() {
    int n, k; cin >> n >> k;
    vi a(n);
    umap<int, int> m;
    forn(i, n) {
        cin >> a[i];
        ++m[a[i]];
    }
    umap<int, int> cs;
    umap<int, vector<int>> fs;
    for (auto [te, c] : m) {
        int v = te;
        vector<int> f = {1};
        int p = 1;
        int r = 0;
        while (ps[v] != 1) {
            if (ps[v] == p) ++r;
            else {
                if (p != 1) rforn(i, len(f)) {
                    int pp = p;
                    forn (b, r) {
                        f.pb(f[i] * pp);
                        pp *= p;
                    }
                }
                p = ps[v], r = 1;
            }
            v /= ps[v];
        }
        if (p != 1) rforn(i, len(f)) {
            int pp = p;
            forn (b, r) {
                f.pb(f[i] * pp);
                pp *= p;
            }
        }
        for (int x : f) cs[x] += c;
        sort(rall(f));
        fs[te] = move(f);
    }
    for (auto& [v, c] : m) {
        // printerr(fs[v]);
        for (int x : fs[v]) if (cs[x] >= k) {
            c = x;
            break;
        }
    }
    for (int x : a) print(m[x]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    init();
    // int tc; cin >> tc;
    // while (tc--) {
    solve();
    // }
}
