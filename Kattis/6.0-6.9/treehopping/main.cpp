#include <bits/stdc++.h>
using namespace std;

#define uset unordered_set
#define forn(i, n) for (int i = 0; i < (n); ++i)

const int MAXN = 1e5;

vector<uset<int>> g;
int P[MAXN];
int Q[MAXN];

int t;

void dfs(int u, uset<int>& s, int p1 = -1, int p2 = -1, int p3 = -1) {
    t -= P[u] == p2 || P[u] == p3;
    t -= Q[u] == p2 || Q[u] == p3;
    uset<int> S;
    for (int v : g[u]) if (v != p1) {
        dfs(v, S, u, p1, p2);
        s.insert(v);
    }
    for (int v : g[u]) if (v != p1) {
        t -= S.find(P[v]) != S.end() || P[v] != p1 && g[u].find(P[v]) != g[u].end();
        t -= S.find(Q[v]) != S.end();
    }
}

void dfs0(int u = 0) {
    t -= g[u].find(P[u]) != g[u].end();
    t -= g[u].find(Q[u]) != g[u].end();
    uset<int> S;
    for (int v : g[u]) {
        dfs(v, S, u);
    }
    for (int v : g[u]) {
        t -= S.find(P[v]) != S.end() || g[u].find(P[v]) != g[u].end();
        t -= S.find(Q[v]) != S.end();
    }
}

void solve() {
    int n; cin >> n; t = n-1;
    g.assign(n, uset<int>());
    forn(i, n-1) {
        int u, v; cin >> u >> v;
        --u, --v;
        g[u].insert(v);
        g[v].insert(u);
    }
    int prev = -2;
    forn(i, n) {
        int v; cin >> v; --v;
        P[v] = prev;
        if (i != 0) Q[prev] = v;
        prev = v;
    }
    Q[prev] = -2;
    dfs0();
    cout << (t==0) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
