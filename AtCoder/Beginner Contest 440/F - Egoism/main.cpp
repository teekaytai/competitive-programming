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

struct FT {
    vector<ll> tree;

    FT(int n) { tree.assign(n + 1, 0); }

    FT(const vector<ll>& a) { build(a); }

    void build(const vector<ll>& a) {
        int n = len(a);
        tree.assign(n + 1, 0);
        forn1(i, n) {
            tree[i] += a[i - 1];
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
const int MAXN = 1e6 + 5;
const ll MOD = 998244353;

void solve() {
    int n, q; cin >> n >> q;
    vi ms(n);
    vi ts(n);
    int t = 0;
    ll s = 0;
    FT ft(MAXN);
    FT ft2(MAXN);
    FT ft3(MAXN);
    forn(i, n) {
        cin >> ms[i] >> ts[i];
        s += ms[i];
        t += ts[i] == 1;
        ft.update(ms[i], 1);
        ft2.update(ms[i], ms[i]);
        if (ts[i] == 2) {
            ft3.update(ms[i], 1);
        }
    }
    forn(_, q) {
        int w, x, y; cin >> w >> x >> y;
        --w;
        s -= ms[w];
        ft.update(ms[w], -1);
        ft2.update(ms[w], -ms[w]);
        if (ts[w] == 2) {
            ft3.update(ms[w], -1);
        }
        ms[w] = x;
        s += ms[w];
        ft.update(ms[w], 1);
        ft2.update(ms[w], ms[w]);
        t -= ts[w] == 1;
        ts[w] = y;
        t += ts[w] == 1;
        if (ts[w] == 2) {
            ft3.update(ms[w], 1);
        }
        if (t == n) {
            print(s);
        } else {
            int i = ft.lower_bound(t + 1);
            if (ft3.query(i, MAXN - 1) == n - t && ft.query(i, MAXN - 1) == n - t) {
                print(s + ft2.query(i, MAXN - 1) - i + (t == 0 ? 0 : ft.lower_bound(t)));
            } else {
                print(s + ft2.query(i + 1, MAXN - 1) + i * (n - t - ft.query(i + 1, MAXN - 1)));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();
}
