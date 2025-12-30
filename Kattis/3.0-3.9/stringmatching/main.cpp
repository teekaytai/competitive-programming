#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define all(x) begin(x), end(x)
#define len(x) int(size(x))
inline int MSB(int x) { return x ? 1 << (31 - __builtin_clz(x)) : 0; }
#define pb push_back

typedef complex<double> C;
typedef vector<C> vc;
void fft(vc& a) {
    int n = len(a);
    int L = 31 - __builtin_clz(n);
    static vector<complex<long double>> R(2, 1);
    static vc rt(2, 1);  // (^ 10% faster if double)
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
// For convolution of complex numbers or more than two vectors: FFT, multiply
// pointwise, divide by n, reverse(start+1, end), FFT back.
vc conv(vc& a, vc& b) {
    if (a.empty() || b.empty()) return {};
    int m = len(a) + len(b) - 1;
    int n = MSB(m) * 2;
    vc in(n), res(n);
    copy(all(a), begin(in));
    copy(all(b), begin(res));
    fft(in);
    fft(res);
    forn (i, n) res[i] = res[i] * in[i] / double(n);
    reverse(res.begin() + 1, res.end());
    fft(res);
    res.resize(m);
    return res;
}

const double pi = M_PI;
const double EPS = 1e-9;

void solve() {
    string p, s;
    while (getline(cin, p)) {
        getline(cin, s);
        vc A;
        for (char c : p) {
            A.pb(polar(1.0, -int(c) * 2 * pi / 128));
        }
        reverse(all(A));
        vc B;
        for (char c : s) {
            B.pb(polar(1.0, int(c) * 2 * pi / 128));
        }
        vc C = conv(A, B);
        double m = len(p);
        for(int i = 0; i < len(s) - len(p) + 1; ++i) {
            if (C[i + len(p) - 1].real() + EPS >= m) {
                cout << i << " ";
            }
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();
}
