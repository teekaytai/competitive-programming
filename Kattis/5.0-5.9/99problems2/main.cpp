#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    multiset<int> s;
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        int d; cin >> d;
        s.insert(d);
    }
    for (int i = 0; i < q; ++i) {
        int t, d; cin >> t >> d;
        if (t == 1) {
            auto it = s.upper_bound(d);
            if (it != s.end()) {
                cout << *it << "\n";
                s.erase(it);
            } else cout << "-1\n";
        } else {
            auto it = s.upper_bound(d);
            if (it != s.begin()) {
                cout << *--it << "\n";
                s.erase(it);
            } else cout << "-1\n";
        }
    }
}
