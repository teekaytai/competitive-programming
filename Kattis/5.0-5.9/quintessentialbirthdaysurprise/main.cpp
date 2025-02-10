#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define len(x) (int) (x).size()
template<class T> constexpr void cmax(T& a, T b) { a = max(a, b); }
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

struct Line {
	mutable ll k, m, p;
    int i;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m, int i) {
		auto z = insert({k, m, 0, i}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	pair<ll, int> query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return {l.k * x + l.m, l.i};
	}
};

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;

void solve() {
    int n; cin >> n;
    vector<tuple<ll, int, int>> a;
    a.reserve(n);
    forn(i, n) {
        ll t; int v, e; cin >> v >> t >> e;
        --e;
        a.eb(t, v, e);
    }
    sort(all(a));
    bool B[5][5] = {false};
    int m; cin >> m;
    forn(i, m) {
        int x, y; cin >> x >> y;
        --x; --y;
        B[x][y] = true;
        B[y][x] = true;
    }
    LineContainer lcs[5];
    pii mx = {INT_MIN, -1};
    vll dp(n, 0);
    vi p(n, -1);
    ll ans = LLONG_MIN;
    int start = -1;
    forn (i, n) {
        auto [_, v, e] = a[i];
        cmax(mx, {v, i});
        forn (j, 5) if (!B[e][j] && !lcs[j].empty()) {
            auto [w, k] = lcs[j].query(v);
            if (w > dp[i]) {
                dp[i] = w;
                p[i] = k;
            }
        }
        lcs[e].add(v, dp[i], i);
        if (p[i] != -1 && dp[i] > ans) {
            ans = dp[i];
            start = i;
        }
    }
    if (mx.fi >= ans || p[start] == -1) cout << mx.fi << "\n1\n" << mx.se+1 << "\n";
    else {
        vi ps = {start};
        while (p[ps.back()] != -1) ps.pb(p[ps.back()]);
        reverse(all(ps));
        cout << ans << "\n" << len(ps) << "\n";
        for (int i : ps) cout << i+1 << " ";
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();
}
