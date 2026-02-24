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

template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    return os << "(" << p.fi << ", " << p.se << ")";
}

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

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;
const ll MOD = 998244353;

void solve() {
    int n, q; cin >> n >> q;
    vector<set<int>> is(n + 1);
    vi a(n);
    forn(i, n) {
        cin >> a[i];
        is[a[i]].insert(i);
    }
    map<int, map<int, int>> ma;
    map<int, ll> ma2;
    auto f = [&](int d, int i) {
        auto& m = ma[d];
        if (m.empty()) {
            m.emplace(i, 1);
            ma2[d] = 1;
            return;
        }
        auto it = m.lower_bound(i);
        if (it != m.begin()) {
            auto p = prev(it);
            if (p->fi + p->se == i) {
                ++p->se;
                ma2[d] += p->se;
                if (it != m.end() && it->fi == p->fi + p->se) {
                    ma2[d] += (ll) p->se * it->se;
                    p->se += it->se;
                    m.erase(it);
                }
                return;
            }
        }
        if (it != m.end() && it->fi == i + 1) {
            m.emplace(i, it->se + 1);
            ma2[d] += it->se + 1;
            m.erase(it);
            return;
        }
        m.emplace(i, 1);
        ++ma2[d];
    };
    auto g = [&](int d, int i) {
        auto& m = ma[d];
        auto temp = m.upper_bound(i);
        assert(!m.empty() && temp != m.begin());
        auto it = prev(temp);
        if (it->se == 1) {
            assert(it->fi == i);
            ma2[d] -= 1;
            m.erase(it);
            return;
        }
        if (it->fi + it->se - 1 == i) {
            ma2[d] -= it->se;
            --it->se;
            return;
        }
        int k = i - it->fi;
        int k2 = it->se - k - 1;
        it->se = k;
        m.emplace(i + 1, k2);
        if (k == 0) m.erase(it);
        ma2[d] -= (ll) (k + 1) * k2 + k + 1;
    };
    forn1(i, n) if (len(is[i]) > 1) {
        int j = *is[i].begin();
        int d = *is[i].rbegin() - j;
        f(d, j);
    }
    // for (auto& [x, m] : ma) {
    //     cerr << x << " ";
    //     printerr(all(m));
    // }
    // printerr(all(ma2));
    forn(_, q) {
        int i, x; cin >> i >> x; --i;
        int p = a[i];
        if (len(is[p]) > 1) {
            int j = *is[p].begin();
            int d = *is[p].rbegin() - j;
            g(d, j);
        }
        is[p].erase(i);
        if (len(is[p]) > 1) {
            int j = *is[p].begin();
            int d = *is[p].rbegin() - j;
            f(d, j);
        }

        if (len(is[x]) > 1) {
            int j = *is[x].begin();
            int d = *is[x].rbegin() - j;
            g(d, j);
        }
        is[x].insert(i);
        if (len(is[x]) > 1) {
            int j = *is[x].begin();
            int d = *is[x].rbegin() - j;
            f(d, j);
        }
        a[i] = x;
        while (!ma2.empty() && ma2.rbegin()->se == 0) {
            ma2.erase(prev(ma2.end()));
        }
        // for (auto& [x, m] : ma) {
        //     cerr << x << " ";
        //     printerr(all(m));
        // }
        // printerr(all(ma2));
        if (ma2.empty()) print(0, 0);
        else {
            auto [d, c] = *ma2.rbegin();
            print(d, c);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
