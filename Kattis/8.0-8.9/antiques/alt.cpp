#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define pb push_back

template <typename... Ts>
inline void print(const Ts&... args) {
    const char* sep = "";
    (((cout << sep << args), sep = " "), ...);
    cout << "\n";
}

int INF = 2e9;
int n, m, k;
pii E[100];
int W[40];
int used[40];
int s[40];
bool must[40];
vvi g;
int best;

void dfs(int k, int c = 0, int i = 0) {
    for (; i < n; ++i) {
        auto [u, v] = E[i];
        if (used[u] >= 0 || used[v] >= 0) continue;
        if (k == 0) return;
        used[u] = i;
        dfs(k-1, c + W[u], i+1);
        used[u] = -1;
        for (int v2 : g[u]) if (used[v2] == -1) {
            used[v2] = i;
            c += W[v2];
            --k;
        }
        if (k >= 0) dfs(k, c, i+1);
        for (int v2 : g[u]) if (used[v2] == i) {
            used[v2] = -1;
        }
        return;
    }
    for (int j = 0; k; ++j) if (used[s[j]] == -1) {
        c += W[s[j]];
        --k;
    }
    best = max(best, c);
}

void dfs2(int k, int c = 0, int u = 0) {
    if (k == 0) {
        best = min(best, c);
        return;
    }
    for (; u < m; ++u) if (used[u] == -1 && !must[u]) {
        for (int v : g[u]) if (used[v] == -1) used[v] = k;
        dfs2(k-1, c + W[u], u+1);
        for (int v : g[u]) if (used[v] == k) used[v] = -1;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m >> k;
    int t = 0;
    int t2 = 0;
    g.assign(m, vi());
    forn(i, n) {
        int a, p, b, q; cin >> a >> p >> b >> q;
        --a; --b;
        t += max(p, q);
        t2 += min(p, q);
        E[i] = make_pair(a, b);
        W[a] += max(q-p, 0);
        W[b] += max(p-q, 0);
        g[a].pb(b);
        g[b].pb(a);
        must[a] |= a==b;
    }
    iota(s, s+m, 0);
    sort(s, s+m, [&](int i, int j) {return W[i] > W[j];});
    memset(used, -1, sizeof(used));
    if (k <= m/2) {
        best = -1;
        dfs(k);
        print(best < 0 ? -1 : t - best);
    } else {
        best = INF;
        dfs2(m-k);
        print(best == INF ? -1 : t2 + best);
    }
}
