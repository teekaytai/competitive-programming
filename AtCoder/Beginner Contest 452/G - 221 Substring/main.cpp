#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef array<int, 3> a3i;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
#define umap unordered_map
#define uset unordered_set
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forn1(i, n) for (int i = 1; i <= (n); ++i)
#define rforn(i, n) for (int i = (n) - 1; i >= 0; --i)
#define rforn1(i, n) for (int i = (n); i > 0; --i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define len(x) int(size(x))
#define LSB(x) ((x) & -(x))
inline int MSB(int x) { return x ? 1 << (31 - __builtin_clz(x)) : 0; }
inline ll MSB(ll x) { return x ? 1ll << (63 - __builtin_clzll(x)) : 0ll; }
template<class T> constexpr void cmin(T& a, T b) { a = min(a, b); }
template<class T> constexpr void cmax(T& a, T b) { a = max(a, b); }
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

template <typename... Ts>
inline void print(const Ts&... args) {
    [[maybe_unused]] const char* sep = "";
    (((cout << sep << args), sep = " "), ...);
    cout << "\n";
}
template <typename It, typename = enable_if_t<is_base_of_v<input_iterator_tag, typename iterator_traits<It>::iterator_category>>>
inline void print(It b, It e) {
    for (auto it = b; it != e; ++it) cout << *it << " ";
    cout << "\n";
}
template <typename... Ts>
inline void printerr(const Ts&... args) {
    [[maybe_unused]] const char* sep = "";
    cerr << "\u001B[31m";
    (((cerr << sep << args), sep = " "), ...);
    cerr << "\u001B[0m" << endl;
}
template <typename It, typename = enable_if_t<is_base_of_v<input_iterator_tag, typename iterator_traits<It>::iterator_category>>>
inline void printerr(It b, It e) {
    cerr << "\u001B[31m{";
    if (b != e) {
        cerr << *b;
        for (auto it = next(b); it != e; ++it) cerr << ", " << *it;
    }
    cerr << "}\u001B[0m" << endl;
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

    SA(string& str) : SA(str.c_str(), len(str)) {}

    static string join_strs(const vector<string>& strs) {
        string combined;
        forn (i, len(strs)) {
            combined.append(strs[i]);
            // Seperators must be pairwise distinct and smaller than actual characters
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

    // Returns inclusive interval [L, R]
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
const ll MOD = 998244353;

void solve() {
    int n; cin >> n;
    vi a(n + 1);
    forn(i, n) cin >> a[i];
    a[n] = 0;
    int c = a[0];
    int l = 0;
    string s;
    for (int x : a) {
        if (x == c) ++l;
        else {
            if (l < c) s += '0';
            else if (l == c) s += '0' + c;
            else {
                s += '0' + c;
                s += '0';
                s += '0' + c;
            }
            c = x;
            l = 1;
        }
    }
    s += '\0';
    SA sa(s);
    int r = len(s) - 1;
    ll ans = 0;
    rforn(i, len(s) - 1) {
        if (s[i] == '0') {
            r = i;
            continue;
        }
        ans += max(r - i - sa.lcp[sa.ra[i]], 0);
    }
    print(ans);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
