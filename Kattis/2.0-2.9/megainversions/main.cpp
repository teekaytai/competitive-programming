#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forn1(i, n) for (int i = 1; i <= (n); ++i)
#define rforn1(i, n) for (int i = (n); i > 0; --i)
#define len(x) int(size(x))
#define fi first
#define se second

class lazy_segtree {
  using S = pll;
  const S e = {0, 0};
  S op(const S& l, const S& r) {return {l.fi + r.fi, l.se + r.se};}
  using F = pll;
  const F id = {0, 0};
  F compose(const F &g, const F &f) {return {g.fi + f.fi, g.se + f.se};}
  S mapping(const F &f, const S& x) {return {x.fi + f.fi, x.se + f.se};}
  int n,log;
  vector<S> d;
  vector<F> lz;
  void update(int k) {d[k] = op(d[2*k], d[2*k+1]);}
  void all_apply(int k, F f) {
    d[k]=mapping(f,d[k]);
    if (k<n) lz[k] = compose(f,lz[k]);
  }
  void push(int k) {
    all_apply(2*k, lz[k]);
    all_apply(2*k+1, lz[k]);
    lz[k]=id;
  }
public:
  lazy_segtree(const vector<S> &init) {
    log=0;
    while (1<<log < len(init)) log++;
    n = 1<<log;
    d.assign(2*n,e);
    lz.assign(n,id);
    forn(i,len(init)) d[n+i]=init[i];
    rforn1(i,n-1) update(i);
  }
  S prod(int l, int r) {
    l+=n;
    r+=n;
    rforn1(i,log) {
      if ((l>>i) << i!=l) push(l>>i);
      if ((r>>i) << i!=r) push(r>>i);
    }
    S sl = e, sr = e;
    while (l < r) {
      if (l&1) sl = op(sl, d[l++]);
      if (r&1) sr = op(d[--r], sr);
      l>>=1,r>>=1;
    }
    return op(sl,sr);
  }
  void apply(int l, int r, F f) {
    assert(0<=l&&l<=r&&r<=n);
    l+=n,r+=n;
    rforn1(i,log) {
      if ((l>>i)<<i!=l) push(l>>i);
      if ((r>>i)<<i!=r) push(r>>i);
    }
    int l2 = l, r2 = r;
    while (l < r) {
      if (l&1) all_apply(l++, f);
      if (r&1) all_apply(--r, f);
      l>>=1,r>>=1;
    }
    l=l2,r=r2;
    forn1(i,log) {
      if ((l>>i)<<i!=l) update(l>>i);
      if ((r>>i)<<i!=r) update(r>>i);
    }
  }
};

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;
const ll MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<pll> a(n + 1, {0, 0});
    lazy_segtree st(a);
    ll ans = 0;
    forn(i, n) {
        int x; cin >> x;
        auto [s, c] = st.prod(x + 1, n + 1);
        st.apply(x, x + 1, {1, s});
        ans += c;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();
}
