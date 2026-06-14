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

template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    return os << "(" << p.fi << ", " << p.se << ")";
}
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

void FST(vll& a, bool inv) {
	for (int n = len(a), step = 1; step < n; step *= 2) {
		for (int i = 0; i < n; i += 2 * step) for(int j = i; j < i+step; ++j) {
			ll &u = a[j], &v = a[j + step]; tie(u, v) =
				// inv ? pii(v - u, u) : pii(v, u + v); // AND
				// inv ? pii(v, u - v) : pii(u + v, u); // OR /// include-line
				pll(u + v, u - v);                   // XOR /// include-line
		}
	}
	if (inv) for (ll& x : a) x /= len(a); // XOR only /// include-line
}
vll conv(vll a, vll b) {
	FST(a, 0); FST(b, 0);
	forn(i,len(a)) a[i] *= b[i];
	FST(a, 1); return a;
}

const ll MOD = 998244353;

void solve() {
    int n, m; cin >> n >> m;
    int M = 1 << m;
    vi cs(M, 0);
    forn(i, n) {
        int x; cin >> x;
        ++cs[x];
    }
    vpii a;
    vll B(M, 0);
    vi res(M, 0);
    int res0 = 0;
    forn(i, M) if (cs[i]) {
        a.eb(cs[i], i);
        B[i] = 1;
        res0 += cs[i] / 2;
    }
    vll A(M, 0);
    sort(rall(a));
    while (!a.empty() && a.back().fi <= 10) {
        int c = a.back().fi;
        int j = len(a) - 1;
        while (j >= 0 && a[j].fi == c) {
            auto [c, i] = a[j];
            --j;
            A[i] = 1;
            B[i] = 0;
        }
        auto C = conv(A, B);
        auto D = conv(A, A);
        forn(i, M) {
            res[i] += c * (C[i] + D[i] / 2);
        }
        while (!a.empty() && a.back().fi == c) {
            auto [c, i] = a.back();
            a.pop_back();
            A[i] = 0;
        }
    }
    forn (i, len(a)) {
        auto [c1, i1] = a[i];
        forn (j, i) {
            auto [c2, i2] = a[j];
            res[i1 ^ i2] += min(c1, c2);
        }
    }
    res[0] = res0;
    ll ans = 0;
    rforn(i, M) {
        ans = (ans * 10 + res[i]) % MOD;
    }
    print(ans);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
