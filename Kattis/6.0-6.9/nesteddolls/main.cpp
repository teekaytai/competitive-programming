#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define all(x) begin(x), end(x)

void solve() {
    int n; cin >> n;
    vpii a;
    forn(i, n) {
        int w, h; cin >> w >> h;
        a.emplace_back(w, h);
    }
    sort(all(a));
    int t = n;
    multiset<int> s;
    int lo = 0;
    int hi = 0;
    while (hi < n) {
        while (a[lo].first != a[hi].first) {
            s.insert(a[lo++].second);
        }
        auto it = s.lower_bound(a[hi].second);
        if (it != s.begin()) {
            s.erase(prev(it));
            --t;
        }
        ++hi;
    }
    cout << t << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
