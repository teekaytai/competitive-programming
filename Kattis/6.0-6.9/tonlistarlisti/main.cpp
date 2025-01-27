#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define umap unordered_map
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define len(x) (int) (x).size()
#define LSB(x) ((x) & -(x))
inline int MSB(int x) { return x ? 1 << (31 - __builtin_clz(x)) : 0; }
#define fi first
#define se second

struct FT {
    vector<ll> tree;

    FT(int n) { tree.assign(n + 1, 0); }

    FT(const vector<ll>& a) { build(a); }

    void build(const vector<ll>& a) {
        int n = len(a);
        tree.assign(n + 1, 0);
        forn(i, n) {
            tree[i] += a[i - 1];
            if (i + LSB(i) <= n) {
                tree[i + LSB(i)] += tree[i];
            }
        }
    }

    ll query(int k) {
        ll t = 0;
        for (int i = min(k + 1, len(tree) - 1); i > 0; i -= LSB(i)) {
            t += tree[i];
        }
        return t;
    }

    ll query(int lo, int hi) {
        return query(hi) - query(lo - 1);
    }

    void update(int k, ll d) {
        assert(k >= 0 && k < len(tree) - 1);
        for (int i = k + 1; i < len(tree); i += LSB(i)) {
            tree[i] += d;
        }
    }

    // Finds minimum i such that sum of [0, i] >= sum, or n if sum of [0, n-1] < sum
    int lower_bound(ll sum) {
        if (sum <= 0) return -1;
        int i = 0;
        for (int b = MSB(len(tree)); b > 0; b /= 2) {
            if (sum > tree[i + b]) {
                i += b;
                sum -= tree[i];
            }
        }
        return i;
    }
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
    static constexpr T FLAG = LONG_LONG_MAX; // Flag value for mset to indicate no updates necessary
    ST *l = 0, *r = 0;
    int lo, hi;
    T val = ID;
    T mset = FLAG;
    T madd = 0;

    inline T comb(T x, T y) {
        return x + y;
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

    void set(int i, T x) { set(i, i + 1, x); }
    void set(int L, int R, T x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            mset = x;
            madd = 0;
            // Recalculate aggregate value here
            val = x * (hi - lo);
        } else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = comb(l->val, r->val);
        }
    }

    void add(int i, T d) { add(i, i + 1, d); }
    void add(int L, int R, T d) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (mset != FLAG) mset += d;
            else madd += d;
            // Recalculate aggregate value here
            val += d * (hi - lo);
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
        if (mset != FLAG)
            l->set(lo, hi, mset), r->set(lo, hi, mset), mset = FLAG;
        else if (madd)
            l->add(lo, hi, madd), r->add(lo, hi, madd), madd = 0;
    }
};
char ST::buf[450 << 20];

const int MAXN = 5e5;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int q; cin >> q;
    ST st(MAXN);
    FT ft(MAXN);
    int cid = 0;
    umap<string, int> ids;
    umap<string, ll> times;
    ll total = 0;
    forn(_, q) {
        string t; cin >> t;
        if (t == "L") {
            string name; cin >> name;
            ll l; cin >> l;
            auto it = ids.find(name);
            if (it != ids.end()) {
                total -= l;
                int id = it->se;
                ft.update(id, -l);
                times[name] = st.query(id);
                ids.erase(it);
            } else {
                total += l;
                ft.update(cid, l);
                auto it = times.find(name);
                if (it != times.end()) st.add(cid, it->se);
                ids[name] = cid++;
            }
        } else if (t == "P") {
            ll l; cin >> l;
            ll v = l / total;
            ll r = l % total;
            int i = ft.lower_bound(total - r) + 1;
            st.add(0, cid, v);
            st.add(i, cid, 1);
        } else {
            string name; cin >> name;
            auto it = ids.find(name);
            if (it != ids.end()) cout << st.query(it->se) << "\n";
            else {
                auto it = times.find(name);
                cout << (it != times.end() ? it->se : 0) << "\n";
            }
        }
    }
}
