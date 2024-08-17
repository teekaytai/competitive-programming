#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define rforn(i, n) for (int i = (n) - 1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vi x(n);
    vi y(n);
    vi p(n);
    forn(i, n) cin >> x[i];
    forn(i, n) cin >> y[i];
    iota(all(p), -1);
    ll t = 0;
    forn(i, n) {
        int j = i - 1;
        while (y[i] && j >= 0) {
            int m = min(x[j], y[i]);
            y[i] -= m;
            x[j] -= m;
            t += m;
            if (x[j] == 0) j = p[j];
        }
        p[i] = j;
    }
    forn(i, n) t -= max(y[i] - x[i], 0);
    cout << t << "\n";
}
