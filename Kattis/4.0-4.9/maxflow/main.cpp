#include <bits/stdc++.h>
using namespace std;

int n, m, s, t;
vector<vector<int>> adj;
vector<vector<int>> cap;
vector<vector<int>> flows;

int bfs(vector<int>& parents) {
    fill(parents.begin(), parents.end(), -1);
    parents[s] = -2;
    queue<pair<int, int>> q;
    q.emplace(s, INT_MAX);
    while (!q.empty()) {
        auto [u, f] = q.front();
        q.pop();
        for (int v : adj[u]) {
            int residual = cap[u][v] - flows[u][v] + flows[v][u];
            if (parents[v] == -1 && residual) {
                parents[v] = u;
                int f2 = min(f, residual);
                if (v == t) return f2;
                q.emplace(v, f2);
            }
        }
    }
    return 0;
}

int EK() {
    int total_flow = 0;
    vector<int> parents(n);
    int f;
    while (f = bfs(parents)) {
        total_flow += f;
        int curr = t;
        while (curr != s) {
            int prev = parents[curr];
            int df = min(f, flows[curr][prev]);
            flows[curr][prev] -= df;
            flows[prev][curr] += f - df;
            curr = prev;
        }
    }
    return total_flow;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m >> s >> t;
    adj.assign(n, vector<int>());
    cap.assign(n, vector<int>(n, 0));
    flows.assign(n, vector<int>(n, 0));
    for (int i = 0 ; i < m; ++i) {
        int u, v, c; cin >> u >> v >> c;
        if (cap[v][u] == 0) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cap[u][v] = c;
    }

    int f = EK();
    vector<tuple<int, int, int>> used_flows;
    for (int u = 0; u < n; ++u) {
        for (int v : adj[u]) {
            if (flows[u][v]) {
                used_flows.emplace_back(u, v, flows[u][v]);
            }
        }
    }
    cout << n << " " << f << " " << used_flows.size() << "\n";
    for (auto [u, v, x] : used_flows) {
        cout << u << " " << v << " " << x << "\n";
    }

    return 0;
}
