#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        int min_num = INT_MAX;
        int min_idx = -1;
        int prev;
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            int num; cin >> num;
            if (num < min_num) {
                min_num = num;
                min_idx = i;
                flag = true;
            } else if (i > 0 && num < prev) {
                flag = false;
            }
            prev = num;
        }
        cout << (flag ? min_idx : -1) << "\n";
    }
    return 0;
}
