#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, t, k; cin >> n >> t >> k;
    vi c(t);
    forn(i, n) {
        int x; cin >> x;
        ++c[x - 1];
    }
    vll a(t);
    vll b(t);
    forn(i, t) {
        int x, y; cin >> x >> y;
        a[i] = (ll) max(2 - c[i], 0) * x;
        b[i] = (ll) c[i] * y;
    }
    vi order(t);
    iota(all(order), 0);
    sort(all(order), [&](int i1, int i2) {
        return (a[i1] + b[i1]) < (a[i2] + b[i2]);
    });
    ll total = 0;
    forn (i, k) {
        total -= a[order[i]];
    }
    for (int i = k; i < t; ++i) {
        total += b[order[i]];
    }
    cout << total << "\n";
}
