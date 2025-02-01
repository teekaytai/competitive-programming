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
    cerr << "\u001B[31m";
    for (auto x : v) cerr << x << " ";
    cerr << "\u001B[0m" << endl;
}

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;

void solve() {
    int n, v; cin >> n >> v;
    vi a(n), b(n), c(n);
    forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i];
    forn(i, n) cin >> c[i];
    sort(rall(a));
    sort(rall(b));
    sort(rall(c));
    auto f = [&](int i, int j, int k) { return pair<ll, t3i>((ll)a[i]*b[j]+(ll)b[j]*c[k]+(ll)c[k]*a[i], {i, j, k}); };
    priority_queue<pair<ll, t3i>> pq;
    set<t3i> s;
    pq.push(f(0, 0, 0));
    forn(_, v - 1) {
        auto [i, j, k] = pq.top().se;
        pq.pop();
        if (i < n-1 && !s.contains({i+1, j, k})) pq.push(f(i+1, j, k)), s.emplace(i+1, j, k);
        if (j < n-1 && !s.contains({i, j+1, k})) pq.push(f(i, j+1, k)), s.emplace(i, j+1, k);
        if (k < n-1 && !s.contains({i, j, k+1})) pq.push(f(i, j, k+1)), s.emplace(i, j, k+1);
    }
    print(pq.top().fi);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();
}
