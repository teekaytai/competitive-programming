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

int n;
int m;
int k;
vb bs;
vi res;

void q() {
    cout << "? " << k;
    forn(i, m) if (bs[i]) {
        cout << " " << (i + 1);
    }
    cout << endl;
    int c; cin >> c;
    res.resize(c);
    forn(i, c) {
        cin >> res[i];
        --res[i];
    }
}

void f(vi& a) {
    cout << "!";
    for(int x : a) {
        cout << " " << (x + 1);
    }
    cout << endl;
}

void solve() {
    cin >> n;
    m = n * n + 1;
    k = m;
    bs.assign(m, true);
    vpii dps(m, {0, -1});
    vpii dns(m, {0, -1});
    vpii aps(m, {0, m});
    vpii ans(m, {0, m});
    forn(_, n) {
        q();
        if (len(res) >= n + 1) {
            res.resize(n + 1);
            f(res);
            return;
        }
        int ri = 1;
        int p = res[0];
        int c = ri == len(res) ? m : res[ri];
        forn(i, m) if (i > res[0] && bs[i]) {
            if (i == c) {
                cmax(aps[i], {aps[p].fi + 1, p});
                cmax(ans[p], {ans[i].fi + 1, i});
                p = c;
                c = ++ri == len(res) ? m : res[ri];
            } else {
                cmax(dps[i], {dps[p].fi + 1, p});
                cmax(dns[p], {dns[i].fi + 1, i});
                if (c < m) {
                    cmax(ans[i], {ans[c].fi + 1, c});
                    cmax(aps[c], {aps[i].fi + 1, i});
                }
            }
        }
        vi x;
        forn(i, m) if (dps[i].fi + dns[i].fi + 1 >= n + 1) {
            int mn = min(dps[i].fi + 1, n + 1);
            int c = i;
            forn(j, mn) {
                x.pb(c);
                c = dps[c].se;
            }
            reverse(all(x));
            c = dns[i].se;
            forn(j, n + 1 - mn) {
                x.pb(c);
                c = dns[c].se;
            }
            f(x);
            return;
        }
        forn(i, m) if (aps[i].fi + ans[i].fi + 1 >= n + 1) {
            int mn = min(aps[i].fi + 1, n + 1);
            int c = i;
            forn(j, mn) {
                x.pb(c);
                c = aps[c].se;
            }
            reverse(all(x));
            c = ans[i].se;
            forn(j, n + 1 - mn) {
                x.pb(c);
                c = ans[c].se;
            }
            f(x);
            return;
        }
        for (int v : res) {
            bs[v] = false;
        }
        k -= len(res);
    }
    assert(false);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
