#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define all(x) begin(x), end(x)
#define len(x) int(size(x))
#define pb push_back
#define eb emplace_back

struct UF {
    vector<int> pars;
    vector<int> sizes;
    int num_sets;

    UF(int n) {
        pars.assign(n, -1);
        sizes.assign(n, 1);
        num_sets = n;
    }

    int find(int i) {
        return pars[i] < 0 ? i : (pars[i] = find(pars[i]));
    }

    bool onion(int i, int j) {
        int r1 = find(i);
        int r2 = find(j);
        if (r1 == r2) return false;
        if (sizes[r2] > sizes[r1]) swap(r1, r2);
        pars[r2] = r1;
        sizes[r1] += sizes[r2];
        num_sets -= 1;
        return true;
    }

    bool is_same_set(int i, int j) { return find(i) == find(j); }
    int set_size(int i) { return sizes[find(i)]; }
};

struct ST {
    static char buf[450 << 20];
    void* operator new(size_t s) {
        static size_t i = sizeof buf;
        assert(s < i);
        return (void*) &buf[i -= s];
    }
    void operator delete(void*) {}
    void operator delete(void*, size_t) {}

    typedef ll T;
    static constexpr T ID = 0; // Identity value
    ST *l = 0, *r = 0;
    int lo, hi;
    T val = ID;
    T madd = 0;

    inline T comb(T x, T y) {
        return max(x, y);
    }

    ST(int n) : ST(0, n) {}

    // Half-open interval [lo, hi) filled with ID
    ST(int lo, int hi): lo(lo), hi(hi) {}

    ST(vector<T>& A) : ST(A, 0, len(A)) {}
    ST(vector<T>& A, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            l = new ST(A, lo, mid);
            r = new ST(A, mid, hi);
            val = comb(l->val, r->val);
        } else val = A[lo];
    }

    // Half-open interval [L, R)
    T query(int i) { return query(i, i + 1); }
    T query(int L, int R) {
        if (R <= lo || hi <= L) return ID;
        if (L <= lo && hi <= R) return val;
        push();
        return comb(l->query(L, R), r->query(L, R));
    }

    void add(int i, T d) { add(i, i + 1, d); }
    void add(int L, int R, T d) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            madd += d;
            // Recalculate aggregate value here
            val += d;
        } else {
            push(), l->add(L, R, d), r->add(L, R, d);
            val = comb(l->val, r->val);
        }
    }

    void push() {
        if (!l) {
            int mid = lo + (hi - lo) / 2;
            l = new ST(lo, mid); r = new ST(mid, hi);
        }
        if (madd)
            l->add(lo, hi, madd), r->add(lo, hi, madd), madd = 0;
    }
};
char ST::buf[450 << 20];

template <bool VALS_EDGES> struct HLD {
	int N, tim = 0;
	vector<vi> adj;
	vi par, siz, rt, pos;
	ST *tree;
	HLD(vector<vi> adj_)
		: N(len(adj_)), adj(adj_), par(N, -1), siz(N, 1),
		  rt(N),pos(N),tree(new ST(0, N)){ dfsSz(0); dfsHld(0); }
	void dfsSz(int v) {
		for (int& u : adj[v]) {
			adj[u].erase(find(all(adj[u]), v));
			par[u] = v;
			dfsSz(u);
			siz[v] += siz[u];
			if (siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
		}
	}
	void dfsHld(int v) {
		pos[v] = tim++;
		for (int u : adj[v]) {
			rt[u] = (u == adj[v][0] ? rt[v] : u);
			dfsHld(u);
		}
	}
	template <class B> void process(int u, int v, B op) {
		for (;; v = par[rt[v]]) {
			if (pos[u] > pos[v]) swap(u, v);
			if (rt[u] == rt[v]) break;
			op(pos[rt[v]], pos[v] + 1);
		}
		op(pos[u] + VALS_EDGES, pos[v] + 1);
	}
	void modifyPath(int u, int v, ll val) {
		process(u, v, [&](int l, int r) { tree->add(l, r, val); });
	}
	ll queryPath(int u, int v) { // Modify depending on problem
		ll res = 0;
		process(u, v, [&](int l, int r) {
				res = max(res, tree->query(l, r));
		});
		return res;
	}
};

void solve() {
    int n, m; cin >> n >> m;
    int N = n * m;
    vll a(N);
    vector<tuple<ll, int, int>> E;
    int v = 0;
    forn(i, n) {
        forn(j, m) {
            cin >> a[v];
            if (j > 0) E.eb(max(a[v - 1], a[v]), v - 1, v);
            if (i > 0) E.eb(max(a[v - m], a[v]), v - m, v);
            ++v;
        }
    }
    sort(all(E));
    vvi g(N);
    UF uf(N);
    for (auto [w, u, v] : E) {
        if (uf.onion(u, v)) {
            g[u].pb(v);
            g[v].pb(u);
        }
    }
    HLD<false> hld(g);
    forn (u, N) {
        hld.modifyPath(u, u, a[u]);
    }
    int q; cin >> q;
    forn(_, q) {
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        --r1; --c1; --r2; --c2;
        cout << hld.queryPath(r1 * m + c1, r2 * m + c2) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
