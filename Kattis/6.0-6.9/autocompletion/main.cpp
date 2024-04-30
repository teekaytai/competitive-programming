#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); ++i)
#define len(x) (int) x.size()
#define pb push_back
#define eb emplace_back

struct Trie {
    static constexpr int MAXN = 5e5 + 1;
    static constexpr int K = 26;
    static constexpr char OFFSET = 'a';

    struct Node {
        char chr;
        bool is_w;
        int size = 0;
        int child[K];
        Node(char a, bool is_w = false): chr(a), is_w(is_w) { memset(child, -1, sizeof(child)); }
    };

    vector<Node> nodes;

    Trie() {
        nodes.reserve(MAXN);
        nodes.eb('^');
    }

    void insert(string word) {
        int cur = 0;
        for (char c : word) {
            Node& node = nodes[cur];
            int idx = c - OFFSET;
            if (node.child[idx] == -1) {
               node.child[idx] = len(nodes);
               nodes.eb(c);
            }
            ++node.size;
            cur = node.child[idx];
        }
        ++nodes[cur].size;
        nodes[cur].is_w = true;
    }

    string query(string s) {
        int cur = 0;
        string ans;
        int i = 0;
        while (i < len(s)) {
            Node& node = nodes[cur];
            char c = s[i];
            if (c != '#') {
                ans.pb(c);
                int idx = c - OFFSET;
                if (node.child[idx] == -1) break;
                cur = node.child[idx];
            } else {
                int r = 0;
                while (++i < len(s) && s[i] == '#') ++r;
                --i;
                if (node.size == node.is_w) break;
                r %= node.size - node.is_w;
                do {
                    for (int nxt : nodes[cur].child) if (nxt != -1) {
                        if (r < nodes[nxt].size) {
                            cur = nxt;
                            ans.pb(nodes[nxt].chr);
                            r -= nodes[nxt].is_w;
                            break;
                        } else r -= nodes[nxt].size;
                    }
                } while (!nodes[cur].is_w || r >= 0);
            }
            ++i;
        }
        while (++i < len(s)) if (s[i] != '#') ans.pb(s[i]);
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    Trie trie;
    int n; cin >> n;
    forn (i, n) {
        string s; cin >> s;
        trie.insert(s);
    }
    int q; cin >> q;
    forn (i, q) {
        string s; cin >> s;
        cout << trie.query(s) << "\n";
    }
}
