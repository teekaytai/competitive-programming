#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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
    cerr << "\u001B[31m";
    for (auto x : v) cerr << x << " ";
    cerr << "\u001B[0m" << endl;
}

ll modinv(ll x, ll mod) {
    return x <= 1 ? x : mod - mod / x * modinv(mod % x, mod) % mod;
}

ll moddiv(ll a, ll b, ll mod) {
    return a * modinv(b, mod) % mod;
}

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;
const int MOD = 998244353;

void solve() {
    int n, q; cin >> n >> q;
    vi a(n);
    vi b(n);
    forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i];
    vi sa = a;
    sort(all(sa));
    vi sb = b;
    sort(all(sb));
    ll p = 1;
    forn(i, n) p = (p * min(sa[i], sb[i])) % MOD;
    map<int, set<int>> ma;
    map<int, set<int>> mb;
    forn (i, n) {
        ma[sa[i]].insert(i);
        mb[sb[i]].insert(i);
    }
    cout << p << " ";
    forn(_, q) {
        int o, i; cin >> o >> i;
        --i;
        if (o == 1) {
            auto it = prev(ma[a[i]].end());
            int j = *it;
            ma[a[i]].erase(it);
            if (ma[a[i]].empty()) ma.erase(a[i]);
            if (sa[j] < sb[j]) {
                p = moddiv(p, sa[j], MOD);
                ++sa[j];
                p = p * sa[j] % MOD;
            } else ++sa[j];
            ++a[i];
            ma[a[i]].insert(j);
        } else {
            auto it = prev(mb[b[i]].end());
            int j = *it;
            mb[b[i]].erase(it);
            if (mb[b[i]].empty()) mb.erase(b[i]);
            if (sb[j] < sa[j]) {
                p = moddiv(p, sb[j], MOD);
                ++sb[j];
                p = p * sb[j] % MOD;
            } else ++sb[j];
            ++b[i];
            mb[b[i]].insert(j);
        }
        cout << p << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
