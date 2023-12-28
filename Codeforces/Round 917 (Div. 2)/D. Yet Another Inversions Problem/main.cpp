#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define all(x) x.begin(), x.end()
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define len(x) (int) x.size()
const int INF = 1e9;
const int MOD = 998244353;
int p[200000];
int q[200000];

struct BIT {
    vector<int> bit;
    int n;
    BIT(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    int sum(int r) {
        int t = 0;
        ++r;
        r = min(r, n - 1);
        while (r) {
            t += bit[r];
            r -= r & -r;
        }
        return t;
    }

    int sum(int lo, int hi) {
        return sum(hi) - sum(lo - 1);
    }

    void inc(int r) {
        ++r;
        while (r < n) {
            ++bit[r];
            r += r & -r;
        }
    }
};

void solve() {
    int n, k; cin >> n >> k;
    BIT bp = BIT(2 * n);
    BIT bq = BIT(k);
    forn (i, n) {
        cin >> p[i];
    }
    ll inv = (ll) k * (k - 1) / 2;
    forn (i, k) {
        cin >> q[i];
        inv -= bq.sum(q[i]);
        bq.inc(q[i]);
    }
    inv %= MOD;
    ll t = inv * n % MOD;
    for (int j = 0; j < n; ++j) {
        int x = p[j];
        int a = x;
        int b = a >> 1;
        for (int i = 0; i < k; ++i) {
            t += (ll) bp.sum(b + 1, a) * (k-i) * (k-i-1)/2;
            t %= MOD;
            a>>=1;
            if (!b) break;
            b >>=1;
        }
        a=x<<1;
        b=x;
        for (int i = 0; i < k; ++i) {
            t += (ll) bp.sum(b, a) * ((ll)k*k-(ll) (k-i) *(k-i-1)/2);
            t %= MOD;
            a<<=1;
            b<<=1;
            if (b >= 2*n) break;
        }
        t += (ll) bp.sum(b, 2*n) * k * k;
        t %= MOD;
        bp.inc(x);
    }
    cout << t << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
