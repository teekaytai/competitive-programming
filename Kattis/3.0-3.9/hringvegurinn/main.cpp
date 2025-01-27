#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
    static constexpr T FLAG = -1; // Flag value for mset to indicate no updates necessary
    ST *l = 0, *r = 0;
    int lo, hi;
    T val = ID;
    T mset = FLAG;
    T madd = 0;

    inline T comb(T x, T y) {
        return x + y;
    }

    ST(int hi) : ST(0, hi) {}

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
    T query(int L, int R) {
        if (R <= lo || hi <= L) return ID;
        if (L <= lo && hi <= R) return val;
        push();
        return comb(l->query(L, R), r->query(L, R));
    }

    void set(int L, int R, T x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            mset = x;
            madd = 0;
            val = x * (hi - lo);
        } else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = comb(l->val, r->val);
        }
    }

    void add(int L, int R, T d) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (mset != FLAG) mset += d;
            else madd += d;
            // Recalculate aggregate value here
            val += d * (hi - lo);
        }
        else {
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q; cin >> n >> q;
    int D = 0;
    ST st(n);
    forn (_, q) {
        int p; cin >> p;
        if (p == 1) {
            int d; cin >> d;
            D = (D + d) % n;
        } else if (p == 2) {
            int l, r, d; cin >> l >> r >> d;
            --l; --r;
            l = (l + D) % n;
            r = (r + D) % n;
            if (l <= r) st.add(l, r + 1, d);
            else st.add(l, n, d), st.add(0, r + 1, d);
        } else {
            int l, r; cin >> l >> r;
            --l; --r;
            l = (l + D) % n;
            r = (r + D) % n;
            cout << (l <= r ? st.query(l, r + 1) : st.query(l, n) + st.query(0, r + 1)) << "\n";
        }
    }
}
