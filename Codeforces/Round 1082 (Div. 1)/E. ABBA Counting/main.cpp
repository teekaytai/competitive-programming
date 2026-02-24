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

const ll MOD = 998244353;
ll pow2[200001];

auto init = ([]() {
    pow2[0] = 1;
    forn1(i, len(pow2) - 1) {
        pow2[i] = pow2[i - 1] * 2 % MOD;
    }
    return 0;
})();

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
// For convolution of complex numbers or more than two vectors: FFT, multiply
// pointwise, divide by n, reverse(start+1, end), FFT back.
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

void solve() {
    int n; cin >> n;
    int m = n / 2;
    string s; cin >> s;
    auto f = [&](string& p, string& q, char c1, char c2) {
        int d = len(p);
        vd a(d * 2);
        vd b(d);
        forn(i, d) {
            a[i] = p[i] == c1;
            a[i + d] = p[i] == c1;
        }
        forn(i, d) {
            b[d - i - 1] = q[i] == c2;
        }
        vd c = conv(a, b);
        vi res(d);
        forn(i, d) {
            res[i] = (int) round(c[d + i - 1]);
        }
        return res;
    };
    auto g = [&](int l, int r, int d) {
        string t(d, '?');
        int j = 0;
        for (int i = l; i < r; ++i) {
            char c = s[i];
            if (t[j] == '?') t[j] = c;
            else if (c != '?' && t[j] != c) return string();
            ++j;
            if (j == d) j -= d;
        }
        return t;
    };
    ll ans = 0;
    vll nope(m + 1, 0);
    forn1(d, m) if (m % d == 0) {
        string p = g(0, m, d);
        string q = g(m, n, d);
        if (p == "" || q == "") continue;
        vi c1 = f(p, q, 'a', 'b');
        vi c2 = f(p, q, 'b', 'a');
        vi x = f(p, q, '?', '?');
        ll t = nope[d];
        forn(i, d) if (c1[i] == 0 && c2[i] == 0) {
            t = (t + pow2[x[i]]) % MOD;
        }
        int r = m / d;
        for (int i = 2; i <= r; ++i) if (r % i == 0) {
            nope[i * d] -= i * t;
        }
        ans = (ans + t % MOD) % MOD;
    }
    print((ans + MOD) % MOD);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}
