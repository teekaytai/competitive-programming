#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define len(x) (int) x.size()

int a[500000];
vector<int> adj_list[500000];

ll best;

ll dfs(int i, int p) {
    vector<ll> r;
    for (int adj : adj_list[i]) {
        if (adj == p) {
            continue;
        }
        r.push_back(dfs(adj, i));
    }
    sort(all(r), greater<>());
    if (len(r) == 0) {
        best = max(best, (ll) a[i]);
        return a[i];
    }
    ll one_sum = r[0];
    if (len(r) == 1) {
        best = max(max(best, (ll) a[i]), a[i] + r[0]);
        return max((ll) a[i], r[0]);
    }
    ll two_sum = one_sum + r[1];
    if (len(r) == 2) {
        best = max(max(max(best, (ll) a[i]), a[i] + r[0]), two_sum);
        return max(max((ll) a[i], r[0]), a[i] + two_sum);
    }
    ll sum = two_sum + r[2];
    for (int j = 3; j < len(r); ++j) {
        if (r[j] < 0) {
            break;
        }
        sum += r[j];
    }
    best = max(max(max(max(best, (ll) a[i]), a[i] + r[0]), two_sum), a[i] + sum);
    return max(max(max((ll) a[i], r[0]), a[i] + two_sum), a[i] + sum);
}

void solve() {
    int n; cin >> n;
    forn (i, n) {
        cin >> a[i];
        adj_list[i].clear();
    }
    forn (i, n - 1) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    best = 0;
    dfs(0, -1);
    cout << best << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
