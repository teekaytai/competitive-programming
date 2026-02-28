#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef array<int, 3> a3i;
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
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define len(x) int(size(x))
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
    [[maybe_unused]] const char* sep = "";
    (((cout << sep << args), sep = " "), ...);
    cout << "\n";
}
template <typename It, typename = enable_if_t<is_base_of_v<input_iterator_tag, typename iterator_traits<It>::iterator_category>>>
inline void print(It b, It e) {
    for (auto it = b; it != e; ++it) cout << *it << " ";
    cout << "\n";
}
template <typename... Ts>
inline void printerr(const Ts&... args) {
    [[maybe_unused]] const char* sep = "";
    cerr << "\u001B[31m";
    (((cerr << sep << args), sep = " "), ...);
    cerr << "\u001B[0m" << endl;
}
template <typename It, typename = enable_if_t<is_base_of_v<input_iterator_tag, typename iterator_traits<It>::iterator_category>>>
inline void printerr(It b, It e) {
    cerr << "\u001B[31m{";
    if (b != e) {
        cerr << *b;
        for (auto it = next(b); it != e; ++it) cerr << ", " << *it;
    }
    cerr << "}\u001B[0m" << endl;
}

struct UF {
    vector<int> pars;
    vector<int> sizes;
    int num_sets;

    UF(int n) {
        pars.assign(n, -1);
        sizes.assign(n, 1);
        num_sets = n;
    }

    int find(int i) {
        return pars[i] < 0 ? i : (pars[i] = find(pars[i]));
    }

    bool onion(int i, int j) {
        int r1 = find(i);
        int r2 = find(j);
        if (r1 == r2) return false;
        if (sizes[r2] > sizes[r1]) swap(r1, r2);
        pars[r2] = r1;
        sizes[r1] += sizes[r2];
        num_sets -= 1;
        return true;
    }

    bool is_same_set(int i, int j) { return find(i) == find(j); }
    int set_size(int i) { return sizes[find(i)]; }
};

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;
const ll MOD = 998244353;

void solve() {
    int n, m; cin >> n >> m;
    UF uf(n);
    vpii e;
    forn(i, m) {
        int u, v; cin >> u >> v;
        --u; --v;
        e.eb(u, v);
    }
    reverse(all(e));
    vll pow2 = {1};
    forn(i, m) pow2.pb(pow2.back() * 2 % MOD);
    ll ans = 0;
    int i = m;
    int c = n;
    for (auto [u, v] : e) {
        if (c > 2) {
            c -= uf.onion(u, v);
            ans = (ans + pow2[i]) % MOD;
        } else if (uf.is_same_set(u, v)) {
            ans = (ans + pow2[i]) % MOD;
        }
        --i;
    }
    print(((pow2.back() * 2 - 2 - ans) % MOD + MOD) % MOD);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();
}
