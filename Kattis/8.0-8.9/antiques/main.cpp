#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vll;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define LSB(x) ((x) & -(x))

int INF = 2e9;
int n, m, k;
pii E[100];
int W[40];
int s[40];
bool must[40];
vll g;
int best;

void dfs(int k, ll used = 0, int i = 0) {
    for (; i < n; ++i) {
        auto [u, v] = E[i];
        ll bu = 1ll << u;
        ll bv = 1ll << v;
        if (used & (bu | bv)) continue;
        if (k == 0) return;
        dfs(k-1, used|bu, i+1);
        k -= __builtin_popcountll(g[u] & ~used);
        if (k >= 0) dfs(k, used|g[u], i+1);
        return;
    }
    int c = 0;
    for (int j = 0; k; ++j) if ((used & (1ll << s[j])) == 0) {
        c += W[s[j]];
        --k;
    }
    while (used) {
        ll b = LSB(used);
        used -= b;
        c += W[__builtin_ctzll(b)];
    }
    best = max(best, c);
}

void dfs2(int k, ll used = 0, int c = 0, int u = 0) {
    if (k == 0) {
        best = min(best, c);
        return;
    }
    for (; u < m; ++u) {
        ll bu = 1ll << u;
        if ((used & bu) == 0 && !must[u]) dfs2(k-1, used|g[u], c+W[u], u+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m >> k;
    int t = 0;
    int t2 = 0;
    g.assign(m, 0);
    forn(i, n) {
        int a, p, b, q; cin >> a >> p >> b >> q;
        --a; --b;
        t += max(p, q);
        t2 += min(p, q);
        E[i] = make_pair(a, b);
        W[a] += max(q-p, 0);
        W[b] += max(p-q, 0);
        g[a] |= 1ll << b;
        g[b] |= 1ll << a;
        must[a] |= a==b;
    }
    iota(s, s+m, 0);
    sort(s, s+m, [&](int i, int j) {return W[i] > W[j];});
    if (k <= m/2) {
        best = -1;
        dfs(k);
        cout << (best < 0 ? -1 : t - best) << "\n";
    } else {
        best = INF;
        dfs2(m-k);
        cout << (best == INF ? -1 : t2 + best) << "\n";
    }
}
