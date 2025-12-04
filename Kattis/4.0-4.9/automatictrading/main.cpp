#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define rforn1(i, n) for (int i = (n); i > 0; --i)
#define len(x) int(size(x))

template< typename T >
struct SuffixArray : vector< int > {
private:
  vector< int > sa_is(const vector< int > &s) const {
    const int n = (int) s.size();
    vector< int > ret(n);

    vector< int > is_s(n), is_lms(n);
    int m = 0;
    for(int i = n - 2; i >= 0; i--) {
      is_s[i] = (s[i] > s[i + 1]) or (s[i] == s[i + 1] and is_s[i + 1]);
      m += (is_lms[i + 1] = is_s[i] and not is_s[i + 1]);
    }

    auto induced_sort = [&](const vector< int > &lms) {
      int upper = *max_element(s.begin(), s.end());
      vector< int > l(upper + 2), r(upper + 2);
      for(auto &&v: s) {
        ++l[v + 1];
        ++r[v];
      }
      partial_sum(l.begin(), l.end(), l.begin());
      partial_sum(r.begin(), r.end(), r.begin());
      fill(ret.begin(), ret.end(), -1);
      for(int i = (int) lms.size() - 1; i >= 0; i--) {
        ret[--r[s[lms[i]]]] = lms[i];
      }
      for(auto &&v: ret) {
        if(v >= 1 and is_s[v - 1]) ret[l[s[v - 1]]++] = v - 1;
      }
      fill(r.begin(), r.end(), 0);
      for(auto &&v: s) ++r[v];
      partial_sum(r.begin(), r.end(), r.begin());
      for(int k = (int) ret.size() - 1, i = ret[k]; k >= 1; i = ret[--k]) {
        if(i >= 1 and not is_s[i - 1]) {
          ret[--r[s[i - 1]]] = i - 1;
        }
      }
    };

    vector< int > lms;
    lms.reserve(m);
    for(int i = 1; i < n; i++) {
      if(is_lms[i]) lms.push_back(i);
    }

    induced_sort(lms);

    vector< int > new_lms;
    new_lms.reserve(m);
    for(int i = 0; i < n; i++) {
      if(not is_s[ret[i]] and ret[i] > 0 and is_s[ret[i] - 1]) {
        new_lms.push_back(ret[i]);
      }
    }

    auto is_same = [&](int a, int b) {
      if(s[a++] != s[b++]) return false;
      for(;; ++a, ++b) {
        if(s[a] != s[b]) return false;
        if(is_lms[a] or is_lms[b]) return is_lms[a] and is_lms[b];
      }
    };

    int rank = 0;
    ret[n - 1] = 0;
    for(int i = 1; i < m; i++) {
      if(not is_same(new_lms[i - 1], new_lms[i])) ++rank;
      ret[new_lms[i]] = rank;
    }

    if(rank + 1 < m) {
      vector< int > new_s(m);
      for(int i = 0; i < m; i++) {
        new_s[i] = ret[lms[i]];
      }
      auto lms_sa = sa_is(new_s);
      for(int i = 0; i < m; i++) {
        new_lms[i] = lms[lms_sa[i]];
      }
    }

    induced_sort(new_lms);

    return ret;
  }

public:
  T vs;

  explicit SuffixArray(const T &vs, bool compress = false) : vs(vs) {
    vector< int > new_vs(vs.size() + 1);
    if(compress) {
      T xs = vs;
      sort(xs.begin(), xs.end());
      xs.erase(unique(xs.begin(), xs.end()), xs.end());
      for(int i = 0; i < (int) vs.size(); i++) {
        new_vs[i] = (int) (std::lower_bound(xs.begin(), xs.end(), vs[i]) - xs.begin() + 1);
      }
    } else {
      auto d = *min_element(vs.begin(), vs.end());
      for(int i = 0; i < (int) vs.size(); i++) {
        new_vs[i] = vs[i] - d + 1;
      }
      // auto d = *min_element(vs.begin(), vs.end());
      // for(int i = 0; i < (int) vs.size(); i++) {
      //   new_vs[i] = vs[i];
      // }
    }
    auto ret = sa_is(new_vs);
    assign(ret.begin(), ret.end());
  }
};

template< typename T >
vector< int > lcp_array(const SuffixArray< T > &sa) {
  int n = (int) sa.size() - 1;
  vector< int > lcp(n + 1), rank(n + 1);
  for(int i = 0; i <= n; i++) {
    rank[sa[i]] = i;
  }
  int h = 0;
  for(int i = 0; i <= n; i++) {
    if(rank[i] < n) {
      int j = sa[rank[i] + 1];
      for(; j + h < n && i + h < n; h++) {
        if(sa.vs[j + h] != sa.vs[i + h]) break;
      }
      lcp[rank[i] + 1] = h;
      if(h > 0) h--;
    }
  }
  return lcp;
}

class segtree {
  using S = int;
  const S e = INT_MAX;
  S op(const S& l, const S& r) {return min(l, r);}
  int n,log;
  vector<S> d;
  void update(int k) {d[k] = op(d[2*k], d[2*k+1]);}
public:
  segtree(const vector<S> &init) {
    log=0;
    while (1<<log < len(init)) log++;
    n = 1<<log;
    d.assign(2*n,e);
    forn(i,len(init)) d[n+i]=init[i];
    rforn1(i,n-1) update(i);
  }
  S prod(int l, int r) {
    l+=n;
    r+=n;
    S sl = e, sr = e;
    while (l < r) {
      if (l&1) sl = op(sl, d[l++]);
      if (r&1) sr = op(d[--r], sr);
      l>>=1,r>>=1;
    }
    return op(sl,sr);
  }
};

void solve() {
    string s; cin >> s;
    SuffixArray sa(s);
    vector<int> ra(len(sa));
    for (int i = 0; i < len(sa); ++i) {
        ra[sa[i]] = i;
    }
    vi lcp = lcp_array(sa);
    segtree st(lcp);
    int q; cin >> q;
    forn(_, q) {
        int i, j; cin >> i >> j;
        i = ra[i];
        j = ra[j];
        if (i > j) swap(i, j);
        cout << st.prod(i + 1, j + 1) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();
}
