#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> nums;
        int total = 0;
        int run = 0;
        int solos = 0;
        int dups = 0;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            nums.push_back(x);
        }
        int lo = 0;
        int hi = n - 1;
        while (lo < n && nums[lo] == 1) {
            ++lo;
        }
        while (hi > lo && nums[hi] == 1) {
            --hi;
        }
        solos += lo + (n - hi - 1);
        if (lo == n) {
            cout << (n - 1 - max(k - 1, 0)) << "\n";
            continue;
        }
        vector<int> one_runs;
        for (int i = lo + 1; i <= hi; ++i) {
            if (nums[i] == 1) {
                dups += run / 2;
                solos += run % 2;
                run = 0;
                int l = 0;
                while (nums[i] == 1) {
                    ++l;
                    ++i;
                }
                one_runs.push_back(l);
            } else if (gcd(nums[i], nums[i - 1]) != 1) {
                ++total;
                dups += run / 2;
                solos += run % 2;
                run = 0;
            } else {
                ++run;
            }
        }
        dups += run / 2;
        solos += run % 2;
        sort(one_runs.begin(), one_runs.end(), greater<>());
        int m = min(dups, k);
        total += 2 * m;
        k -= m;
        while (k > 0 && !one_runs.empty()) {
            int r = one_runs.back();
            one_runs.pop_back();
            if (k >= r) {
                ++total;
            }
            m = min(k, r);
            total += m;
            k -= m;
        }
        total += min(k, solos);
        cout << (n - 1 - total) << "\n";
    }
    return 0;
}
