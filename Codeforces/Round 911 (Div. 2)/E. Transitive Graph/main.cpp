#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define len(x) (int) x.size()

ll a[200000];
vector<int> al[200000];
vector<int> al_rev[200000];
bool seen[200000];
vector<int> order;
vector<int> comp;
int roots[200000];
int sz[200000];

void dfs1(int v) {
    if (seen[v]) return;
    seen[v] = true;
    for (int adj : al[v]) {
        dfs1(adj);
    }
    order.push_back(v);
}

void dfs2(int v) {
    if (seen[v]) return;
    seen[v] = true;
    comp.push_back(v);
    for (int adj : al_rev[v]) {
        dfs2(adj);
    }
}

void solve() {
    int n, m; cin >> n >> m;
    forn (i, n) {
        cin >> a[i];
        al[i].clear();
        al_rev[i].clear();
        seen[i] = false;
    }
    forn (i, m) {
        int u, v; cin >> u >> v;
        --u, --v;
        al[u].push_back(v);
        al_rev[v].push_back(u);
    }
    order.clear();
    forn (i, n) {
        dfs1(i);
    }
    forn (i, n) {
        seen[i] = false;
    }
    reverse(all(order));
    ll res = 0;
    int mx_s = 0;
    for (int v : order) {
        if (seen[v]) continue;
        dfs2(v);
        int r = comp.front();
        ll w = 0;
        ll w2 = 0;
        int s = 0;
        for (int u : comp) {
            roots[u] = r;
            w += a[u];
        }
        for (int u : comp) {
            for (int adj : al_rev[u]) {
                int r2 = roots[adj];
                if (r2 == r) continue;
                if (sz[r2] > s || sz[r2] == s && a[roots[adj]] < w2) {
                    w2 = a[roots[adj]];
                    s = sz[r2];
                }
            }
        }
        a[r] = w + w2;
        sz[r] = comp.size() + s;
        if (sz[r] > mx_s || sz[r] == mx_s && a[r] < res) {
            res = a[r];
            mx_s = sz[r];
        }
        comp.clear();
    }
    cout << mx_s << " " << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
