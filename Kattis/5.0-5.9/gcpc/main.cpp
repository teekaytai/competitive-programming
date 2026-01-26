#include <bits/stdc++.h>
using namespace std;

typedef array<int, 3> a3i;
typedef vector<int> vi;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define len(x) int(size(x))

#include <bits/extc++.h>
using namespace __gnu_pbds;
template<class T>
using OST = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n, m; cin >> n >> m;
    vi a(n, 0);
    vi b(n, 0);
    OST<a3i> ost;
    forn(i, m) {
        int t, p; cin >> t >> p;
        --t;
        if (a[t] > 0) {
            ost.erase({a[t], b[t], t});
        }
        ++a[t];
        b[t] -= p;
        ost.insert({a[t], b[t], t});
        cout << len(ost) - ost.order_of_key({a[0], b[0] + 1, -1}) + 1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();
}
