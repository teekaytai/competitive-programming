#include <bits/stdc++.h>
using namespace std;

#define uset unordered_set
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define rforn1(i, n) for (int i = (n); i > 0; --i)
#define len(x) int(size(x))
#define pb push_back

typedef uint64_t ull;
typedef uint64_t H;
static ull B[26];

vector<H> getHashes(string& str, int length) {
    if (len(str) < length) return {};
    H h = 0;
    forn(i, length) h = h + B[str[i] - 'a'];
    vector<H> ret = {h};
    for (int i = length; i < len(str); ++i) {
        ret.pb(h += B[str[i] - 'a'] - B[str[i-length] - 'a']);
    }
    return ret;
}

void solve() {
    string s, t; cin >> s >> t;
    string best = "NONE";
    rforn1(l, min(len(s), len(t))) {
        uset<H> se;
        for (auto h : getHashes(t, l)) se.insert(h);
        auto v = getHashes(s, l);
        forn(i, len(v)) {
            if (se.contains(v[i])) {
                cout << string(s, i, l) << "\n";
                return;
            }
        }
    }
    cout << "NONE\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<ull> distr(1ull, ULLONG_MAX);
    forn(i, 26) {
        B[i] = distr(gen);
    }

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
