#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define forn(i, n) for (int i = 0; i < (n); ++i)

int bigs[200000];
int smalls[200000];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        forn(i, n) {
            cin >> bigs[i];
        }
        ll T = 0;
        int mx = INT_MIN;
        int mn = INT_MAX;
        forn(i, n) {
            cin >> smalls[i];
            if (smalls[i] > bigs[i]) {
                int temp = smalls[i];
                smalls[i] = bigs[i];
                bigs[i] = temp;
            }
            T += bigs[i] - smalls[i];
            mx = max(mx, smalls[i]);
            mn = min(mn, bigs[i]);
        }
        cout << (T + max(2 * (mx - mn), 0)) << "\n";
    }
    return 0;
}
