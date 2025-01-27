#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define umap unordered_map
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define len(x) (int) (x).size()

static char buf[450 << 20];
void* operator new(size_t s) {
    static size_t i = sizeof buf;
    assert(s < i);
    return (void*) &buf[i -= s];
}
void operator delete(void*) {}
void operator delete(void*, size_t) {}

struct ST {
    typedef ll T;
    static constexpr T ID = 0; // Identity value
    static constexpr T FLAG = LONG_LONG_MAX; // Flag value for mset to indicate no updates necessary
    ST *l = 0, *r = 0;
    ll lo, hi;
    T val = ID;
    T mset = FLAG;
    T madd = 0;

    inline T comb(T x, T y) {
        return x + y;
    }

    ST(ll hi) : ST(0, hi) {}

    // Half-open interval [lo, hi) filled with ID
    ST(ll lo, ll hi): lo(lo), hi(hi) {}

    ST(vector<T>& A) : ST(A, 0, len(A)) {}
    ST(vector<T>& A, ll lo, ll hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            ll mid = lo + (hi - lo) / 2;
            l = new ST(A, lo, mid);
            r = new ST(A, mid, hi);
            val = comb(l->val, r->val);
        } else val = A[lo];
    }

    // Half-open interval [L, R)
    T query(ll L, ll R) {
        if (R <= lo || hi <= L) return ID;
        if (L <= lo && hi <= R) return val;
        push();
        return comb(l->query(L, R), r->query(L, R));
    }

    void set(ll L, ll R, T x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            mset = x;
            madd = 0;
            // Recalculate aggregate value here
            val = x;
        } else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = comb(l->val, r->val);
        }
    }

    void add(ll L, ll R, T d) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (mset != FLAG) mset += d;
            else madd += d;
            // Recalculate aggregate value here
            val += d;
        } else {
            push(), l->add(L, R, d), r->add(L, R, d);
            val = comb(l->val, r->val);
        }
    }

    void push() {
        if (!l) {
            ll mid = lo + (hi - lo) / 2;
            l = new ST(lo, mid); r = new ST(mid, hi);
        }
        if (mset != FLAG)
            l->set(lo, hi, mset), r->set(lo, hi, mset), mset = FLAG;
        else if (madd)
            l->add(lo, hi, madd), r->add(lo, hi, madd), madd = 0;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q; cin >> n >> q;
    forn(_, n) {
        string name; cin >> name;
    }
    ST st(-1e14 - 1ll, 1e14 + 2ll);
    st.set(0, 1, n);
    umap<string, ll> m;
    forn(_, q) {
        string p; cin >> p;
        if (p == "!") {
            int k; cin >> k;
            forn(_, k) {
                string name; cin >> name;
                ll d; cin >> d;
                auto& v = m[name];
                st.add(v, v + 1, -1);
                v += d;
                st.add(v, v + 1, 1);
            }
        } else {
            string name; cin >> name;
            ll v = m[name];
            cout << st.query(-1e14 - 1ll, v) + 1 << " " << v << "\n";
        }
    }
}
