#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forn1(i, n) for (int i = 1; i <= (n); ++i)
#define rforn1(i, n) for (int i = (n); i > 0; --i)
#define len(x) int(size(x))

const int INF = 1e9;
int K = -1;

class ST {
  using S = array<array<int, 5>, 5>;
  const S e = {{
    {0, INF, INF, INF, INF},
    {INF, 0, INF, INF, INF},
    {INF, INF, 0, INF, INF},
    {INF, INF, INF, 0, INF},
    {INF, INF, INF, INF, 0},
  }};
  S op(const S& l, const S& r) {
    S s;
    forn (i, K) {
      forn(j, K) {
        int mn = INF;
        forn(k, K) {
          mn = min(mn, l[i][k] + r[k][j]);
        }
        s[i][j] = mn;
      }
    }
    return s;
  }
  int n,log;
  vector<S> d;
  void update(int k) {d[k] = op(d[2*k], d[2*k+1]);}

public:
  ST(const vector<S> &init) {
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
    int n, m, o; cin >> K >> n >> m >> o;
    vector<array<array<int, 5>, 5>> a((n + K - 1) / K - 1, {{
      {INF, INF, INF, INF, INF},
      {INF, INF, INF, INF, INF},
      {INF, INF, INF, INF, INF},
      {INF, INF, INF, INF, INF},
      {INF, INF, INF, INF, INF},
    }});
    forn(i, m) {
      int u, v, w; cin >> u >> v >> w;
      int j = u / K;
      a[j][u % K][v % K] = min(a[j][u % K][v % K], w);
    }
    ST st(a);
    forn(i, o) {
        int s, t; cin >> s >> t;
        if (s / K >= t / K) {
            cout << -1 << "\n";
            continue;
        }
        auto arr = st.prod(s / K, t / K);
        int ans = arr[s % K][t % K];
        cout << (ans < 1e9 ? ans : -1) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();
}
