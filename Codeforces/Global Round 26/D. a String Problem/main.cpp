#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
#define umap unordered_map
#define uset unordered_set
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forn1(i, n) for (int i = 1; i <= (n); ++i)
#define rforn(i, n) for (int i = (n) - 1; i >= 0; --i)
#define rforn1(i, n) for (int i = (n); i > 0; --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define len(x) (int) x.size()
#define LSB(x) ((x) & -(x))
inline int MSB(int x) { return x ? 1 << (31 - __builtin_clz(x)) : 0; }
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

template <typename... Ts>
inline void print(const Ts&... args) {
    const char* sep = "";
    (((cout << sep << args), sep = " "), ...);
    cout << "\n";
}
template <typename T>
inline void print(const vector<T>& v) {
    for (auto x : v) cout << x << " ";
    cout << "\n";
}
template <typename... Ts>
inline void printerr(const Ts&... args) {
    const char* sep = "";
    cerr << "\u001B[31m";
    (((cerr << sep << args), sep = " "), ...);
    cerr << "\u001B[0m" << endl;
}
template <typename T>
inline void printerr(const vector<T>& v) {
    cerr << "\u001B[31m";
    for (auto x : v) cerr << x << " ";
    cerr << "\u001B[0m" << endl;
}

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;

void solve() {
    string s; cin >> s;
    int n = len(s);
    int idx = -1;
    int L = 0;
    rforn (i, n) {
        if (s[i] != 'a') {
            ++L;
            idx = i;
        }
    }
    if (idx == -1) {
        print(n - 1);
        return;
    }
    ll t = 0;
    int v = 0;
    forn1 (l, n-idx) if (s[idx+l-1] != 'a') {
        ++v;
        if (L % v) continue;
        // printerr(l, v);
        int mn = INF;
        int c = 0;
        for (int i = idx + l; i < n; ++i) {
            if (s[i] == 'a') ++c;
            else {
                bool can = i + l <= n;
                if (can) for (int j = 0; j < l; ++j) {
                    if (s[i+j] != s[idx+j]) {
                        can = false;
                        break;
                    }
                }
                if (!can) {
                    mn = -1;
                    break;
                }
                mn = min(mn, c);
                c = 0;
                i += l-1;
            }
        }
        mn = min(mn, idx+c);
        if (mn >= 0)
            t += ll(mn+2)*(mn+1)/2-(mn>idx?ll(mn-idx-1+2)*(mn-idx-1+1)/2:0)-(mn>=c?ll(mn-c-1+2)*(mn-c-1+1)/2:0)+(mn>=idx+c+2?ll(mn-idx-c-2+2)*(mn-idx-c-2+1)/2:0);
        // printerr(t, mn, c);
    }
    print(t);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
