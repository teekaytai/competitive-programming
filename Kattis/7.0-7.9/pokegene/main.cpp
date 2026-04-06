#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define all(x) begin(x), end(x)
#define len(x) int(size(x))
template<class T> constexpr void cmax(T& a, T b) { a = max(a, b); }
#define pb push_back
#define eb emplace_back

template<class T>
struct SpT {
	vector<vector<T>> jmp;
	SpT(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= len(V); pw *= 2, ++k) {
			jmp.eb(len(V) - pw * 2 + 1);
			forn(j, len(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}

    // Half-open interval [L, R)
	T query(int L, int R) {
		assert(L < R); // or return inf if a == b
		int dep = 31 - __builtin_clz(R - L);
		return min(jmp[dep][L], jmp[dep][R - (1 << dep)]);
	}
};

struct SA {
    static constexpr int MAX_ASCII = 200150;

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

    SA(vector<int>& str) : SA(str.data(), len(str)) {}

    static pair<vi, vi> join_strs(const vector<string>& strs) {
        vi combined;
        vi starts = {0};
        int t = 0;
        forn (i, len(strs)) {
            for (char c : strs[i]) combined.pb(200000 + c);
            combined.pb(i);
            t += len(strs[i]) + 1;
            starts.pb(t);
        }
        return {combined, starts};
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
};

void solve() {
    int n, q; cin >> n >> q;
    vector<string> ss(n);
    forn(i, n) cin >> ss[i];
    auto [S, starts] = SA::join_strs(ss);
    SA sa(S);
    SpT st(sa.lcp);
    forn(_, q) {
        int m, k; cin >> m >> k;
        vi xs(m);
        vi vs(m);
        forn(i, m) {
            cin >> xs[i]; --xs[i];
            vs[i] = sa.ra[starts[xs[i]]];
        }
        sort(all(vs));
        int ans = 0;
        forn(i, m - k + 1) {
            int h = k > 1 ? st.query(vs[i] + 1, vs[i + k - 1] + 1) : starts[xs[i] + 1] - starts[xs[i]] - 1;
            int l = 0;
            if (i > 0) cmax(l, st.query(vs[i - 1] + 1, vs[i + k - 1] + 1));
            if (i + k < m) cmax(l, st.query(vs[i] + 1, vs[i + k] + 1));
            ans += h - l;
        }
        cout << ans << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
