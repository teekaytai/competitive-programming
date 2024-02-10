#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vll;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forn1(i, n) for (int i = 1; i <= (n); ++i)
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<vector<pii>> g;
unordered_map<int, ll> row_mn;
unordered_map<int, ll> col_mn;
unordered_map<int, ll> row_mn2;
unordered_map<int, ll> col_mn2;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, k; cin >> n >> k;
    g.assign(k, vector<pii>());
    forn(r, n) forn(c, n) {
        int x; cin >> x;
        g[x-1].emplace_back(r, c);
        if (x == 1) {
            row_mn[r] = 0;
            col_mn[c] = 0;
        }
    }
    forn(i, k) if (g[i].empty()) {
        cout << -1 << "\n";
        return 0;
    }
    forn1(i, k-1) {
        row_mn2.clear();
        col_mn2.clear();
        for (auto& [r, c] : g[i]) {
            ll d = LONG_LONG_MAX;
            for (auto [R, D] : row_mn) d = min(d, D + (r-R)*(r-R));
            for (auto [C, D] : col_mn) d = min(d, D + (c-C)*(c-C));
            auto it = row_mn2.find(r);
            if (it != row_mn2.end()) it->y = min(it->y, d);
            else row_mn2[r] = d;
            it = col_mn2.find(c);
            if (it != col_mn2.end()) it->y = min(it->y, d);
            else col_mn2[c] = d;
        }
        swap(row_mn, row_mn2);
        swap(col_mn, col_mn2);
    }
    cout << min_element(all(row_mn), [](auto& m1, auto& m2) {return m1.y < m2.y;})->y << "\n";
    return 0;
}
