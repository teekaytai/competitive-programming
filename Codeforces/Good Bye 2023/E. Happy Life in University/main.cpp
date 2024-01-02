#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define all(x) x.begin(), x.end()
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define len(x) (int) x.size()
#define pb push_back
#define x first
#define y second
const int INF = 1e9;
const int MAXN = 3e5;
int n;
int p[MAXN];
int a[MAXN];
int tin[MAXN];
int tout[MAXN];
vvi g;
vvi c;
int mxs[8*MAXN];
int lazy[8*MAXN];
ll best;

void reset() {
    best = 0;
    g.assign(n, vi());
    c.assign(n, vi());
    forn(i, 8*n) {
        mxs[i] = 0;
        lazy[i] = 0;
    }
}

void push(int v, int tl, int tr) {
    mxs[v] += lazy[v];
    if (tl < tr) {
        lazy[2*v] += lazy[v];
        lazy[2*v+1] += lazy[v];
    }
    lazy[v] = 0;
}

void update(int ql, int qr, int d, int v = 1, int tl = 0, int tr = 2*n-1) {
    push(v, tl, tr);
    if (qr < tl || ql > tr) return;
    if (ql <= tl && qr >= tr) {
        lazy[v] += d;
        push(v, tl, tr);
        return;
    }
    int mid = tl + (tr - tl) / 2;
    update(ql, qr, d, 2*v, tl, mid);
    update(ql, qr, d, 2*v+1, mid+1, tr);
    mxs[v] = max(mxs[2*v], mxs[2*v+1]);
}

int get_max(int ql, int qr, int v = 1, int tl = 0, int tr = 2*n-1) {
    if (qr < tl || ql > tr) return 0;
    push(v, tl, tr);
    if (ql <= tl && qr >= tr) return mxs[v];
    int mid = tl + (tr - tl) / 2;
    return max(get_max(ql, qr, 2*v, tl, mid), get_max(ql, qr, 2*v+1, mid+1, tr));
}

int dfs1(int u = 0, int t = 0) {
    tin[u] = t++;
    for (int v : g[u]) t = dfs1(v, t);
    tout[u] = t++;
    return t;
}

void dfs2(int u = 0) {
    for (int v : g[u]) dfs2(v);
    while (!c[a[u]].empty()) {
        int v = c[a[u]].back();
        if (tin[v] < tin[u] || tout[v] > tout[u]) break;
        c[a[u]].pop_back();
        update(tin[v], tout[v], -1);
    }
    c[a[u]].pb(u);
    update(tin[u], tout[u], 1);
    int m1 = 1, m2 = 1;
    for (int v : g[u]) {
        int m = get_max(tin[v], tout[v]);
        if (m > m2) swap(m, m2);
        if (m2 > m1) swap(m1, m2);
    }
    best = max(best, (ll)m1*m2);
}

void solve() {
    cin >> n;
    reset();
    forn(i, n-1) {
        cin >> p[i+1];
        --p[i+1];
        g[p[i+1]].pb(i+1);
    }
    forn(i, n) {
        cin >> a[i];
        --a[i];
    }
    dfs1();
    dfs2();
    cout << best << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
