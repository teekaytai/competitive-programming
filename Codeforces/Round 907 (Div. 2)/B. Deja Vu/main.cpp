#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        vector<int> A;
        for (int i = 0; i < n; ++i) {
            int a; cin >> a;
            A.push_back(a);
        }
        int m = 0;
        for (int i = 0; i < q; ++i) {
            int x; cin >> x;
            int b = 1 << (x - 1);
            if (m % b == 0) {
                m |= b;
            }
        }
        for (int a : A) {
            cout << (a | (m % (a & -a))) << " ";
        }
        cout << "\n";
    }
    return 0;
}
