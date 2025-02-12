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

struct SA {
    static constexpr int MAX_ASCII = 150;

    const int* T;
    const int n;
    vi ra;
    vi sa;
    vi lcp;

    // Include terminating symbol in input, or segfault may occur
    // Ensure input string is not modified/deleted
    SA(const int* _T, const int _n) : T(_T), n(_n) {
        construct_sa();
        compute_lcp();
    }

    // SA(const string& str) : SA(str.c_str(), len(str)) {}

    // static string join_strs(const vector<string>& strs) {
    //     string combined;
    //     forn (i, len(strs)) {
    //         combined.append(strs[i]);
    //         combined.pb(char(i));
    //     }
    //     return combined;
    // }

    void counting_sort(int k) {
        int buckets = n;
        vi c(buckets, 0);
        forn (i, n) ++c[i+k < n ? ra[i+k] : 0];
        int sum = 0;
        forn (i, buckets) {
            int t = c[i]; c[i] = sum; sum += t;
        }
        vi temp_sa(n);
        forn (i, n) temp_sa[c[sa[i]+k < n ? ra[sa[i]+k] : 0]++] = sa[i];
        swap(sa, temp_sa);
    }

    void construct_sa() {
        sa.resize(n);
        iota(all(sa), 0);
        ra.resize(n);
        forn (i, n) ra[i] = T[i];
        for (int k = 1; k < n; k <<= 1) {
            counting_sort(k);
            counting_sort(0);
            vi temp_ra(n);
            int r = 0;
            temp_ra[sa[0]] = r;
            forn (i, n-1) {
                temp_ra[sa[i+1]] =
                    ((ra[sa[i+1]] == ra[sa[i]]) && (ra[sa[i+1]+k] == ra[sa[i]+k])) ?
                    r : ++r;
            }
            swap(ra, temp_ra);
            if (ra[sa[n-1]] == n-1) break;
        }
    }

    void compute_lcp() {
        vi phi(n); // Index of previous suffix in sorted order
        vi plcp(n); // (Permuted) LCP in original suffix order
        phi[sa[0]] = -1;
        forn (i, n-1) phi[sa[i+1]] = sa[i];
        int L = 0;
        forn (i, n) {
            if (phi[i] == -1) { plcp[i] = 0; continue; }
            while (i+L < n && phi[i]+L < n && T[i+L] == T[phi[i]+L])
                ++L;
            plcp[i] = L;
            L = max(L-1, 0);
        }
        lcp.resize(n);
        forn (i, n) lcp[i] = plcp[sa[i]];
    }
};

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 1e6+5;
int a[MAXN];
int p[MAXN];
int pp[MAXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    umap<int, int> m;
    p[0] = 1;
    pp[0] = 1;
    forn(i, n) {
        cin >> p[i+1];
        auto it = m.find(p[i+1]);
        if (it != m.end()) a[i] = it->se;
        else {
            int s = len(m)+1;
            m.emplace(p[i+1], s);
            a[i] = s;
        }
        p[i+1] = p[i+1]%2==0;
        p[i+1] = p[i+1]==p[i];
        pp[i+1] = pp[i] + p[i+1];
    }
    a[n] = 0;
    SA sa(a, n+1);
    ll t = 0;
    // printerr(vi(a, a+n+1));
    // printerr(vi(p, p+n+1));
    // printerr(vi(pp, pp+n+1));
    forn1(i, n) {
        int lcp = sa.lcp[i];
        int idx = sa.sa[i];
        int l = n - idx;
        int s = l - lcp;
        int temp = pp[idx+l]-pp[idx+lcp];
        // printerr(pp[idx+l+1], pp[idx], temp);
        if (!p[idx]) temp = s - temp;
        t += temp;
        // printerr(lcp, idx, l, s, t);
    }
    print(t);
}
