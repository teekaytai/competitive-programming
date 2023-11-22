#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define forn(i, n) for (int i = 0; i < (n); ++i)

void solve() {
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    queue<int> p[26];
    int i = 0;
    for (char c : t) {
        int idx = c - 'a';
        if (!p[idx].empty()) {
            int r = p[idx].front();
            p[idx].pop();
            for (int j = 0; j < idx; ++j) {
                while (!p[j].empty() && p[j].front() < r) {
                    p[j].pop();
                }
            }
            continue;
        }
        for (int j = 0; j < idx; ++j) {
            queue<int>().swap(p[j]);
        }
        bool f = false;
        while (!f) {
            if (i == s.size()) {
                cout << "NO\n";
                return;
            }
            if (s[i] == c) {
                f = true;
            } else if (s[i] > c) {
                p[s[i] - 'a'].push(i);
            }
            ++i;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
