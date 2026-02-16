#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forn1(i, n) for (int i = 1; i <= (n); ++i)
#define len(x) int(size(x))
template<class T> constexpr void cmin(T& a, T b) { a = min(a, b); }
#define pb push_back
#define eb emplace_back

void solve() {
    int n, t; cin >> n >> t;
    vpii e;
    e.eb(1, 1);
    vi I = {1};
    forn1(i, n) {
        int s, w; cin >> s >> w;
        if ((s > 0 && w < s) || (s < 0 && w < t)) {
            e.eb(s, w);
            I.pb(i + 1);
        }
    }
    n = len(e);
    int t3 = t * 3;
    vvi pq(t);
    pq[0].pb(t);
    vi ds(t3 + 1, t);
    iota(ds.begin() + t, ds.begin() + (2 * t), 0);
    vi ps(t3 + 1, 0);
    ps[t] = -1;
    pii best = {t, t};
    for (int d = 0; 2 * d < best.first; ++d) {
        for (int u : pq[d]) {
            if (ds[u] != d) continue;
            forn (i, n) {
                auto [s, w] = e[i];
                int v = u + s;
                if (v < 0 || v >= t3) continue;
                int d2 = d + w;
                if (d2 >= ds[v]) continue;
                ds[v] = d2;
                ps[v] = i;
                pq[d2].pb(v);
                cmin(best, {ds[v] + ds[t3 - v], v});
            }
        }
    }
    vi ans;
    int c = best.second;
    while (c != t) {
        ans.pb(I[ps[c]]);
        c -= e[ps[c]].first;
    }
    c = t3 - best.second;
    while (c != t) {
        ans.pb(I[ps[c]]);
        c -= e[ps[c]].first;
    }
    cout << len(ans) << "\n";
    for (int x : ans) cout << x << " ";
    cout << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();
}
