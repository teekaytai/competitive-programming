#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define all(x) x.begin(), x.end()
#define len(x) (int) x.size()

struct SA {
    static constexpr int MAX_UNICODE = 300;

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

    void counting_sort(int k) {
        int buckets = max(MAX_UNICODE, n);
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


void solve() {
    string s; cin >> s;
    s += '\0';
    SA sa(s);
    int t = 0;
    int p = 0;
    for (int x : sa.lcp) {
        t += max(x - p, 0);
        p = x;
    }
    cout << t << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
