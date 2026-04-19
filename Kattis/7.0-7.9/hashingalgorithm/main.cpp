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

    const char* T;
    const int n;
    vi ra;
    vi sa;
    vi lcp;

    // Include terminating symbol in input, or segfault may occur
    // Ensure input string is not modified/deleted
    SA(const char* _T, const int _n) : T(_T), n(_n) {
        construct_sa();
        compute_lcp();
    }

    SA(const string& str) : SA(str.c_str(), len(str)) {}

    static string join_strs(const vector<string>& strs) {
        string combined;
        forn (i, len(strs)) {
            combined.append(strs[i]);
            combined.pb(char(i));
        }
        return combined;
    }

    void counting_sort(int k) {
        int buckets = max(MAX_ASCII, n);
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

    bool contains(const string& s) {
        return contains(s.c_str(), len(s));
    }

    bool contains(const char* P, int m) {
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int cmp = strncmp(T+sa[mid], P, m);
            if (cmp == 0) return true;
            cmp < 0 ? lo = mid+1 : hi = mid-1;
        }
        return false;
    }

    pii find_all(const string& s) {
        return find_all(s.c_str(), len(s));
    }

    pii find_all(const char* P, int m) {
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            int cmp = strncmp(T+sa[mid], P, m);
            cmp < 0 ? lo = mid+1 : hi = mid;
        }
        if (strncmp(T+sa[lo], P, m) != 0) return {-1, -1};
        pii ans; ans.first = lo;
        hi = n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            int cmp = strncmp(T+sa[mid], P, m);
            cmp <= 0 ? lo = mid+1 : hi = mid;
        }
        ans.second = hi - 1;
        return ans;
    }

    pii longest_repeated_substring() {
        int idx = 0, maxlcp = -1;
        forn1 (i, n-1) if (lcp[i] > maxlcp) {
            maxlcp = lcp[i];
            idx = i;
        }
        return {maxlcp, idx};
    }

    pii longest_common_substring(const vi& seps, int m = 0) {
        if (m < 2) m = len(seps); // By default find substring common to all words
        vi w_ids(n); vi psa(n);
        forn (i, n) psa[sa[i]] = i;
        int w_id = 0;
        forn (i, n) {
            w_ids[psa[i]] = w_id;
            w_id += seps[w_id] == i;
        }
        multiset<int> lcps;
        vi w_counts(len(seps) + 1, 0);
        int idx = 0, maxlcp = -1;
        int lo = 0, c = ++w_counts[w_ids[0]] == 1;
        forn1 (hi, n-1) {
            c += ++w_counts[w_ids[hi]] == 1;
            lcps.insert(lcp[hi]);
            while (c == m) {
                int l = *lcps.begin();
                if (l > maxlcp) idx = lo, maxlcp = l;
                c -= --w_counts[w_ids[lo]] == 0;
                lcps.erase(lcps.find(lcp[++lo]));
            }
        }
        return {maxlcp, idx};
    }
};


const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;
int MOD = 998244353;

void solve() {
    string s; cin >> s;
    s.pb('\0');
    SA sa(s);
    stack<ll> ls({0});
    stack<ll> vs({0});
    ll t = 0;
    forn1 (i, sa.n-1) {
        ll hi = sa.n - 1 - sa.sa[i];
        ll lo = sa.lcp[i];
        ll v2 = 0;
        while (ls.top() > lo) {
            ll l2 = ls.top(); ls.pop();
            v2 = vs.top(); vs.pop();
            t = (t + v2*v2%MOD*(l2-max(lo, ls.top()))%MOD)%MOD;
            if (ls.top() > lo) vs.top() = (vs.top() + v2) % MOD;
        }
        if (lo > ls.top()) {
            ls.push(lo);
            vs.push(v2);
        } else if (lo == ls.top()) {
            vs.top() = (vs.top() + v2) % MOD;
        }
        ls.push(hi);
        vs.push(1);
    }
    while (ls.top() > 0) {
        ll l2 = ls.top(); ls.pop();
        ll v2 = vs.top(); vs.pop();
        t = (t + v2*v2%MOD*(l2-ls.top())%MOD)%MOD;
        vs.top() = (vs.top() + v2) % MOD;
    }
    print(t%MOD);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
