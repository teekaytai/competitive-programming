#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define all(x) x.begin(), x.end()
#define len(x) (int) x.size()
#define pb push_back

vi D;
int P[7];
int t = 0;

void f(int n, int k) {
    if (k >= len(D)) {
        if (n != 0) return;
        int r = 1;
        int x = 1;
        int ld = 0, lp = 0;
        int cd = -1, cp = -1;
        forn(i, len(D)) {
            if (D[i] != cd) {
                r *= x;
                x = 1;
                ld = lp = 1;
                cd = D[i];
                cp = P[i];
            } else {
                ++ld;
                x *= ld;
                if (P[i] == cp) {
                    ++lp;
                    x /= lp;
                } else {
                    lp = 1;
                    cp = P[i];
                }
            }
        }
        t += r * x;
        return;
    }
    int d = D[k];
    int c = k > 0 && d == D[k-1] ? P[k-1] : 1;
    while (c <= n) {
        P[k] = c;
        f(n - c, k + 1);
        c *= d;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string s; cin >> s;
    int n = stoi(s);
    for (auto d : s) D.pb(d - '0');
    sort(all(D));
    f(n, 0);
    cout << t << "\n";
}
