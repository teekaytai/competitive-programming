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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define len(x) (int) x.size()
#define LSB(x) ((x) & -(x))
inline int MSB(int x) { return x ? 1 << (31 - __builtin_clz(x)) : 0; }
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
const int MAXN = 1e5+1;

int temp[MAXN];

int f(vi& a, int lo, int hi) {
    if (lo == hi) return 0;
    int mid = (lo + hi) / 2;
    int t = f(a, lo, mid) + f(a, mid+1, hi);
    int l = lo;
    int r = mid+1;
    forn (i, hi - lo + 1) {
        if (l > mid) temp[i] = a[r++];
        else if (r > hi) temp[i] = a[l++];
        else if (a[l] <= a[r]) {
            temp[i] = a[l++];
        } else {
            t += mid - l + 1;
            temp[i] = a[r++];
        }
    }
    l = lo;
    forn (i, hi - lo + 1) a[l++] = temp[i];
    return t;
}

void solve() {
    int n; cin >> n;
    vi a(n), b(n);
    forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i];
    int x = f(a, 0, n-1);
    int y = f(b, 0, n-1);
    bool s = false;
    forn(i, n-1) {
        if (a[i] == a[i+1]) {
            s = true;
            break;
        }
    }
    print(a==b && (s || (x-y)%2==0) ? "YES" : "NO");
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
