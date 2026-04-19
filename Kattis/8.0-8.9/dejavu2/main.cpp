#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define forn(i, n) for (int i = 0; i < (n); ++i)

struct Node {
    ll d;
    int l;
    int r;
    int h;
    Node(ll d, int l, int r, int h) : d(d), l(l), r(r), h(h) {}
    bool operator<(const Node& o) const {return d < o.d;}
};

const int MAXN = 1e6;

int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, k, l; cin >> n >> k >> l;
    forn(i, n) cin >> a[i];
    sort(a, a+n, greater<>());
    priority_queue<Node> pq;
    pq.emplace(accumulate(a, a+k, 0ll), 0, k-1, -1);
    forn(_, l) {
        if (pq.empty()) {
            cout << "-1\n";
            continue;
        }
        auto [d, l, r, h] = pq.top(); pq.pop();
        cout << d << "\n";
        if (h == l) ++l, h = -1;
        if (h == -1) {
            if (r < n-1) pq.emplace(d - a[r] + a[r+1], l, r+1, r);
        } else {
            pq.emplace(d - a[h-1] + a[h], l, r, h-1);
            if (r < n-1) pq.emplace(d - a[r] + a[r+1], h+1, r+1, r);
        }
    }
}
