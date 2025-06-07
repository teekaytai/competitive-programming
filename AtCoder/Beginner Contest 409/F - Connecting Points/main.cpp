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
const int MOD = 998244353;

vpii ps;
vector<t3i> temp;

int d(int i, int j) {
    return abs(ps[i].fi - ps[j].fi) + abs(ps[i].se - ps[j].se);
}

void solve() {
    int n, q; cin >> n >> q;
    ps.clear();
    UF uf(n + q);
    temp.reserve((n + q) * (n + q));
    priority_queue<t3i, vector<t3i>, greater<t3i>> pq {greater<t3i>(), move(temp)};
    forn(i, n) {
        int x, y; cin >> x >> y;
        ps.eb(x, y);
        forn (j, i) {
            pq.emplace(d(i, j), i, j);
        }
    }
    forn(_, q) {
        int t; cin >> t;
        if (t == 1) {
            int x, y; cin >> x >> y;
            ps.eb(x, y);
            forn (i, len(ps) - 1) {
                pq.emplace(d(i, len(ps) - 1), i, len(ps) - 1);
            }
        } else if (t == 3) {
            int u, v; cin >> u >> v; --u; --v;
            print(uf.is_same_set(u, v) ? "Yes" : "No");
        } else {
            while (!pq.empty() && uf.is_same_set(get<1>(pq.top()), get<2>(pq.top()))) {
                pq.pop();
            }
            if (pq.empty()) {
                print(-1);
                continue;
            }
            auto [mn, u, v] = pq.top();
            while (!pq.empty() && get<0>(pq.top()) == mn) {
                auto [_, u, v] = pq.top();
                pq.pop();
                uf.onion(u, v);
            }
            print(mn);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();
}
