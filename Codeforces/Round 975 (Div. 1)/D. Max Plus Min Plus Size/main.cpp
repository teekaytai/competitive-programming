#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
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

struct UF {
    vector<int> pars;
    vector<int> sizes;
    vector<int> left;
    vector<int> um;
    int num_sets;

    UF(vi& a) {
        int n = len(a);
        int mx = *max_element(all(a));
        pars.resize(n);
        iota(all(pars), 0);
        sizes.assign(n, 1);
        left.resize(n);
        iota(all(left), 0);
        um.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            if (a[i] == mx) {
                um[i] = i % 2 ? 1 : 2;
            }
        }
        num_sets = n;
    }

    int find(int i) {
        return pars[i] == i ? i : (pars[i] = find(pars[i]));
    }

    bool onion(int i, int j) {
        int r1 = find(i);
        int r2 = find(j);
        if (r1 == r2) return false;
        if (sizes[r2] > sizes[r1]) swap(r1, r2);
        pars[r2] = r1;
        sizes[r1] += sizes[r2];
        left[r1] = min(left[r1], left[r2]);
        um[r1] = um[r1] | um[r2];
        num_sets -= 1;
        return true;
    }

    bool is_same_set(int i, int j) { return find(i) == find(j); }
    int set_size(int i) { return sizes[find(i)]; }

    bool f(int i) {
        i = find(i);
        return um[i] == 3 || (um[i] != 0 && (sizes[i] % 2 == 0 || um[i] % 2 == left[i] % 2));
    }
};


const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;

void solve() {
    int n; cin >> n;
    vi a(n);
    forn(i, n) cin >> a[i];
    UF uf(a);
    vi o(n);
    iota(all(o), 0);
    sort(all(o), [&](int i1, int i2) {
        return a[i1] > a[i2];
    });
    vector<bool> seen(n, false);
    int mx = a[o[0]];
    int mn = mx;
    ll ans = 0;
    ll t = 0;
    int b = 0;
    for (int i : o) {
        t += 1;
        b += a[i] == mx;
        mn = min(mn, a[i]);
        seen[i] = true;
        if (i > 0 && seen[i - 1]) {
            t -= (uf.set_size(i) + 1) / 2 + (uf.set_size(i - 1) + 1) / 2;
            b -= uf.f(i) + uf.f(i-1);
            uf.onion(i-1, i);
            t += (uf.set_size(i) + 1) / 2;
            b += uf.f(i);
        }
        if (i < n-1 && seen[i + 1]) {
            t -= (uf.set_size(i) + 1) / 2 + (uf.set_size(i + 1) + 1) / 2;
            b -= uf.f(i) + uf.f(i+1);
            uf.onion(i+1, i);
            t += (uf.set_size(i) + 1) / 2;
            b += uf.f(i);
        }
        ans = max(ans, t + mx + mn - (b == 0));
    }
    print(ans);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
