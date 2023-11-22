#include <bits/stdc++.h>

using namespace std;

vector<int> adj_list[100001];
int perm[100001];
vector<tuple<int, int, int>> queries[100001];
bool answers[1000001];
bool seen[1000001] {false};

set<int>* dfs(int x) {
    seen[x] = true;
    vector<set<int>*> sets;
    int m = 0;
    set<int>* ans = nullptr;
    for (int adj : adj_list[x]) {
        if (seen[adj]) {
            continue;
        }
        set<int>* res = dfs(adj);
        sets.push_back(res);
        if (res->size() > m) {
            ans = res;
            m = res->size();
        }
    }
    if (ans == nullptr) {
        ans = new set<int>();
    } else {
        for (auto s : sets) {
            if (s == ans) {
                continue;
            }
            for (int n : *s) {
                ans->insert(n);
            }
        }
    }
    ans->insert(perm[x]);
    for (auto& [u, v, i] : queries[x]) {
        auto it = ans->lower_bound(u);
        answers[i] = it != ans->end() && *it <= v;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        for (int i = 0; i < n - 1; ++i) {
            int u, v; cin >> u >> v;
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        for (int i = 1; i <= n; ++i) {
            int p; cin >> p;
            perm[p] = i;
        }
        for (int i = 0; i < q; ++i) {
            int l, r, x; cin >> l >> r >> x;
            queries[x].emplace_back(l, r, i);
        }
        dfs(1);

        for (int i = 1; i <= n; ++i) {
            adj_list[i].clear();
            queries[i].clear();
            seen[i] = false;
        }
        for (int i = 0; i < q; ++i) {
            cout << (answers[i] ? "YES" : "NO") << "\n";
        }
        cout << "\n";
    }
    return 0;
}
