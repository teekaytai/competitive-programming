#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define umap unordered_map
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define all(x) begin(x), end(x)
#define len(x) int(size(x))
#define eb emplace_back
#define fi first
#define se second

struct Trie {
    static constexpr int MAXN = 1e6 + 1;
    static constexpr int K = 26;
    static constexpr char OFFSET = 'a';

    struct Node {
        char chr;
        int c;
        int child[K];
        Node(char a, bool c = 0): chr(a), c(c) { memset(child, -1, sizeof(child)); }
    };

    vector<Node> nodes;

    Trie() {
        nodes.reserve(MAXN);
        nodes.eb('^');
    }

    void insert(string word) {
        int cur = 0;
        ++nodes[cur].c;
        for (char c : word) {
            int idx = c - OFFSET;
            if (nodes[cur].child[idx] == -1) {
               nodes[cur].child[idx] = len(nodes);
               nodes.eb(c);
            }
            cur = nodes[cur].child[idx];
            ++nodes[cur].c;
        }
    }

    int starts_with(string prefix) {
        int cur = 0;
        int t = nodes[cur].c;
        for (char c : prefix) {
            Node& node = nodes[cur];
            int idx = c - OFFSET;
            if (node.child[idx] == -1) return t;
            cur = node.child[idx];
            t += nodes[cur].c;
        }
        return t;
    }
};

void solve() {
    int n; cin >> n;
    vector<string> ws(n);
    umap<string, int> m;
    forn (i, n) {
        cin >> ws[i];
        m[ws[i]] = i;
    }
    int q; cin >> q;
    vector<tuple<int, string, int>> qs(q);
    forn(i, q) {
        string w; cin >> w;
        auto it = m.find(w);
        int j = it == m.end() ? n : it->se;
        qs[i] = {j, w, i};
    }
    sort(all(qs));
    int qi = 0;
    Trie trie;
    vi ans(q);
    forn (i, n) {
        trie.insert(ws[i]);
        while (qi < q && get<0>(qs[qi]) == i) {
            auto [_, w, j] = qs[qi++];
            ans[j] = trie.starts_with(w);
        }
    }
    while (qi < q) {
        auto [_, w, j] = qs[qi++];
        ans[j] = trie.starts_with(w);
    }
    for (int x : ans) cout << x << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();
}
