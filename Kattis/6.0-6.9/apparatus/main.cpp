#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define umap unordered_map
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define len(x) (int) (x).size()

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vi x(n, 0), y(n, 0);
    vi c(n, 0);
    forn(_, m) {
        string a, b; cin >> a >> b;
        map<pii, int> m;
        int t = 0;
        forn(i, n) {
            t -= c[x[i]] != 0;
            c[x[i]] += a[i] - '0';
            t += c[x[i]] != 0;
            auto it = m.find({x[i], a[i] - '0'});
            if (it == m.end()) {
                m[{x[i], a[i] - '0'}] = len(m);
            }
            x[i] = m[{x[i], a[i] - '0'}];
            t -= c[y[i]] != 0;
            c[y[i]] -= b[i] - '0';
            t += c[y[i]] != 0;
            it = m.find({y[i], b[i] - '0'});
            if (it == m.end()) {
                m[{y[i], b[i] - '0'}] = len(m);
            }
            y[i] = m[{y[i], b[i] - '0'}];
        }
        if (t != 0) {
            cout << "0\n";
            return 0;
        }
    }
    umap<int, int> ma;
    ll p = 1;
    for (int v : x) p = (p * ++ma[v]) % 1000003;
    cout << p << "\n";
}
