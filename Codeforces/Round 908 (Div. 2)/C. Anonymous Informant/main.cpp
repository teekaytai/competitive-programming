#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<vector<int>> adj_list(n);
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        if (a > n) {
            continue;
        }
        int d = (a - 1 - i + n) % n;
        adj_list[(d - a + n) % n].push_back(d);
    }
    vector<int> seen(n, -1);
    queue<int> q;
    q.push(0);
    for (int i = 0; i < k; ++i) {
        if (q.empty()) {
            cout << "No\n";
            return;
        }
        for (int j = q.size(); j > 0; --j) {
            int c = q.front();
            q.pop();
            for (int d : adj_list[c]) {
                if (seen[d] == -1) {
                    seen[d] = i;
                    q.push(d);
                } else if (seen[d] < i) {
                    cout << "Yes\n";
                    return;
                }
            }
        }
    }
    cout << (q.empty() ? "No\n" : "Yes\n");
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
