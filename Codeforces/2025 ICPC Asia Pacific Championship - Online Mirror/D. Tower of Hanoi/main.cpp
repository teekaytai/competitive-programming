#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> t3i;
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
#define len(x) (int) (x).size()
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
    cerr << "\u001B[31m{";
    if (!v.empty()) cerr << v[0];
    forn1 (i, len(v) - 1) cerr << ", " << v[i];
    cerr << "}\u001B[0m" << endl;
}

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;
const int MOD = 998244353;

ll modpow(ll x, ll p, ll mod = MOD) {
    ll ans = 1;
    while (p > 0) {
        if (p & 1) ans = ans * x % mod;
        x = x * x % mod;
        p >>= 1;
    }
    return ans;
}

struct ST {
	struct T {
        int l;
        array<ll, 3> ss;
        array<int, 3> ds;
    };
	static constexpr T ID = {0, {0ll}, {0, 1, 2}};

	inline T comb(T a, T b) {
        array<ll, 3> ss;
        array<int, 3> ds;
        forn(i, 3) {
            int j = b.ds[i];
            ss[i] = (b.ss[i] * modpow(2, a.l) + a.ss[j]) % MOD;
            ds[i] = a.ds[j];
        }
        return {a.l + b.l, ss, ds};
    }

    int n;
	vector<T> tree;

	ST(int n, T v = ID) : n(n), tree(2 * n, v) {
        for (int i = n - 1; i >= 0; --i) {
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

	void update(int pos, int d) {
        T t = ID;
        t.l = 1;
        t.ss[(d+1)%3] = 1ll;
        t.ss[(d+2)%3] = 1ll;
        swap(t.ds[(d+1)%3], t.ds[(d+2)%3]);
		for (tree[pos += n] = t; pos /= 2;) {
			tree[pos] = comb(tree[pos * 2], tree[pos * 2 + 1]);
        }
	}
};

void solve() {
    int n, q; cin >> n >> q;
    ST st(n);
    forn(i, n) {
        int d; cin >> d; --d;
        st.update(i, d);
    }
    forn(_, q) {
        char c; int l, r; cin >> c >> l >> r; --l;
        if (c == 'c') {
            --r;
            st.update(l, r);
        } else {
            print(st.query(l, r).ss[0]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    // int tc; cin >> tc;
    // while (tc--) {
    solve();
    // }
}
