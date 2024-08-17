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

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;

vector<string> S = {"BG", "BR", "BY", "GR", "GY", "RY"};

void solve() {
    int n, q; cin >> n >> q;
    vi a(n);
    forn(i, n) {
        string s; cin >> s;
        a[i] = int(find(all(S), s) - S.begin());
    }
    vvi b(15);
    vvi B(15);
    forn(i, 6) forn (j, i) {
        int k = i * (i - 1) / 2 + j;
        vi& c = b[k];
        vi& C = B[k];
        c.resize(n);
        C.resize(n);
        c[0] = a[0] != j && a[0] != i ? 0 : -1;
        forn1(l, n - 1) c[l] = a[l] != j && a[l] != i ? l : c[l - 1];
        C[n - 1] = a[n-1] != j && a[n-1] != i ? n - 1 : -1;
        rforn(l, n - 1) C[l] = a[l] != j && a[l] != i ? l : C[l + 1];
    }
    forn(i, q) {
        int x, y; cin >> x >> y;
        --x; --y;
        if (y < x) swap(x, y);
        int j = a[x];
        int k = a[y];
        if (S[j][0] == S[k][0] || S[j][0] == S[k][1] || S[j][1] == S[k][0] || S[j][1] == S[k][1]) {
            print(y - x);
            continue;
        }
        if (k < j) swap(j, k);
        vi& c = b[k * (k - 1) / 2 + j];
        vi& C = B[k * (k - 1) / 2 + j];
        if (c[y] >= x) print(y - x);
        else if (c[x] == -1 && C[y] == -1) print(-1);
        else print(y - x + 2 * min(c[x] > -1 ? x - c[x] : INF, C[y] > -1 ? C[y] - y : INF));
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
