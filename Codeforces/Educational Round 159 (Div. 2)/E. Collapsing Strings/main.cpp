#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define all(x) x.begin(), x.end()
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define len(x) (int) x.size()

string ss[1000000];
pii pref_trie[1000000][26];
int x = 1;

void solve() {
    int n; cin >> n;
    ll total = 0;
    forn (i, n) {
        cin >> ss[i];
        total += len(ss[i]);
        int curr = 0;
        for (char c : ss[i]) {
            auto& [idx, count] = pref_trie[curr][c - 'a'];
            if (count++ == 0) {
                idx = x++;
            }
            curr = idx;
        }
    }
    total *= 2 * n;
    for (string& s : ss) {
        int curr = 0;
        for (int i = len(s) - 1; i >= 0; --i) {
            auto& [idx, count] = pref_trie[curr][s[i] - 'a'];
            if (!count) {
                break;
            }
            total -= 2 * count;
            curr = idx;
        }
    }
    cout << total << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();

    return 0;
}