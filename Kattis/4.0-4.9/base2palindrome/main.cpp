#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    --n;
    int i = 0;
    int b = 1;
    bool o = false;
    while (i + b <= n) {
        i += b;
        if (i + b > n) {
            o = true;
            break;
        }
        i += b;
        b *= 2;
    }
    b += n - i;
    int ans = b;
    if (!o) b >>= 1;
    while (b) {
        ans = (ans << 1) + (b & 1);
        b >>= 1;
    }
    cout << ans << "\n";
}
