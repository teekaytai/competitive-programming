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

template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    return os << "(" << p.fi << ", " << p.se << ")";
}
template <typename... Ts>
ostream& operator<<(ostream& os, const tuple<Ts...>& t) {
    os << "(";
    bool first = true;
    apply([&](const Ts&... elems) {
        ((os << (first ? "" : ", ") << elems, first = false), ...);
    }, t);
    os << ")";
    return os;
}

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

template<long unsigned int N>
using A = array<pair<ll, int>, N>;
constexpr pair<ll, int> id = {LLONG_MIN / 4, -1};

template<long unsigned int N>
void f(A<N>& a, pair<ll, int> p) {
    bool b = false;
    for (int i = 0; i < len(a); ++i) if (a[i].se == p.se) {
        b = true;
        if (p.fi <= a[i].fi) break;
        a[i].fi = p.fi;
        int j = i;
        while (j > 0 && a[j].fi > a[j - 1].fi) {
            swap(a[j - 1], a[j]);
            --j;
        }
        break;
    }
    if (!b) {
        int j = len(a) - 1;
        if (p.fi <= a[j].fi) return;
        a[j] = p;
        while (j > 0 && a[j].fi > a[j - 1].fi) {
            swap(a[j - 1], a[j]);
            --j;
        }
    }
}

template<long unsigned int N>
void f(A<N>& a, A<N>& a2) {
    for (auto& p : a2) {
        if (p.fi < 0) break;
        f(a, p);
    }
}

struct ST {
    static char buf[512 << 20];
    void* operator new(size_t s) {
        static size_t i = sizeof buf;
        assert(s < i);
        return (void*) &buf[i -= s];
    }
    void operator delete(void*) {}
    void operator delete(void*, size_t) {}

    typedef A<3> T;
    static constexpr T ID = {id, id, id}; // Identity value
    // static constexpr T FLAG = 1e9; // Flag value for mset to indicate no updates necessary
    ST *l = 0, *r = 0;
    int lo, hi;
    T val = ID;
    // T madd = ID;

    ST(int n) : ST(0, n) {}

    // Half-open interval [lo, hi) filled with ID
    ST(int lo, int hi): lo(lo), hi(hi) {}

    ST(vector<T>& A) : ST(A, 0, len(A)) {}
    ST(vector<T>& A, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            l = new ST(A, lo, mid);
            r = new ST(A, mid, hi);
            // val = comb(l->val, r->val);
        } else val = A[lo];
    }

    // Half-open interval [L, R)
    T query(int i) { return query(i, i + 1); }
    T query(int L, int R) {
        if (R <= lo || hi <= L) return ID;
        if (L <= lo && hi <= R) return val;
        push();
        T ans = l->query(L, R);
        if (ans[0].fi >= 0) return ans;
        return r->query(L, R);
    }

    // void add(int i, pll d) { add(i, i + 1, d); }
    void add(int L, int R, pair<ll, int>& d) {
        T temp = {d, id, id};
        add(L, R, temp);
    }
    void add(int L, int R, T& d) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            f(val, d);
            // Recalculate aggregate value here
            // val += d;
        } else {
            push(), l->add(L, R, d), r->add(L, R, d);
            // val = comb(l->val, r->val);
        }
    }

    void push() {
        if (!l) {
            int mid = lo + (hi - lo) / 2;
            l = new ST(lo, mid); r = new ST(mid, hi);
        }
        if (val[0].fi >= 0)
            l->add(lo, hi, val), r->add(lo, hi, val), val = ID;
    }
};
char ST::buf[512 << 20];

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;
const ll MOD = 998244353;

void solve() {
    int n; cin >> n;
    vpii a;
    A<4> mx_vs = {id, id, id, id};
    vector<vector<tuple<ll, int, int>>> b(n);
    forn(i, n) {
        int k, v; cin >> k >> v;
        a.eb(k, v);
        int i0 = mx_vs[0].se == k ? 3 : 0;
        int i1 = mx_vs[1].se == k ? 3 : 1;
        int i2 = mx_vs[2].se == k ? 3 : 2;
        for (auto [p, q] : {make_pair(i0, i1), make_pair(i0, i2), make_pair(i1, i2)}) {
            if (mx_vs[p].fi < 0 || mx_vs[q].fi < 0) continue;
            ll t = v + mx_vs[p].fi + mx_vs[q].fi;
            b[i].eb(t, mx_vs[p].se, mx_vs[q].se);
        }
        // printerr(all(b[i]));
        f(mx_vs, {v, k});
    }
    // printerr();
    ST st(n + 1);
    mx_vs = {id, id, id, id};
    ll ans = -1;
    rforn1(i, n - 1) {
        auto [k, v] = a[i];
        int i0 = mx_vs[0].se == k ? 3 : 0;
        int i1 = mx_vs[1].se == k ? 3 : 1;
        int i2 = mx_vs[2].se == k ? 3 : 2;
        for (auto [p, q] : {make_pair(i0, i1), make_pair(i0, i2), make_pair(i1, i2)}) {
            if (mx_vs[p].fi < 0 || mx_vs[q].fi < 0) continue;
            ll t = v + mx_vs[p].fi + mx_vs[q].fi;
            pair<ll, int> d = {t, k};
            a3i ks = {k, mx_vs[p].se, mx_vs[q].se};
            sort(all(ks));
            st.add(0, ks[0], d);
            st.add(ks[0] + 1, ks[1], d);
            st.add(ks[1] + 1, ks[2], d);
            st.add(ks[2] + 1, n + 1, d);
        }
        auto r = st.query(a[i - 1].fi);
        // printerr(all(r));
        for (auto [tr, kr] : r) {
            for (auto [tl, k1, k2] : b[i - 1]) if (k1 != kr && k2 != kr) {
                cmax(ans, tl + tr);
            }
        }
        f(mx_vs, {v, k});
    }
    print(ans);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();
}
