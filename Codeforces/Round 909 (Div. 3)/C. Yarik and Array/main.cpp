#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        int sum = 0;
        int prev;
        int max_sum = INT_MIN;
        for (int i = 0; i < n; ++i) {
            int num; cin >> num;
            if (i > 0 && (num % 2 == 0) == (prev % 2 == 0)) {
                sum = 0;
            }
            prev = num;
            sum = sum + num;
            max_sum = max(max_sum, sum);
            sum = max(sum, 0);
        }
        cout << max_sum << "\n";
    }
    return 0;
}
