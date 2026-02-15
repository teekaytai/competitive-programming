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

#include <sys/time.h>
typedef uint64_t ull;
static int C; // initialized below

template<int M, class B>
struct A {
    int x; B b; A(int x=0) : x(x), b(x) {}
    A(int x, B b) : x(x), b(b) {}
    A operator+(A o){int y = x+o.x; return{y - (y>=M)*M, b+o.b};}
    A operator-(A o){int y = x-o.x; return{y + (y< 0)*M, b-o.b};}
    A operator*(A o) { return {(int)(1LL*x*o.x % M), b*o.b}; }
    explicit operator ull() const { return x ^ (ull) b << 21; }
    bool operator==(A o) const { return (ull)*this == (ull)o; }
    bool operator<(A o) const { return (ull)*this < (ull)o; }
};
typedef A<1000000007, A<1000000009, unsigned>> H;

struct HashInterval {
	vector<H> ha, pw;
	HashInterval(string& str) : ha(len(str)+1), pw(ha) {
		pw[0] = 1;
		forn(i, len(str))
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	H hashInterval(int a, int b) { // hash [a, b)
        assert(a <= b);
		return ha[b] - ha[a] * pw[b - a];
	}
};

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
};

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

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;
const ll MOD = 998244353;

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    string t; cin >> t;

    int B = 10;
    HashInterval ha(s);
    vector<vector<H>> hs(B + 1);
    forn (i, len(s)) {
        for (int l = 2; l <= min(B, len(s) - i); ++l) {
            forn (j, l) {
                hs[l].pb(ha.hashInterval(i, i + l) - (H) s[i + j] * ha.pw[l - 1 - j]);
            }
        }
    }
    for (auto& r : hs) sort(all(r));
    HashInterval hat(t);

    s += '\0';
    s += t;
    s += '\1';
    SA sa(s);
    SpT<int> spt(sa.lcp);

    int ans = 0;
    int lo = 0;
    while (lo < m) {
        ++ans;
        bool done = false;
        for (int l = 2; l <= B; ++l) {
            if (lo + l > m) {
                lo = m;
                done = true;
                break;
            }
            bool can = false;
            forn (j, l) {
                H h = hat.hashInterval(lo, lo + l) - (H) t[lo + j] * hat.pw[l - 1 - j];
                auto it = lower_bound(all(hs[l]), h);
                if (it != hs[l].end() && *it == h) {
                    can = true;
                    break;
                }
            }
            if (!can) {
                lo += l - 1;
                done = true;
                break;
            }
        }
        if (!done) {
            int mx = 0;
            forn(i, n) {
                int p = sa.ra[n + 1 + lo];
                int q = sa.ra[i];
                if (p > q) swap(p, q);
                int l = spt.query(p + 1, q + 1);
                if (i + l == n || lo + l == m) {
                    cmax(mx, l);
                    break;
                }
                p = sa.ra[n + 1 + lo + l + 1];
                q = sa.ra[i + l + 1];
                if (p > q) swap(p, q);
                cmax(mx, l + 1 + spt.query(p + 1, q + 1));
            }
            assert(mx >= B);
            lo += mx;
        }
    }
    print(ans);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    timeval tp;
	gettimeofday(&tp, 0);
	C = (int)tp.tv_usec; // (less than modulo)
	assert((ull)(H(1)*2+1-3) == 0);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
