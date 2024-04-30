#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); ++i)

const int MAXN = 4100;

bitset<16400> a[MAXN];
int b[4*MAXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m, k; cin >> n >> m >> k;
    forn(i, n) forn(j, m) {
        char c; cin >> c;
        int id = c == 'A' ? 0 : c == 'C' ? 1 : c == 'G' ? 2 : 3;
        a[i].set(4*j + id);
        ++b[4*j + id];
    }
    forn(i, n) {
        int x = 0;
        for (int j = 0; j < 4*m; ++j) {
            if (a[i][j]) x += b[j];
        }
        if (x != n*(m-k)+k) continue;
        bool can = true;
        forn(j, n) if (i != j) {
            if (int((a[i] ^ a[j]).count()) != 2*k) {
                can = false;
                break;
            }
        }
        if (can) {
            cout << i + 1 << "\n";
            break;
        }
    }
}
