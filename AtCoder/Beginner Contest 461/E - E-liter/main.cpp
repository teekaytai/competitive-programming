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

int n, q;
vb um;
vpii qs;
int cs1[300001];
int c1;
int cs2[300001];
int c2;

void add(int ind, int end) {
    auto [t, x] = qs[ind];
    if (t == 1) c1 += ++cs1[x] == 1;
    else c2 += ++cs2[x] == 1;
} // add a[ind] (end = 0 or 1)
void del(int ind, int end) {
    auto [t, x] = qs[ind];
    if (t == 1) c1 -= --cs1[x] == 0;
    else c2 -= --cs2[x] == 0;

} // remove a[ind]
int calc(int qi) {
    return um[qi] ? n : (qs[qi].fi == 1 ? c2 : c1);
} // compute current answer

vi mo(vector<pii> Q) {
	int L = 0, R = 0, blk = 550; // ~N/sqrt(Q)
	vi s(len(Q)), res = s;
#define K(x) pii(x.first/blk, x.second ^ -(x.first/blk & 1))
	iota(all(s), 0);
	sort(all(s), [&](int s, int t){ return K(Q[s]) < K(Q[t]); });
	for (int qi : s) {
		pii q = Q[qi];
		while (L > q.first) add(--L, 0);
		while (R < q.second) add(R++, 1);
		while (L < q.first) del(L++, 0);
		while (R > q.second) del(--R, 1);
		res[qi] = calc(qi);
	}
	return res;
}

const ll MOD = 998244353;

void solve() {
    cin >> n >> q;
    c1 = 0;
    c2 = 0;
    qs.resize(q);
    um.assign(q, false);
    umap<int, int> m1;
    umap<int, int> m2;
    vpii Q;
    forn(i, q) {
        int t, x; cin >> t >> x;
        qs[i] = {t, x};
        auto it = t == 1 ? m1.find(x) : m2.find(x);
        int l;
        if (it == m1.end()) {
            if (t == 1) um[i] = true, l = i;
            else l = 0;
        } else l = it->se + 1;
        Q.eb(l, i);
        if (t == 1) {
            m1[x] = i;
        } else {
            m2[x] = i;
        }
    }
    vi res = mo(Q);
    ll c = 0;
    forn(i, q) {
        if (qs[i].fi == 1) c += res[i];
        else c -= res[i];
        print(c);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
