#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> t3i;
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
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define len(x) (int) (x).size()
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
    cerr << "\u001B[31m{";
    for (auto x : v) cerr << x << ", ";
    cerr << "\u001B[0m}" << endl;
}

typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C>& a) {
	int n = len(a);
    int L = 31 - __builtin_clz(n);
	static vector<complex<long double>> R(2, 1);
	static vector<C> rt(2, 1);  // (^ 10% faster if double)
	for (static int k = 2; k < n; k *= 2) {
		R.resize(n); rt.resize(n);
		auto x = polar(1.0L, acos(-1.0L) / k);
		for (int i = k; i < 2*k; ++i) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
	}
	vi rev(n);
	forn (i, n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	forn (i, n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) forn (j, k) {
			auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];
			C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);
			a[i + j + k] = a[i + j] - z;
			a[i + j] += z;
		}
}
vd conv(const vd& a, const vd& b) {
	if (a.empty() || b.empty()) return {};
	vd res(len(a) + len(b) - 1);
	int L = 32 - __builtin_clz(len(res));
    int n = 1 << L;
	vector<C> in(n), out(n);
	copy(all(a), begin(in));
	forn (i, len(b)) in[i].imag(b[i]);
	fft(in);
	for (C& x : in) x *= x;
	forn (i, n) out[i] = in[-i & (n - 1)] - conj(in[i]);
	fft(out);
	forn (i, len(res)) res[i] = imag(out[i]) / (4 * n);
	return res;
}

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 1e6 + 1;

void solve() {
    int n; cin >> n;
    vd a(MAXN, 0);
    forn(_, n) {
        int x; cin >> x;
        ++a[x];
    }
    vd c = conv(a, a);
    ll ans = 0;
    forn1 (i, MAXN - 1) if (a[i]) {
        ans += (ll) round(c[2 * i]);
    }
    print((ans - n) / 2);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();
}
