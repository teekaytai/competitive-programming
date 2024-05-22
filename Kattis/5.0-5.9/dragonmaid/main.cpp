#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forn1(i, n) for (int i = 1; i <= (n); ++i)
#define all(x) x.begin(), x.end()
#define len(x) (int) x.size()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

template <typename T>
inline void print(const vector<T>& v) {
    for (auto x : v) cout << x << " ";
    cout << "\n";
}

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vector<pair<int, ll>> a;
    forn1(i, n) {
        int p, v; cin >> p >> v;
        a.eb(v, i - p * 1000000ll);
    }
    sort(all(a));
    int q; cin >> q;
    vector<tuple<int, int, int>> b;
    forn(i, q) {
        int x, k; cin >> x >> k;
        b.eb(x, k, i);
    }
    sort(all(b));
    vvi ans(q);
    set<ll> pq;
    int curr = 0;
    for (auto [x, k, i] : b) {
        while (curr < n && a[curr].fi <= x) {
            pq.insert(a[curr++].se);
            if (len(pq) > 10) pq.erase(prev(pq.end()));
        }
        if (pq.empty()) ans[i].pb(-1);
        else {
            auto it = pq.begin();
            forn(_, k) {
                ans[i].pb(int(*it % 1000000 + 1000000));
                if (++it == pq.end()) break;
            }
        }
    }
    for (auto& v : ans) print(v);
}
