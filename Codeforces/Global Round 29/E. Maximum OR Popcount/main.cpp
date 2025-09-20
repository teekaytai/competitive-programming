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
    int n, q; cin >> n >> q;
    int o = 0;
    vi a(n);
    vi cs(31, 0);
    forn(i, n) {
        cin >> a[i];
        o |= a[i];
        int m = a[i];
        while (m) {
            int b = m & -m;
            ++cs[__builtin_ctz(b)];
            m -= b;
        }
    }
    vector<set<pii>> pqs(31);
    forn (i, n) {
        int v = a[i];
        int m = 0;
        forn (j, 31) {
            int x = v & m;
            if (len(pqs[j]) < (31 - j)) {
                pqs[j].emplace(x, i);
            } else if (x > pqs[j].begin()->fi) {
                pqs[j].erase(pqs[j].begin());
                pqs[j].emplace(x, i);
            }
            m = m * 2 + 1;
        }
    }
    uset<int> used;
    vll need;
    forn (j, 31) if (cs[j] == 0) {
        ll t = 0;
        for (int k = j; k >= 0; --k) if (cs[k] == 0) {
            t += 1 << k;
            auto& pq = pqs[k];
            for (auto it = pq.rbegin(); it != pq.rend(); ++it) {
                auto [x, i] = *it;
                if (used.contains(i)) continue;
                used.insert(i);
                int m = a[i];
                while (m) {
                    int b = m & -m;
                    --cs[__builtin_ctz(b)];
                    m -= b;
                }
                t -= x;
                break;
            }
        }
        need.pb(t);
        for (int i : used) {
            int m = a[i];
            while (m) {
                int b = m & -m;
                ++cs[__builtin_ctz(b)];
                m -= b;
            }
        }
        used.clear();
    }
    forn(i, q) {
        int x; cin >> x;
        int ans = (int) (lower_bound(all(need), x + 1) - need.begin());
        print(ans + __builtin_popcount(o));
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
