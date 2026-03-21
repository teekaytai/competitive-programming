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

const ll MOD = 998244353;

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
    T mmul = 1;
    T madd = 0;

    inline T comb(T x, T y) {
        return (x + y) % MOD;
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

    void mul(int i, T d) { mul(i, i + 1, d); }
    void mul(int L, int R, T d) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (madd) push();
            mmul = mmul * d % MOD;
            // Recalculate aggregate value here
            val = val * d % MOD;
        } else {
            push(), l->mul(L, R, d), r->mul(L, R, d);
            val = comb(l->val, r->val);
        }
    }

    void add(int i, T d) { add(i, i + 1, d); }
    void add(int L, int R, T d) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            madd += d;
            // Recalculate aggregate value here
            val = (val + d * (hi - lo)) % MOD;
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
        if (mmul != 1)
            l->mul(lo, hi, mmul), r->mul(lo, hi, mmul), mmul = 1;
        else if (madd)
            l->add(lo, hi, madd), r->add(lo, hi, madd), madd = 0;
    }
};
char ST::buf[450 << 20];

void solve() {
    int n, m; cin >> n >> m;
    vpii e;
    forn(_, m) {
        int u, v; cin >> u >> v; --u; --v;
        e.eb(u, v);
    }
    sort(all(e));
    ST st(n);
    st.add(0, 1, 1);
    for (auto [u, v] : e) {
        st.add(v, v + 1, st.query(u, v + 1));
        st.mul(0, u, 2);
        st.mul(v + 1, n, 2);
    }
    print(st.query(n - 1, n));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
