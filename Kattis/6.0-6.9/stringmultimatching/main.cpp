#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define all(x) x.begin(), x.end()
#define len(x) (int) x.size()
#define pb push_back

struct SA {
    static constexpr int MAX_UNICODE = 300;

    const char* T;
    const int n;
    vi ra;
    vi sa;

    SA(const char* initialT, const int _n) : T(initialT), n(_n) {
        construct_sa();
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
        if (strncmp(T+sa[lo], P, m) != 0) return {0, -1};
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
};

int n;
string P[100000];

void solve() {
    forn(i, n) getline(cin, P[i]);
    string s; getline(cin, s);
    s += '\0';
    SA sa(s);
    forn (i, n) {
        auto [lo, hi] = sa.find_all(P[i]);
        vi ans;
        for (int i = lo; i <= hi; ++i) ans.pb(sa.sa[i]);
        sort(all(ans));
        for (int i : ans) cout << i << " ";
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    while (cin >> n) {
        cin.ignore();
        solve();
    }
}
