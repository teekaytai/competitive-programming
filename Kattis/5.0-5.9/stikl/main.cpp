#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define rforn(i, n) for (int i = (n) - 1; i >= 0; --i)
inline int MSB(int x) { return x ? 1 << (31 - __builtin_clz(x)) : 0; }
#define pb push_back

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vi a(n);
    vvi b(n);
    stack<int> st;
    forn(i, n) {
        cin >> a[i];
        b[i].pb(-1);
        while (!st.empty() && a[st.top()] <= a[i]) {
            b[st.top()][0] = i;
            st.pop();
        }
        st.push(i);
    }
    forn(i, 31 - __builtin_clz(n-1)) rforn(j, n) {
        b[j].pb(b[j][i] == -1 ? -1 : b[b[j][i]][i]);
    }
    forn(_, q) {
        int s, d; cin >> s >> d; --s;
        while (s + d < n && s != -1 && d) {
            int bit = MSB(d);
            s = b[s][__builtin_ctz(bit)];
            d -= bit;
        }
        if (d || s == -1) cout << "leik lokid\n";
        else cout << s+1 << "\n";
    }
}
