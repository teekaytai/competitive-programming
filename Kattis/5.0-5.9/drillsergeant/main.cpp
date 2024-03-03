#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
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
#define x first
#define y second

template <typename... Ts>
inline void print(const Ts&... args) {
    const char* sep = "";
    (((cout << sep << args), sep = " "), ...);
    cout << "\n";
}
template <typename... Ts>
inline void printerr(const Ts&... args) {
    const char* sep = "";
    cerr << "\u001B[31m";
    (((cerr << sep << args), sep = " "), ...);
    cerr << "\u001B[0m" << endl;
}


const int INF = 1e9+1;
const int MAXN = 3e5;

int S[4] = {3, 32, 323, 3233};
umap<int, uset<int>> g;
map<int, int> s {{INF, 0}, {-INF, 0}};

void solve() {
    int n, m; cin >> n >> m;
    forn(i, m) {
        int u, v; cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    int q; cin >> q;
    ll t = 0;
    forn(i, q) {
        int d, z; cin >> d >> z;
        if (d == 1) {
            s[z] = 0;
            auto it = s.find(z);
            auto p = prev(it);
            t -= S[p->y];
            p->y &= 0b10;
            bool b = g[z].find(p->x) != g[z].end();
            p->y |= b ? 0b01 : 0;
            t += S[p->y];
            it->y |= b ? 0b10 : 0;

            auto n = next(it);
            t -= S[n->y];
            n->y &= 0b01;
            b = g[z].find(n->x) != g[z].end();
            n->y |= b ? 0b10 : 0;
            t += S[n->y];
            it->y |= b ? 0b01 : 0;

            t += S[it->y];
        } else {
            auto it = s.find(z);
            auto p = prev(it);
            auto n = next(it);
            t -= S[it->y];
            s.erase(it);

            t -= S[p->y];
            p->y &= 0b10;
            bool b = g[p->x].find(next(p)->x) != g[p->x].end();
            p->y |= b ? 0b01 : 0;
            t += S[p->y];

            t -= S[n->y];
            n->y &= 0b01;
            b = g[n->x].find(prev(n)->x) != g[n->x].end();
            n->y |= b ? 0b10 : 0;
            t += S[n->y];
        }
        print(t);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    // int t; cin >> t;
    // while (t--) {
        solve();
    // }
}
