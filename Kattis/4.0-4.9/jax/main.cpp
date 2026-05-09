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

struct Trie {
    static constexpr int MAXN = 5e5 + 1;
    static constexpr int K = 26;
    static constexpr char OFFSET = 'a';

    struct Node {
        char chr;
        int c;
        int child[K];
        Node(char a, int c = 0): chr(a), c(c) { memset(child, -1, sizeof(child)); }
    };

    vector<Node> nodes;

    Trie() {
        nodes.reserve(MAXN);
        nodes.eb('^');
    }

    void insert(string& word) {
        int cur = 0;
        for (char c : word) {
            int idx = c - OFFSET;
            if (nodes[cur].child[idx] == -1) {
               nodes[cur].child[idx] = len(nodes);
               nodes.eb(c);
            }
            cur = nodes[cur].child[idx];
            ++nodes[cur].c;
        }
    }

    int longest_pref(string& word) {
        int cur = 0;
        int l = 0;
        for (char c : word) {
            Node& node = nodes[cur];
            int idx = c - OFFSET;
            if (node.child[idx] == -1) break;
            cur = node.child[idx];
            if (nodes[cur].c < 2) break;
            ++l;
        }
        return l;
    }

    int starts_with(string& word, int l) {
        int cur = 0;
        forn (i, l) {
            char c = word[i];
            Node& node = nodes[cur];
            int idx = c - OFFSET;
            if (node.child[idx] == -1) return 0;
            cur = node.child[idx];
        }
        return nodes[cur].c;
    }
};

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;
const ll MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<string> a(n);
    vector<string> b(n);
    vector<string> c(n);
    Trie ta;
    Trie tb;
    Trie tc;
    forn(i, n) {
        cin >> a[i];
        b[i] = a[i];
        reverse(all(b[i]));
        c[i].reserve(len(a[i]) * 2);
        forn(j, len(a[i])) {
            c[i] += a[i][j];
            c[i] += a[i][len(a[i]) - j - 1];
        }
        ta.insert(a[i]);
        tb.insert(b[i]);
        tc.insert(c[i]);
    }
    vi ans;
    forn(i, n) {
        int l = min(ta.longest_pref(a[i]), tb.longest_pref(b[i]));
        if (tc.starts_with(c[i], l * 2) > 1) ans.pb(0);
        else ans.pb(l);
    }
    print(all(ans));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
