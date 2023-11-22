#include <bits/stdc++.h>

using namespace std;

int nums[150000];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        long long best = 0;
        for (int i = 1; i < n; ++i) {
            if (n % i != 0) {
                continue;
            }
            long long min_sum = LONG_LONG_MAX;
            long long max_sum = LONG_LONG_MIN;
            for (int j = 0; j < n; j += i) {
                long long sum = 0;
                for (int k = j; k < j + i; ++k) {
                    sum += nums[k];
                }
                min_sum = min(min_sum, sum);
                max_sum = max(max_sum, sum);
            }
            best = max(best, max_sum - min_sum);
        }
        cout << best << '\n';
    }
    return 0;
}
