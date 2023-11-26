#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define len(x) (int) x.size()

const int N = 300001;
int ls[N];
int rs[N];
string s;

int dfs(int v) {
    if (v == 0) {
        return 1e6;
    }
    if (ls[v] == 0 && rs[v] == 0) {
        return 0;
    }
    return min((s[v-1] != 'L') + dfs(ls[v]), (s[v-1] != 'R') + dfs(rs[v]));
}

void solve() {
    int n; cin >> n;
    cin >> s;
    forn (i, n) {
        cin >> ls[i+1] >> rs[i+1];
    }
    cout << dfs(1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
