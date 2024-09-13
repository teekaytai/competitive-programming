#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ll a, b, x, n, m; cin >> a >> b >> x >> n >> m;
    ll pow_a = a;
    ll s = 1;
    ll A = 1;
    ll gp = 0;
    for (ll bit = 1; n; bit <<= 1) {
        if (n & bit) {
            n -= bit;
            gp = (gp + A * s) % m;
            A = A * pow_a % m;
        }
        s = (pow_a + 1) * s % m;
        pow_a = pow_a * pow_a % m;
    }
    cout << (A*x+b*gp) % m << "\n";
}
