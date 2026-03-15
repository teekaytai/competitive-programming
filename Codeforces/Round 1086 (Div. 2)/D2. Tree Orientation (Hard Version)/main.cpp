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
const int MAXN = 8000;
const ll MOD = 998244353;

vector<bitset<MAXN>> bs;
int cs[MAXN];

void solve() {
    int n; cin >> n;
    bs.clear();
    bool can = true;
    forn(i, n) {
        string s; cin >> s;
        reverse(all(s));
        bs.eb(s);
        cs[i] = (int) bs[i].count();
        can &= bs[i][i];
    }
    if (!can) {
        print("No");
        return;
    }
    vi I(n);
    iota(all(I), 0);
    sort(all(I), [&](int i1, int i2) {
        return cs[i1] < cs[i2];
    });
    UF uf(n);
    vpii ans;
    forn(i, n) {
        int ii = I[i];
        bitset<MAXN> b = bs[ii];
        int c = cs[ii];
        rforn(j, i) {
            int jj = I[j];
            if (b[jj]) {
                if (((~b) & bs[jj]).any() || !uf.onion(ii, jj)) {
                    print("No");
                    return;
                }
                b ^= bs[jj];
                c -= cs[jj];
                ans.eb(ii, jj);
            }
        }
        if (c != 1 || len(ans) > n - 1) {
            print("No");
            return;
        }
    }
    if (len(ans) != n - 1) {
        print("No");
        return;
    }
    print("Yes");
    for (auto [u, v] : ans) {
        print(u + 1, v + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
