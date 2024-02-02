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

template<typename T>
inline T MSB(T x) {
    T b = 1;
    while (b * 2 < x) b *= 2;
    return b;
}

struct FT {
    vector<ll> tree;

    FT(int n) { tree.assign(n + 1, 0); }

    ll query(int k) {
        ll t = 0;
        for (int i = min(k + 1, len(tree) - 1); i > 0; i -= LSB(i)) {
            t += tree[i];
        }
        return t;
    }

    ll query(int lo, int hi) {
        return query(hi) - query(lo - 1);
    }

    void update(int k, ll d) {
        assert(k >= 0);
        for (int i = k + 1; i < len(tree); i += LSB(i)) {
            tree[i] += d;
        }
    }
};

const int INF = 1e9;
const int MAXN = 2e5;

ll a[MAXN];
ll s[MAXN];
ll p[MAXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    forn(i, n) {
        cin >> a[i];
        s[i] = a[i];
    }
    sort(s, s + n);
    FT prefs(n);
    forn(i, n) {
        ll x = a[i];
        p[i] = prefs.query(lower_bound(s, s + n, 2 * x) - s, n);
        prefs.update(lower_bound(s, s + n, x) - s, 1);
        prefs.update(-2, 1);
    }
    ll total = 0;
    FT sufs(n);
    rforn(i, n) {
        ll x = a[i];
        total += p[i] * sufs.query(upper_bound(s, s + n, x / 2) - s - 1);
        sufs.update(lower_bound(s, s + n, x) - s, 1);
    }
    cout << total << "\n";
    return 0;
}
