#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        int c = 0;
        map<int, int> counts;
        long long total = 0;
        for (int i = 0; i < n; ++i) {
            int num; cin >> num;
            if (num <= 2) {
                total += c++;
            } else {
                total += counts[num]++;
            }
        }
        cout << total << "\n";
    }
    return 0;
}
