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
    static char buf[450 << 20];
    void* operator new(size_t s) {
        static size_t i = sizeof buf;
        assert(s < i);
        return (void*) &buf[i -= s];
    }
    void operator delete(void*) {}
    void operator delete(void*, size_t) {}

    struct T {
        int num_up;
        ll mx;
    };
    static constexpr T ID = {0, 0}; // Identity value
    static constexpr int FLAG = 0;
    ST *l = 0, *r = 0;
    int lo, hi;
    T val = ID;
    int mflips = FLAG;
    ll madd = 0;

    inline T comb(T x, T y) {
        return {x.num_up + y.num_up, max(x.mx, y.mx)};
    }

    ST(int n) : ST(0, n) {}

    // Half-open interval [lo, hi) filled with ID
    ST(int lo, int hi): lo(lo), hi(hi) {
        val.num_up = hi - lo;
    }

    // Half-open interval [L, R)
    ll query(int i) { return query(i, i + 1); }
    ll query(int L, int R) {
        if (R <= lo || hi <= L) return ID.mx;
        if (L <= lo && hi <= R) return val.mx;
        push();
        return max(l->query(L, R), r->query(L, R));
    }

    void flip(int L, int R, int x = 1) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            mflips += x;
            madd = 0;
            // Recalculate aggregate value here
            if (x % 2 == 1) {
                val.num_up = hi - lo - val.num_up;
            }
            val.mx = 0;
        } else {
            push(), l->flip(L, R, x), r->flip(L, R, x);
            val = comb(l->val, r->val);
        }
    }

    void add(int L, int R, ll d) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            madd += d;
            // Recalculate aggregate value here
            if (val.num_up > 0) val.mx += d;
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
        if (mflips != FLAG)
            l->flip(lo, hi, mflips), r->flip(lo, hi, mflips), mflips = FLAG;
        if (madd)
            l->add(lo, hi, madd), r->add(lo, hi, madd), madd = 0;
    }
};
char ST::buf[450 << 20];


const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;
const ll MOD = 998244353;

void solve() {
    int n, q; cin >> n >> q;
    ST st(n);
    forn(_, q) {
        int t, l, r; cin >> t >> l >> r;
        --l; --r;
        if (t == 1) {
            int x; cin >> x;
            st.add(l, r + 1, x);
        } else if (t == 2) {
            st.flip(l, r + 1);
        } else {
            print(st.query(l, r + 1));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();
}
