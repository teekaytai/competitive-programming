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
    for (auto x : v) cerr << x << ", ";
    cerr << "\u001B[0m}" << endl;
}

struct FT {
    vector<ll> tree;

    // FT(int n) { tree.assign(n + 1, 0); }

    FT(int n) { build(n); }

    void build(int n) {
        tree.assign(n + 1, 0);
        forn1(i, n) {
            tree[i] += 1;
            if (i + LSB(i) <= n) {
                tree[i + LSB(i)] += tree[i];
            }
        }
    }

    ll query(int k) {
        ll t = 0;
        for (int i = min(k + 1, len(tree) - 1); i > 0; i -= LSB(i)) {
            t += tree[i];
        }
        return t;
    }

    ll query(int lo, int hi) {
        return query(hi) - query(lo - 1);
    }

    void update(int k, ll d) {
        assert(k >= 0 && k < len(tree) - 1);
        for (int i = k + 1; i < len(tree); i += LSB(i)) {
            tree[i] += d;
        }
    }

    // Finds minimum i such that sum of [0, i] >= sum, or n if sum of [0, n-1] < sum, or -1 if sum <= 0
    int lower_bound(ll sum) {
        if (sum <= 0) return -1;
        int i = 0;
        for (int b = MSB(len(tree)); b > 0; b /= 2) {
            if (i + b < len(tree) && sum > tree[i + b]) {
                i += b;
                sum -= tree[i];
            }
        }
        return i;
    }
};

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;

void solve() {
    int n; cin >> n;
    vi a(n);
    forn(i, n) cin >> a[i];
    FT ft(n);
    vi ans(n);
    rforn(i, n) {
        int x = a[i];
        int j = ft.lower_bound(x);
        ans[j] = i + 1;
        ft.update(j, -1);
    }
    print(ans);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    // int tc; cin >> tc;
    // while (tc--) {
        solve();
    // }
}
