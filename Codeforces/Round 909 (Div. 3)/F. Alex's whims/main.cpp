#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        for (int i = 1; i < n; ++i) {
            cout << i << " " << (i + 1) << "\n";
        }
        int curr = n - 1;
        for (int i = 0; i < q; ++i) {
            int num; cin >> num;
            if (curr == num) {
                cout << "-1 -1 -1\n";
            } else {
                cout << n << " " << curr << " " << num << "\n";
                curr = num;
            }
        }
    }
    return 0;
}
