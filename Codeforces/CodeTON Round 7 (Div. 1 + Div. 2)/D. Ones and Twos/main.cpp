#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define len(x) (int) x.size()

int a[100000];
set<int> ones;

string yes(bool b) {
    return b ? "YES" : "NO";
}

void solve() {
    int n, q; cin >> n >> q;
    bool odd = false;
    int total = 0;
    ones.clear();
    forn (i, n) {
        cin >> a[i];
        total += a[i];
        if (a[i] == 1) {
            ones.insert(i);
            odd = !odd;
        }
    }
    forn (_, q) {
        int op; cin >> op;
        if (op == 1) {
            int s; cin >> s;
            if (odd == (s % 2 == 1)) {
                cout << yes(s <= total) << "\n";
            } else if (ones.empty()) {
                cout << yes(s % 2 == 0 && s <= total) << "\n";
            } else {
                cout << yes(s <= total - 1 - 2 * min(*ones.begin(), n - *ones.rbegin() - 1)) << "\n";
            }
        } else {
            int i, v; cin >> i >> v;
            --i;
            if (a[i] == v) continue;
            a[i] = v;
            odd = !odd;
            if (v == 1) {
                --total;
                ones.insert(i);
            } else {
                ++total;
                ones.erase(i);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
