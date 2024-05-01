#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define all(x) x.begin(), x.end()

struct UF {
    vector<int> pars;
    vector<int> sizes;
    int num_sets;

    UF(int n) {
        pars.resize(n);
        iota(all(pars), 0);
        sizes.assign(n, 0);
        num_sets = n;
    }

    int find(int i) {
        return pars[i] == i ? i : (pars[i] = find(pars[i]));
    }

    bool onion(int i, int j) {
        int r1 = find(i);
        int r2 = find(j);
        if (r1 == r2) return false;
        if (sizes[r2] > sizes[r1]) swap(r1, r2);
        pars[r2] = r1;
        sizes[r1] += sizes[r2];
        num_sets -= 1;
        return true;
    }
};

typedef tuple<int, int, int> tiii;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    priority_queue<tiii, vector<tiii>, greater<>> pq;
    forn(i, n) forn(j, n) {
        int d; cin >> d;
        if (i < j) pq.emplace(d, i, j);
    }
    UF uf(n);
    int c = 0;
    while (c < n-1) {
        auto [_, i, j] = pq.top(); pq.pop();
        if (uf.onion(i, j)) {
            cout << i+1 << " " << j+1 << "\n";
            ++c;
        }
    }
}
