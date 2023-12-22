#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define all(x) x.begin(), x.end()
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define len(x) (int) x.size()
const int INF = 1e9;

int n, m, t;
int S;
int T;
int mat[50][50];
int a[50];
int b[50];
vvi adj;
vvi cost;
vvi cap;

void BF(vi& par, vi& ds) {
    fill(all(par), -1);
    fill(all(ds), INF);
    vector<bool> inq(t, false);
    par[S] = -2;
    ds[S] = 0;
    queue<int> q;
    q.push(S);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int v : adj[u]) {
            int d = ds[u] + cost[u][v];
            if (cap[u][v] && d < ds[v]) {
                par[v] = u;
                ds[v] = d;
                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

pii MCMF() {
    vi par(t);
    vi ds(t);
    int tf = 0;
    int tc = 0;
    while (true) {
        BF(par, ds);
        if (ds[T] == INF) {
            break;
        }
        tc += ds[T];
        int f = INF;
        int curr = T;
        while (curr != S) {
            int prev = par[curr];
            f = min(f, cap[prev][curr]);
            curr = prev;
        }
        tf += f;
        curr = T;
        while (curr != S) {
            int prev = par[curr];
            cap[prev][curr] -= f;
            cap[curr][prev] += f;
            curr = prev;
        }
    }
    return {tf, tc};
}

void solve() {
    cin >> n >> m;
    S = n + m;
    T = S + 1;
    t = T + 1;
    adj.assign(t, vi());
    cost.assign(t, vi(t, 0));
    cap.assign(t, vi(t, 0));
    int s = 0;
    forn(r, n) {
        forn(c, m) {
            cin >> mat[r][c];
            s += mat[r][c];
            adj[r].push_back(n+c);
            adj[n+c].push_back(r);
            cost[r][n+c] = 1 - mat[r][c];
            cost[n+c][r] = mat[r][c] - 1;
            cap[r][n+c] = 1;
        }
    }
    int sa = 0;
    int sb = 0;
    forn(i, n){
        cin >> a[i];
        sa += a[i];
        adj[S].push_back(i);
        adj[i].push_back(S);
        cap[S][i] = a[i];
    }
    forn(i,m) {
        cin>>b[i];
        sb += b[i];
        adj[n+i].push_back(T);
        adj[T].push_back(n+i);
        cap[n+i][T] = b[i];
    }
    if (sa != sb) {
        cout << -1 << "\n";
        return;
    }
    auto [F, cst] = MCMF();
    cout << (F == sa ? (cst + (s + cst - sa)) : -1) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();
    return 0;
}
