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

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;
ll MOD;

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
    bool mmod = false;
    T madd1 = 0;
    T madd2 = 0;

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

    void mod(int L, int R) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            mmod = true;
            madd1 = (madd1 + madd2) % MOD;
            madd2 = 0;
            // Recalculate aggregate value here
            val = val % MOD;
        } else {
            push(), l->mod(L, R), r->mod(L, R);
            val = comb(l->val, r->val);
        }
    }

    void add(int i, T d) { add(i, i + 1, d); }
    void add(int L, int R, T d) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            madd2 += d;
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
        if (mmod) {
            l->add(lo, hi, madd1), r->add(lo, hi, madd1), madd1 = 0;
            l->mod(lo, hi), r->mod(lo, hi), mmod = false;
        }
        if (madd2)
            l->add(lo, hi, madd2), r->add(lo, hi, madd2), madd2 = 0;
    }
};
char ST::buf[450 << 20];

void solve() {
    int n, q; cin >> n >> q >> MOD;
    vll a(n);
    forn (i, n) {
        cin >> a[i];
    }
    ST st(a);
    forn(_, q) {
        int t; cin >> t;
        if (t == 1) {
            int l, r, x; cin >> l >> r >> x; --l; --r;
            st.add(l, r + 1, x);
        } else if (t == 2) {
            int l, r; cin >> l >> r; --l; --r;
            st.mod(l, r + 1);
        } else {
            int i; cin >> i; --i;
            print(st.query(i));
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
