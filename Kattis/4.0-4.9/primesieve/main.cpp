#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); ++i)

const int N = 100000001;
bitset<N> isp;
void init() {
    isp.set();
    isp.reset(0);
    isp.reset(1);
    forn (i, N) if (isp.test(i)) {
        if (i * i > N) break;
        for (int j = i * 2; j < N; j += i) {
            isp.reset(j);
        }
    }
}

void solve() {
    int n, q; cin >> n >> q;
    int t = 0;
    forn (i, n + 1) t += isp[i];
    cout << t << "\n";
    forn (_, q) {
        int x; cin >> x;
        cout << isp[x] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    init();
    solve();
}
