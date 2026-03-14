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

const int INF = 1e9;
vi ow;

struct ST {
    static char buf[450 << 20];
    void* operator new(size_t s) {
        static size_t i = sizeof buf;
        assert(s < i);
        return (void*) &buf[i -= s];
    }
    void operator delete(void*) {}
    void operator delete(void*, size_t) {}

    typedef pii T;
    static constexpr T ID = {INF, 0}; // Identity value
    ST *l = 0, *r = 0;
    int lo, hi;
    T val = ID;
    int madd = 0;

    inline T comb(T x, T y) {
        return x.fi == y.fi ? make_pair(x.fi, x.se + y.se) : min(x, y);
    }

    ST(int n) : ST(0, n) {}
    ST(int lo, int hi): lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            l = new ST(lo, mid);
            r = new ST(mid, hi);
            val = comb(l->val, r->val);
        } else val = {0, ow[lo + 1] - ow[lo]};
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
            madd += d;
            // Recalculate aggregate value here
            val.fi += d;
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

void solve() {
    int H, W, h, w, n; cin >> H >> W >> h >> w >> n;
    map<int, int> sw;
    sw[0] = -1;
    sw[W - w + 1] = -1;
    vector<a3i> a;
    forn(_, n) {
        int r, c; cin >> r >> c; --r; --c;
        sw[max(c - w + 1, 0)] = -1;
        sw[min(c + 1, W - w + 1)] = -1;
        a.pb({max(r - h + 1, 0), c, 1});
        a.pb({min(r + 1, H - h + 1), c, -1});
    }
    sort(all(a));
    ow.clear();
    int i = 0;
    for (auto& [c, ii] : sw) {
        ow.pb(c);
        ii = i++;
    }
    ST st(len(ow) - 1);
    ll ans = (ll) (H - h + 1) * (W - w + 1);
    forn (i, len(a)) {
        auto [r, c, d] = a[i];
        st.add(sw[max(c - w + 1, 0)], sw[min(c + 1, W - w + 1)], d);
        if (i < len(a) - 1 && r == a[i + 1][0]) continue;
        auto [k, v] = st.query(0, len(ow) - 1);
        if (i == len(a) - 1) {
            assert(k == 0 && v == W - w + 1);
            break;
        }
        ans -= (ll) (W - w + 1 - (k == 0 ? v : 0)) * (a[i + 1][0] - r);
    }
    print(ans);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
