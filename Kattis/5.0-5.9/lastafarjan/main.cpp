#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); ++i)
#define len(x) (int) (x).size()

vector<int> a;
int n, l;
int mx = 0;
unordered_set<int> seen;

void dfs(array<int, 4>& vs, int i) {
    mx = max(mx, i);
    int x = ((vs[3] * l + vs[2]) * l + vs[1]) * l + vs[0];
    if (i == n || seen.contains(x)) {
        return;
    }
    seen.insert(x);
    forn (j, 4) {
        if (vs[j] + a[i] < l) {
            array<int, 4> vs2 = vs;
            vs2[j] += a[i];
            int k = j;
            while (k > 0 && vs2[k] > vs2[k - 1]) {
                swap(vs2[k], vs2[k - 1]);
                --k;
            }
            dfs(vs2, i + 1);
        }
        if (vs[j] == 0) break;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> l;
    l += 2;
    a.resize(n);
    forn(i, n) cin >> a[i], ++a[i];
    array<int, 4> vs = {0};
    dfs(vs, 0);
    cout << mx << "\n";
}
