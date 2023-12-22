#include <bits/stdc++.h>
using namespace std;

deque<pair<int, int>> dq;
set<pair<int, int>> card_counts;
unordered_map<int, set<pair<int, int>>::iterator> nodes;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        string op; cin >> op;
        if (op[0] == 'P') {
            int cnt, x; cin >> cnt >> x;
            if (op[4] == 'T') {
                if (!dq.empty() && dq.front().first == x) dq.front().second += cnt;
                else dq.emplace_front(x, cnt);
            } else {
                if (!dq.empty() && dq.back().first == x) dq.back().second += cnt;
                else dq.emplace_back(x, cnt);
            }
            auto it = nodes.find(x);
            if (it != nodes.end()) {
                cnt += it->second->first;
                card_counts.erase(it->second);
            }
            nodes[x] = card_counts.emplace(cnt, -x).first;
        } else {
            int cnt; cin >> cnt;
            while (cnt) {
                int x, c;
                if (op[7] == 'T') {
                    pair<int, int>& p = dq.front();
                    x = p.first;
                    c = p.second;
                    if (c <= cnt) dq.pop_front();
                    else dq.front().second -= cnt;
                } else {
                    pair<int, int>& p = dq.back();
                    x = p.first;
                    c = p.second;
                    if (c <= cnt) dq.pop_back();
                    else dq.back().second -= cnt;
                }
                c = min(c, cnt);
                cnt -= c;
                auto it = nodes.find(x);
                c = it->second->first - c;
                card_counts.erase(it->second);
                nodes[x] = card_counts.emplace(c, -x).first;
            }
        }
        cout << -card_counts.rbegin()->second << "\n";
    }

    return 0;
}
