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

struct FT {
    vector<int> tree;

    FT(int n) { tree.assign(n + 1, 0); }

    int query(int k) {
        int t = 0;
        for (int i = min(k + 1, len(tree)); i > 0; i -= LSB(i)) {
            t += tree[i];
        }
        return t;
    }

    void update(int k, int d) {
        for (int i = k + 1; i < len(tree); i += LSB(i)) {
            tree[i] += d;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    FT ft(10001);
    int t = 0;
    ll s = 0;
    forn1(i, n) {
        int a; cin >> a;
        s += a;
        ft.update(a, 1);
        t += ft.query(int((s + i - 1) / i - 1)) > i / 2;
    }
    cout << t << '\n';
    return 0;
}
