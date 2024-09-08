#include <bits/stdc++.h>
using namespace std;

#define uset unordered_set
#define forn(i, n) for (int i = 0; i < (n); ++i)

int flip(int x) {
    int y = 0;
    while (x) {
        int d = x % 10;
        x /= 10;
        if (d == 3 || d == 4 || d == 7) {
            return 0;
        }
        y = y * 10 + (d == 6 ? 9 : d == 9 ? 6 : d);
    }
    return y;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, s; cin >> n >> s;
    uset<int> nums;
    forn(i, n) {
        int x; cin >> x;
        int y = flip(x);
        if (nums.find(s - x) != nums.end() || y && nums.find(s - y) != nums.end()) {
            cout << "YES\n";
            return 0;
        }
        nums.insert(x);
        if (y) nums.insert(y);
    }
    cout << "NO\n";
}
