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
const int MAXN = 3e5;

struct FT {
    vector<ll> vals;

    FT(int n) { vals.assign(n + 1, 0); }

    ll query(int idx) {
        ll total = 0;
        for (int i = idx + 1; i > 0; i -= LSB(i)) {
            total += vals[i];
        }
        return total;
    }

    void update(int idx, ll d) {
        for (int i = idx + 1; i < len(vals); i += LSB(i)) {
            vals[i] += d;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q; cin >> n >> q;
    FT ft = FT(n);
    forn (_, q) {
        char op; cin >> op;
        if (op == '+') {
            int i, d; cin >> i >> d;
            ft.update(i, d);
        } else {
            int i; cin >> i;
            cout << ft.query(i - 1) << "\n";
        }
    }
    return 0;
}
