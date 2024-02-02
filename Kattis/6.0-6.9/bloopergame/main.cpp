#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forn1(i, n) for (int i = 1; i <= (n); ++i)
#define rforn(i, n) for (int i = (n) - 1; i >= 0; --i)
#define rforn1(i, n) for (int i = (n); i > 0; --i)
#define all(x) x.begin(), x.end()
#define len(x) (int) x.size()
#define LSB(x) ((x) & -(x))
#define pb push_back
#define x first
#define y second

const int INF = 1e9;
const int MAXN = 1e5;

double a[MAXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, l;
    double p;
    cin >> n >> l >> p;
    double hi = 0;
    forn(i, n) {
        cin >> a[i];
        hi = max(hi, a[i]);
    }
    double lo = 1;
    forn (_, 100) {
        double mid = (lo + hi) / 2;
        double c = 0;
        forn(i, n) if (a[i] > mid) {
            c += ceil(log(log(mid) / log(a[i])) / log(p));
        }
        if (c == l) {
            break;
        } else if (c > l) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    forn(i, n) if (a[i] > hi) {
        int r = (int) ceil(log(log(hi) / log(a[i])) / log(p));
        a[i] = pow(a[i], pow(p, r));
        l -= r;
    }
    priority_queue<double> pq(a, a + n);
    while (l) {
        double v = pq.top();
        if (v < 1.000000000001) break;
        pq.pop();
        pq.push(pow(v, p));
        l -= 1;
    }
    double res = 1;
    while (!pq.empty()) {
        res /= pq.top();
        pq.pop();
    }
    cout << fixed << setprecision(7) << res << "\n";
    return 0;
}
