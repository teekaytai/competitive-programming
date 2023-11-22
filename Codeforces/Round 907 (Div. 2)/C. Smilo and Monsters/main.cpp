#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            a.push_back(x);
        }
        sort(a.begin(), a.end());
        int lo = 0;
        int hi = n - 1;
        long long total = 0;
        int c = 0;
        while (lo <= hi) {
            if (lo == hi) {
                total += a[lo] == 1 ? 1 : (a[lo] - c + 1) / 2 + 1;
                break;
            }
            int m = min(a[hi] - c, a[lo]);
            a[lo] -= m;
            total += m;
            c += m;
            if (a[hi] == c) {
                a[hi] = 0;
                c = 0;
                ++total;
                --hi;
            }
            if (a[lo] == 0) {
                ++lo;
            }
        }
        cout << total << "\n";
    }
    return 0;
}
