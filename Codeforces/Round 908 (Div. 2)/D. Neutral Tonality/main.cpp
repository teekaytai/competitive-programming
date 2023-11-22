#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }
        sort(b.begin(), b.end(), greater<>());
        int j = 0;
        for (int i = 0; i < n; ++i) {
            while (j < m && b[j] >= a[i]) {
                cout << b[j++] << " ";
            }
            cout << a[i] << " ";
        }
        while (j < m) {
            cout << b[j++] << " ";
        }
        cout << "\n";
    }
    return 0;
}
