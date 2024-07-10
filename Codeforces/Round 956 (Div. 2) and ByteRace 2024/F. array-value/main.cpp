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

struct Trie {
    static constexpr int MAXN = 2e6;
    static constexpr int K = 2;

    struct Node {
        int max_idx = -1;
        int child[K] = {-1, -1};
    };

    vector<Node> nodes;

    Trie() {
        nodes.reserve(MAXN);
        nodes.eb();
    }

    void reset() {
        nodes.clear();
        nodes.eb();
    }

    void insert(int x, int i) {
        int cur = 0;
        for (int b = 1 << 29; b; b >>= 1) {
            int c = (x & b) > 0;
            if (nodes[cur].child[c] == -1) {
               nodes[cur].child[c] = len(nodes);
               nodes.eb();
            }
            cur = nodes[cur].child[c];
            nodes[cur].max_idx = i;
        }
    }

    int query(int x, int k) {
        int cur = 0;
        int mx = -1;
        for (int b = 1 << 29; b; b >>= 1) {
            int c = (x & b) > 0;
            if (k & b && nodes[cur].child[c] != -1) {
                mx = max(mx, nodes[nodes[cur].child[c]].max_idx);
            }
            int nxt = nodes[cur].child[((x ^ k) & b) > 0];
            if (nxt == -1) {
               return mx;
            }
            cur = nxt;
        }
        return max(mx, nodes[cur].max_idx);
    }
};

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;

void solve() {
    int n; ll k; cin >> n >> k;
    vi a(n);
    forn(i, n) cin >> a[i];
    Trie trie;
    int lo = 0;
    int hi = (1 << 30) - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        trie.reset();
        ll t = 0;
        int m = -1;
        forn (i, n) {
            m = max(m, trie.query(a[i], mid));
            t += m + 1;
            trie.insert(a[i], i);
        }
        if (t < k) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    print(lo);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
