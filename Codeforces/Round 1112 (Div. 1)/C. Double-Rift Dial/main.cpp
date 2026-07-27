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

struct ST {
    static char buf[250 << 20];
    void* operator new(size_t s) {
        static size_t i = sizeof buf;
        assert(s < i);
        return (void*) &buf[i -= s];
    }
    void operator delete(void*) {}
    void operator delete(void*, size_t) {}

    struct T {
        int mx = 0;
        int c = 0;
    };
    static constexpr T ID = {0, 0}; // Identity value
    ST *l = 0, *r = 0;
    int lo, hi;
    T val = ID;
    int madd = 0;
    int msub = 0;

    inline T comb(T x, T y) {
        return {max(x.mx, y.mx), 0};
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

    void add(int i, int d) { add(i, i + 1, d); }
    void add(int L, int R, int d) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (d < 0) msub -= d;
            else {
                int mn = min(d, msub);
                msub -= mn;
                madd += d - mn;
            }
            // Recalculate aggregate value here
            val.c += d;
            cmax(val.mx, val.c);
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
        if (msub)
            l->add(lo, hi, -msub), r->add(lo, hi, -msub), msub = 0;
    }
};
char ST::buf[250 << 20];

const ll MOD = 998244353;

void solve() {
    int n; cin >> n;
    vi p(n);
    forn(i, n) {
        cin >> p[i]; --p[i];
    }
    vi ts(n, -1);
    ST st(n);
    forn(i, n) {
        int x = p[i];
        ts[x] = i;
        int x1 = -1;
        int x2 = -1;
        if (x > 0 && ts[x - 1] != -1) x2 = ts[x - 1];
        if (x < n - 1 && ts[x + 1] != -1) {
            int y = ts[x + 1];
            if (y > x2) {
                x1 = x2;
                x2 = y;
            } else if (x2 != i) {
                x1 = y;
            } else {
                x2 = y;
            }
        }
        st.add(x2 + 1, i + 1, 1);
        st.add(0, x1 + 1, -1);
    }
    forn(i, n - 1) {
        int x = p[i];
        ts[x] += n;
        int x1 = -1;
        int x2 = i;
        if (x > 0) x2 = ts[x - 1];
        if (x < n - 1) {
            int y = ts[x + 1];
            if (x == 0) x2 = y;
            else if (y > x2) {
                x1 = x2;
                x2 = y;
            } else {
                x1 = y;
            }
        }
        st.add(x2 + 1, n, 1);
        st.add(i + 1, x1 + 1, -1);
    }
    int ans = 0;
    forn(i, n) ans += st.query(i, i + 1).mx <= 2;
    print(ans);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
