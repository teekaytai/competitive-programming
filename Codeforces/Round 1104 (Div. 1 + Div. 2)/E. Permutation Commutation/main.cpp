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

const ll MOD = 998244353;

void solve() {
    int n; cin >> n;
    vi a(n), b(n);
    vi cs(n, -1);
    vi ms(n, -1);
    set<pii> s;
    forn(i, n) {
        cin >> a[i];
        --a[i];
    }
    forn(i, n) if (cs[i] == -1) {
        int l = 1;
        int x = a[i];
        int mn = i;
        while (x != i) {
            cmin(mn, x);
            x = a[x];
            ++l;
        }
        cs[i] = l;
        ms[i] = mn;
        s.emplace(l, mn);
        x = a[i];
        while (x != i) {
            cs[x] = l;
            ms[x] = mn;
            x = a[x];
        }
    }
    forn(i, n) {
        cin >> b[i];
        if (b[i] != -1) --b[i];
    }
    vb seen(n, false);
    vi ans(n, -1);
    forn(i, n) if (b[i] != -1) {
        if (ans[i] != -1) {
            if (ans[i] != b[i]) {
                print("NO");
                return;
            }
            continue;
        }
        if (cs[i] != cs[b[i]]) {
            print("NO");
            return;
        }
        int x = i;
        int y = b[i];
        auto it = s.find({cs[y], ms[y]});
        if (it == s.end()) {
            print("NO");
            return;
        }
        s.erase(it);
        forn (_, cs[i]) {
            ans[x] = y;
            assert(!seen[y]);
            seen[y] = true;
            x = a[x];
            y = a[y];
        }
    }
    forn(i, n) if (ans[i] == -1) {
        int l = cs[i];
        auto it = s.lower_bound({l, -1});
        assert(it != s.end() && it->fi == l);
        int m = it->se;
        s.erase(it);
        int x = i;
        int y = m;
        forn(_, l) {
            ans[x] = y;
            x = a[x];
            y = a[y];
        }
    }
    assert(s.empty());

    forn (i, n) ++ans[i];
    print("YES");
    print(all(ans));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
