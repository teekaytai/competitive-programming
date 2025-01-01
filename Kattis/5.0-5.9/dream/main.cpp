#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); ++i)
#define len(x) (int) (x).size()
template<class T> constexpr void cmin(T& a, T b) { a = min(a, b); }
template<class T> constexpr void cmax(T& a, T b) { a = max(a, b); }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    unordered_map<string, int> m;
    stack<string> st;
    forn(_, n) {
        char c; cin >> c;
        if (c == 'E') {
            string s; cin >> s;
            m[s] = len(st);
            st.emplace(move(s));
        } else if (c == 'D') {
            int x; cin >> x;
            while (x) {
                m.erase(st.top());
                st.pop();
                --x;
            }
        } else {
            int k; cin >> k;
            int lo = 0;
            int hi = len(st);
            forn (_, k) {
                string s; cin >> s;
                if (s[0] == '!') {
                    auto it = m.find(s.substr(1));
                    if (it != m.end()) cmin(hi, it->second);
                } else {
                    auto it = m.find(s);
                    if (it == m.end()) lo = len(st) + 1;
                    else cmax(lo, it->second + 1);
                }
            }
            if (lo > hi) cout << "Plot Error\n";
            else {
                int x = len(st) - hi;
                x == 0 ? (cout << "Yes\n") : (cout << x << " Just A Dream\n");
            }
        }
    }
}
