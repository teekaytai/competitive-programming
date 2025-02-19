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
    cerr << "\u001B[31m{";
    if (!v.empty()) cerr << v[0];
    forn1 (i, len(v) - 1) cerr << ", " << v[i];
    cerr << "}\u001B[0m" << endl;
}

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;
const int MOD = 998244353;

void solve() {
    string s; cin >> s;
    int lo = 0;
    int hi = len(s) - 1;
    while (lo < hi && s[lo] == s[hi]) ++lo, --hi;
    int mid = len(s) / 2;
    int r = mid;
    int l = r - 1;
    while (l >= 0 && s[l] == s[r]) --l, ++r;
    map<int, int> m;
    int c = 0;
    for (int i = lo; i <= l; ++i) {
        c += ++m[s[i]] == 1;
        c -= --m[s[len(s) - 1 - i]] == 0;
    }
    if (c == 0) {
        print(max(l - lo + 1, 0));
        return;
    }
    map<int, int> mt;
    for (int i = lo; i <= hi; ++i) ++mt[s[i]];
    for (auto& [k, v] : mt) v /= 2;
    int i = lo;
    int um = len(mt);
    map<int, int> m2;
    while (um) {
        char cc = s[i++];
        um -= mt.contains(cc) && mt[cc]==++m2[cc];
    }
    int j = hi;
    um = len(mt);
    map<int, int> m3;
    while (um) {
        char cc = s[j--];
        um -= mt.contains(cc) && mt[cc]==++m3[cc];
    }
    print(min(i - lo, hi - j));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
