#include <bits/stdc++.h>
using namespace std;

int q(int a, int b, int c, int d) {
    cout << "? " << a << " " << b << " " << c << " " << d << endl;
    int cmp; cin >> cmp;
    return cmp;
}

int f(int l, int r) {
    if (l == r) {
        return 0;
    }
    if (l == r - 1) {
        return q(0, 0, l, r);
    }
    int lo = l;
    int hi = r - 1;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        int cmp = q(l, mid, mid, r);
        if (cmp == 0) {
            return 2 * ((mid - l) < (r - mid) ? f(l, mid) : f(mid, r));
        }
        if (cmp == -1) {
            hi = mid - 1;
        } else {
            lo = mid;
        }
    }
    return 2 * ((lo - l) < (r - lo) ? f(l, lo) : f(lo + 1, r)) + 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    int ans = f(0, n);
    cout << "! " << ans << endl;
}
