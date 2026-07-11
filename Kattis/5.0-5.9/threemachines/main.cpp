#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define all(x) begin(x), end(x)
#define len(x) int(size(x))

ull modmul(ull a, ull b, ull M) {
	ll ret = a * b - M * ull(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
	ull ans = 1;
	for (; e; b = modmul(b, b, mod), e /= 2)
		if (e & 1) ans = modmul(ans, b, mod);
	return ans;
}
bool isPrime(ull n) {
	if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
	ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
	    s = __builtin_ctzll(n-1), d = n >> s;
	for (ull a : A) {   // ^ count trailing zeroes
		ull p = modpow(a%n, d, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--)
			p = modmul(p, p, n);
		if (p != n-1 && i != s) return 0;
	}
	return 1;
}
ull pollard(ull n) {
	ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
	auto f = [&](ull x) { return modmul(x, x, n) + i; };
	while (t++ % 40 || __gcd(prd, n) == 1) {
		if (x == y) x = ++i, y = f(x);
		if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
		x = f(x), y = f(f(y));
	}
	return __gcd(prd, n);
}
vector<ull> factor(ull n) {
	if (n == 1) return {};
	if (isPrime(n)) return {n};
	ull x = pollard(n);
	auto l = factor(x), r = factor(n / x);
	l.insert(l.end(), all(r));
	return l;
}

ull f(vector<pair<const ull, int>>& a, ull m, ull x = 1, int i = 0) {
    ull t = 0;
    if (i == len(a)) {
        while (x < m) {
            t += m - x;
            x *= 2;
        }
        return t;
    }
    auto [k, v] = a[i];
    forn (j, v + 1) {
        t += f(a, m, x, i + 1);
        x *= k;
    }
    return t;
}

void solve() {
    int n; ull m; cin >> n >> m;
    ull g = 0;
    forn(_, n) {
        ull x; cin >> x;
        g = gcd(g, x - 1);
    }
    auto a = factor(g);
    unordered_map<ull, int> ma;
    for (ull x : a) ++ma[x];
    ma.erase(2);
    auto b = vector(all(ma));
    cout << f(b, m) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
