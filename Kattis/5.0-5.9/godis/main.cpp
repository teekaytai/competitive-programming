#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forn1(i, n) for (int i = 1; i <= (n); ++i)
#define all(x) (x).begin(), (x).end()
#define LSB(x) ((x) & -(x))

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;

void solve() {
    int n; cin >> n;
    vvi a(n);
    vi curr(n);
    forn(i, n) {
        a[i].assign(10, 0);
        int k; cin >> k;
        forn(j, k) {
            int s, x; cin >> s >> x;
            a[i][abs(s) - 1] = s > 0 ? x : -x;
            curr[i] += s > 0 ? x : -x;
        }
    }
    int best = accumulate(all(curr), 0);
    vector<bool> positive(10, true);
    forn1 (i, 1023) {
        int total = 0;
        int b = __builtin_ctz(LSB(i));
        positive[b] = !positive[b];
        forn(j, n) {
            curr[j] += 2 * (positive[b] ? a[j][b] : -a[j][b]);
            total += max(curr[j], 0);
        }
        best = max(best, total);
    }
    cout << best << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();
}
