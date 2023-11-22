#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define forn(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        if (k < n + m - 2 || (k + m + n) % 2 != 0) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        char c = n % 2 == 0 ? 'R' : 'B';
        forn(i, n - 1) {
            forn(j, m - 1) {
                cout << c << " ";
            }
            cout << "\n";
        }
        if (n % 2 == 0) {
            for (int i = 2; i < m; i += 2) {
                cout << "R B ";
            }
            if (m % 2 == 0) {
                cout << "R";
            }
        } else {
            for (int i = 2; i < m; i += 2) {
                cout << "B R ";
            }
            if (m % 2 == 0) {
                cout << "B";
            }
        }
        cout << "\n";
        char C = 'B';
        c = c == 'R' ? 'B' : 'R';
        forn(i, n - 1) {
            cout << C;
            C = C == 'B' ? 'R' : 'B';
            forn(j, m - 1) {
              cout << " " << c;
            }
            cout << "\n";
        }
    }
    return 0;
}
