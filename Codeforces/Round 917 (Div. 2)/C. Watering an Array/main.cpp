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
int a[2000];
int v[100000];

void solve() {
    int n, k, d; cin >> n >> k >> d;
    int c = 0;
    int lo = 0;
    forn(i,n) {
        cin>>a[i];
        a[i] -= i + 1;
        c += a[i] == 0;
    }
    while (lo < n &&a[lo] > 0) {
        ++lo;
    }
    int mx = c + (d - 1)/2;
    forn(i,k) {
        cin >> v[i];
    }
    forn (i, d - 1) {
        for (int j = lo; j < v[i % k]; ++j) {
            if (++a[j] == 0) {
                ++c;
            } else if (a[j] == 1) {
                --c;
            }
        }
        mx = max(mx, c + (d - i - 2)/2);
        while (lo < n && a[lo] > 0) {
            ++lo;
        }
        if (lo >= n || n - lo + (d-i-2)/2 < mx) break;
    }
    cout << mx << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
