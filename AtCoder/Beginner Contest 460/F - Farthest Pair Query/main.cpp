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

template<class T>
struct SpT {
	vector<vector<T>> jmp;
	SpT(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= len(V); pw *= 2, ++k) {
			jmp.eb(len(V) - pw * 2 + 1);
			forn(j, len(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}

    // Half-open interval [L, R)
	T query(int L, int R) {
		assert(L < R); // or return inf if a == b
		int dep = 31 - __builtin_clz(R - L);
		return min(jmp[dep][L], jmp[dep][R - (1 << dep)]);
	}
};

struct LCA {
	int T = 0;
	vi time, path, ret, depth;
	SpT<int> spt;

	LCA(vvi& g) : time(len(g)), depth(len(g)), spt((dfs(g, 0), ret)) {}

	void dfs(vvi& g, int u, int p = -1, int d = 0) {
		time[u] = T++;
        depth[u] = d;
		for (int v : g[u]) if (v != p) {
			path.pb(u), ret.pb(time[u]);
			dfs(g, v, u, d + 1);
		}
	}

	int lca(int u, int v) {
		if (u == v) return u;
		tie(u, v) = minmax(time[u], time[v]);
		return path[spt.query(u, v)];
	}

    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
};

struct ST {
    typedef pii T;
    static constexpr T ID = {-1, -1};

    inline T comb(T a, T b) {
        if (a.fi == -1) return b;
        if (b.fi == -1) return a;
        a3i mx = max(a3i({lca.dist(a.fi, a.se), a.fi, a.se}), a3i({lca.dist(b.fi, b.se), b.fi, b.se}));
        for (int u : {a.fi, a.se}) for (int v : {b.fi, b.se}) {
            cmax(mx, {lca.dist(u, v), u, v});
        }
        return {mx[1], mx[2]};
    }

    int n;
    vector<T> tree;
    LCA lca;

    ST(int n, LCA&& lca) : n(n), tree(2 * n), lca(lca) {
        forn (i, n) {
            tree[i + n] = {i, i};
        }
        rforn (i, n) {
            tree[i] = comb(tree[i * 2], tree[i * 2 + 1]);
        }
    }

    int query() {
        auto [u, v] = query(0, n);
        return lca.dist(u, v);
    }

    T query(int L, int R) {
        T ra = ID, rb = ID;
        for (L += n, R += n; L < R; L /= 2, R /= 2) {
            if (L % 2) ra = comb(ra, tree[L++]);
            if (R % 2) rb = comb(tree[--R], rb);
        }
        return comb(ra, rb);
    }

    void update(int pos) {
        pos += n;
        tree[pos] = tree[pos].fi == -1 ? make_pair(pos - n, pos - n) : make_pair(-1, -1);
        for (; pos /= 2;) {
            tree[pos] = comb(tree[pos * 2], tree[pos * 2 + 1]);
        }
    }
};

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;
const ll MOD = 998244353;

void solve() {
    int n; cin >> n;
    vvi g(n);
    forn(_, n - 1) {
        int u, v; cin >> u >> v; --u; --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    ST st(n, LCA(g));
    int q; cin >> q;
    forn(_, q) {
        int x; cin >> x; --x;
        st.update(x);
        print(st.query());
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
