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
    const char* sep = "";
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
    const char* sep = "";
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

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;
const ll MOD = 998244353;

void solve() {
    int n, m; cin >> n >> m;
    vi a(n);
    vvi g(m + 1);
    vi cs(m + 1, 0);
    vvi ps(n);
    forn(i, n) {
        cin >> a[i];
        ++cs[a[i]];
        g[a[i]].pb(i);
    }
    vb isp(m + 1, true);
    isp[0] = false;
    isp[1] = false;
    cs[1] = n;
    for (int i = 2; i <= m; ++i) {
        if (isp[i]) for (int k : g[i]) ps[k].pb(i);
        for (int j = i + i; j <= m; j += i) {
            isp[j] = false;
            cs[i] += cs[j];
            if (isp[i]) for (int k : g[j]) ps[k].pb(i);
        }
    }
    vi ds(n, 0);
    forn(i, n) {
        forn1 (j, (1 << len(ps[i])) - 1) {
            int x = 1;
            int m = j;
            while (m) {
                int b = LSB(m);
                m -= b;
                x *= ps[i][__builtin_ctz(b)];
            }
            ds[i] += (__builtin_popcount(j) % 2 ? 1 : -1) * cs[x];
        }
    }
    forn (i, n) ds[i] = n - ds[i] - (a[i] == 1);
    auto it = max_element(all(ds));
    if (*it == 0) {
        print(0);
        return;
    }
    int idx = (int) (it - ds.begin());
    pii mn = {INT_MAX, -1};
    forn (i, n) if (i != idx && gcd(a[i], a[idx]) == 1) {
        cmin(mn, {ds[i], i});
        --ds[i];
    }
    forn (i, n) if (i != mn.se && gcd(a[i], a[mn.se]) == 1) {
        --ds[i];
    }
    ds[idx] = 0;
    ds[mn.se] = 0;
    forn (i, n) if (ds[i] > 0) {
        forn (j, n) if (i != j && gcd(a[i], a[j]) == 1 && ds[j]) {
            print(idx+1, mn.se+1, i+1, j+1);
            return;
        }
    }
    print(0);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
