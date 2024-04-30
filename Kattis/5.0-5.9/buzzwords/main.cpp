#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forn1(i, n) for (int i = 1; i <= (n); ++i)
#define all(x) x.begin(), x.end()
#define len(x) (int) x.size()

struct SA {
    static constexpr int MAX_UNICODE = 300;

    const string T;
    const int n;
    vi ra;
    vi sa;
    vi lcp;

    SA(const string initialT) : T(initialT + '\0'), n(len(initialT) + 1) {
        construct_sa();
        compute_lcp();
    }

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
            forn1 (i, n-1) {
                temp_ra[sa[i]] =
                    ((ra[sa[i]] == ra[sa[i-1]]) && (ra[sa[i]+k] == ra[sa[i-1]+k])) ?
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


const int INF = 1e9;
const int MAXN = 3e5;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string s; getline(cin, s);
    while (s != "") {
        string s2;
        for (char c : s) if (c != ' ') s2.push_back(c);
        SA sa(s2);
        forn1 (i, sa.n-1) {
            int mx = 0;
            int c = 0;
            for (int l : sa.lcp) {
                c = l >= i ? c + 1 : 0;
                mx = max(mx, c);
            }
            if (!mx) break;
            cout << (mx + 1) << "\n";
        }
        cout << "\n";

        getline(cin, s);
    }
}
