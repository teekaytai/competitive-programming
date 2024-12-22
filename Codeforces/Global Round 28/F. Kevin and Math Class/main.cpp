#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<bool> vb;
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

void solve() {
    int n; cin >> n;
    vll a(n), b(n);
    forn (i, n) cin >> a[i];
    forn (i, n) cin >> b[i];

    // Treap/Cartesian tree
    vi l(n, -1), r(n, -1);
    stack<int> st;
    forn (i, n) {
        while (!st.empty() && b[st.top()] > b[i]) {
            int j = st.top();
            st.pop();
            if (!st.empty() && b[st.top()] > b[i]) {
                r[st.top()] = j;
            } else {
                l[i] = j;
            }
        }
        st.push(i);
    }
    int s;
    while (!st.empty()) {
        s = st.top();
        st.pop();
        if (!st.empty()) {
            r[st.top()] = s;
        }
    }

    auto dfs = [&](auto dfs, int u) {
        array<ll, 64> ans = {0};
        if (u == -1) return ans;
        fill_n(ans.begin(), 64, a[u]);
        auto ls = dfs(dfs, l[u]);
        auto rs = dfs(dfs, r[u]);
        int i = 0;
        int j = 0;
        ans[0] = max({ans[0], ls[0], rs[0]});
        while (i + j < 63) {
            if (ls[i] >= rs[j]) ++i;
            else ++j;
            ans[i+j] = max({ans[i+j], ls[i], rs[j]});
        }
        forn (k, 63) ans[k+1] = min(ans[k+1], (ans[k]+b[u]-1)/b[u]);
        return ans;
    };
    auto arr = dfs(dfs, s);
    int x = 0;
    while (arr[x] > 1) ++x;
    print(x);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
