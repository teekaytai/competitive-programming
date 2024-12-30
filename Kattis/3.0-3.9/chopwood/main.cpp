#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forn1(i, n) for (int i = 1; i <= (n); ++i)

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vi a(n, 0);
    vi c(n + 2, 0);
    forn (i, n) {
        cin >> a[i];
        ++c[a[i]];
    }
    if (a[n - 1] != n + 1) {
        cout << "Error\n";
        return 0;
    }
    priority_queue<int> pq;
    forn1 (i, n) if (c[i] == 0) pq.push(-i);
    forn (i, n) {
        cout << -pq.top() << "\n";
        pq.pop();
        if (--c[a[i]] == 0) pq.push(-a[i]);
    }
}
