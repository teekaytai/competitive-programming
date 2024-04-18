#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forn1(i, n) for (int i = 1; i <= (n); ++i)
#define all(x) x.begin(), x.end()
#define len(x) (int) x.size()
#define pb push_back

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

    pair<int, vi> longest_common_substring(vi seps, int m = 0) {
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
        vi ids;
        int maxlcp = -1;
        int lo = 0, c = ++w_counts[w_ids[0]] == 1;
        bool newp = true;
        forn1 (hi, n-1) {
            c += ++w_counts[w_ids[hi]] == 1;
            lcps.insert(lcp[hi]);
            while (c == m) {
                int l = *lcps.begin();
                if (l > maxlcp) ids = {lo}, maxlcp = l, newp = false;
                else if (l == maxlcp && newp) ids.pb(lo), newp = false;
                else if (l < maxlcp) newp = true;
                c -= --w_counts[w_ids[lo]] == 0;
                lcps.erase(lcps.find(lcp[++lo]));
            }
        }
        return {maxlcp, ids};
    }
};

int n;
vector<string> strs;

void solve() {
    strs.resize(n);
    vi seps;
    forn (i, n) {
        cin >> strs[i];
        seps.pb(i == 0 ? len(strs[i]) : seps.back() + len(strs[i]) + 1);
    }
    if (n == 1) {
        cout << strs[0] << "\n\n";
        return;
    }
    string combined = SA::join_strs(strs);
    SA sa(combined);
    auto [mx, ids] = sa.longest_common_substring(seps, n/2+1);
    if (mx <= 0) cout << "?\n\n";
    else {
        for (int idx : ids) cout << combined.substr(sa.sa[idx], mx) << "\n";
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;
    while (n) {
        solve();
        cin >> n;
    }
}
