#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define rforn(i, n) for (int i = (n) - 1; i >= 0; --i)
#define len(x) int(size(x))
#define pb push_back
#define eb emplace_back

template<class T>
struct SpT {
	vector<vector<T>> jmp;
    SpT() {}

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

    LCA() {}
	LCA(vvi& g, int r) : time(len(g)), depth(len(g)), spt((dfs(g, r), ret)) {}

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

LCA lca;

struct ST {
    struct T {
        int lca;
        int mxd;
    };
    static constexpr T ID = {-1, 0};

    inline T comb(T a, T b) {
        if (a.lca == -1) return b;
        if (b.lca == -1) return a;
        return {lca.lca(a.lca, b.lca), max(a.mxd, b.mxd)};
    }

    int n;
    vector<T> tree;

    ST(const vi& A) : n(len(A)), tree(2 * len(A), ID) {
        forn(i, n) {
            tree[i + n] = {A[i], lca.depth[A[i]]};
        }
        rforn (i, n) {
            tree[i] = comb(tree[i * 2], tree[i * 2 + 1]);
        }
    }

    // Half-open interval [L, R)
    T query(int L, int R) {
        T ra = ID, rb = ID;
        for (L += n, R += n; L < R; L /= 2, R /= 2) {
            if (L % 2) ra = comb(ra, tree[L++]);
            if (R % 2) rb = comb(tree[--R], rb);
        }
        return comb(ra, rb);
    }

    void update(int pos, int v) {
        pos += n;
        tree[pos] = {v, lca.depth[v]};
        for (; pos /= 2;) {
            tree[pos] = comb(tree[pos * 2], tree[pos * 2 + 1]);
        }
    }
};

void solve() {
    int n, m, q; cin >> n >> m >> q;
    int r = -1;
    vvi g(n);
    forn(u, n) {
        int v; cin >> v; --v;
        if (u == v) r = u;
        else g[v].pb(u);
    }
    lca = LCA(g, r);
    vi a(2 * m);
    vi ra(n, -1);
    forn(i, m) {
        cin >> a[i]; --a[i];
        a[i + m] = a[i];
        ra[a[i]] = i;
    }
    ST st(a);
    forn(_, q) {
        int t; cin >> t;
        if (t == 1) {
            int u, v; cin >> u >> v; --u; --v;
            int x = ra[u];
            int y = ra[v];
            if (x != -1) {
                a[x] = v;
                a[x + m] = v;
                st.update(x, v);
                st.update(x + m, v);
            }
            if (y != -1) {
                a[y] = u;
                a[y + m] = u;
                st.update(y, u);
                st.update(y + m, u);
            }
            ra[v] = x;
            ra[u] = y;
        } else {
            int x, k; cin >> x >> k; --x;
            int lo = x;
            int hi = x + m - 1;
            while (lo < hi) {
                int mid = (lo + hi + 1) / 2;
                auto [l, d] = st.query(x, mid + 1);
                if (d - lca.depth[l] <= k) lo = mid;
                else hi = mid - 1;
            }
            int ans = lo - x + 1;
            lo = x + 1;
            hi = x + m;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                auto [l, d] = st.query(mid, x + m + 1);
                if (d - lca.depth[l] <= k) hi = mid;
                else lo = mid + 1;
            }
            ans = max(ans, x + m - lo + 1);
            cout << ans << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
