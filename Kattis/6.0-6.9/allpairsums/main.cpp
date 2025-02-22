#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define len(x) (int) (x).size()

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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vd a(200001);
    vd b(200001);
    forn (_, n) {
        int x; cin >> x;
        ++a[x + 100000];
    }
    forn (_, m) {
        int x; cin >> x;
        ++b[x + 100000];
    }
    vd ans = conv(a, b);
    int q; cin >> q;
    forn(_, q) {
        int x; cin >> x;
        x += 200000;
        cout << (x < ans.size() ? ans[x] : 0) << "\n";
    }
}
