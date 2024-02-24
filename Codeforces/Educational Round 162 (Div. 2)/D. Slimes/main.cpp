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
#define x first
#define y second

template <typename... Ts>
inline void print(const Ts&... args) {
    const char* sep = "";
    (((cout << sep << args), sep = " "), ...);
    cout << "\n";
}
template <typename... Ts>
inline void printerr(const Ts&... args) {
    const char* sep = "";
    cerr << "\u001B[31m";
    (((cerr << sep << args), sep = " "), ...);
    cerr << "\u001B[0m" << endl;
}

const int INF = 2e9;
const int MAXN = 3e5;
vector<int> a;
vector<ll> p;
vector<int> L;
vector<int> R;
vector<int> ans;

void solve() {
    int n; cin >> n;
    a.resize(n);
    p.resize(n+1);
    L.assign(n, n);
    R.assign(n, -1);
    p[0] = 0;
    forn(i, n) cin >> a[i], p[i+1] = p[i]+a[i];
    int lo = 0;
    forn(hi, n) {
        while (a[lo] != a[hi]) L[lo++] = hi;
    }
    int hi = n-1;
    rforn(lo, n) {
        while (a[lo] != a[hi]) R[hi--] = lo;
    }

    ans.assign(n, INF);
    forn(i, n) {
        if (i>0&&a[i-1]>a[i]||i<n-1&&a[i+1]>a[i]){
            ans[i]=1;
            continue;
        }
        int lo = -1;
        int hi = i > 0 ? R[i-1] : -1;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            ll s = p[i] - p[mid];
            if (s > a[i]) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        if (lo > -1) ans[i] = i - lo;
        lo = i<n-1 ? L[i+1] : n;
        hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            ll s = p[mid+1] - p[i+1];
            if (s > a[i]) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        if (hi < n) ans[i] = min(ans[i], hi - i);
        if (ans[i] == INF) ans[i] = -1;
    }
    for(int x : ans)cout << x << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
