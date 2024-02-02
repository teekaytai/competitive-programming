#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forn1(i, n) for (int i = 1; i <= (n); ++i)
#define rforn(i, n) for (int i = (n) - 1; i >= 0; --i)
#define rforn1(i, n) for (int i = (n); i > 0; --i)
#define all(x) x.begin(), x.end()
#define len(x) (int) x.size()
#define LSB(x) ((x) & -(x))
#define pb push_back
#define x first
#define y second

struct FT {
    vector<bitset<100>> tree;

    FT(int n) { tree.assign(n + 1, 0); }

    FT(const vector<bitset<100>>& a) { build(a); }

    void build(const vector<bitset<100>>& a) {
        int n = len(a);
        tree.assign(n + 1, 0);
        forn1(i, n) {
            tree[i] ^= a[i - 1];
            if (i + LSB(i) <= n) {
                tree[i + LSB(i)] ^= tree[i];
            }
        }
    }

    bitset<100> query(int k) {
        bitset<100> t = 0;
        for (int i = min(k + 1, len(tree) - 1); i > 0; i -= LSB(i)) {
            t ^= tree[i];
        }
        return t;
    }

    bitset<100> query(int lo, int hi) {
        return query(hi) ^ query(lo - 1);
    }

    void update(int k, bitset<100> d) {
        assert(k >= 0 && k < len(tree) - 1);
        for (int i = k + 1; i < len(tree); i += LSB(i)) {
            tree[i] ^= d;
        }
    }
};

const int INF = 1e9;
const int MAXN = 3e5;

int a[MAXN];
vvi g;
int tin[MAXN];
int tout[MAXN];
vector<bitset<100>> b;

int dfs(int v, int t = 0) {
    tin[v] = t;
    for (int u : g[v]) {
        t = dfs(u, t + 1);
    }
    tout[v] = t;
    return t;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q; cin >> n >> q;
    forn(i, n) {
        cin >> a[i];
        --a[i];
    }
    g.assign(n, vi());
    forn1(i, n-1) {
        int p; cin >> p;
        --p;
        g[p].pb(i);
    }
    dfs(0);
    b.assign(n, 0);
    forn(i, n) {
        b[tin[i]].set(a[i]);
    }
    FT ft(b);
    forn(i, q) {
        int k, x; cin >> k >> x;
        --x;
        if (k == 0) {
            cout << ft.query(tin[x], tout[x]).count() << "\n";
        } else {
            bitset<100> new_b = 0;
            new_b.set(k - 1);
            new_b ^= b[tin[x]];
            b[tin[x]] ^= new_b;
            ft.update(tin[x], new_b);
        }
    }

    return 0;
}
