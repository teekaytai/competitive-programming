#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[6][50] {0};
    int b[6][50] {0};

    long long total = 0;
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        string x; cin >> x;
        int t = 0;
        for (char d : x) {
            t += d - '0';
        }
        int p = t;
        int s = t;
        int S = x.size() - 2;
        for (int j = 0; S > 0; ++j, S -= 2) {
            p -= (x[x.size() - j - 1] - '0') * 2;
            s -= (x[j] - '0') * 2;
            ++a[S][p];
            ++a[S][s];
            total += b[S][p];
            total += b[S][s];
        }
        total += a[x.size()][t] + 1;
        a[x.size()][t] += 2;
        ++b[x.size()][t];
    }
    cout << total;
    return 0;
}
