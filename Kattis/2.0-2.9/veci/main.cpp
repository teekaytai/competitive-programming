#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    cout << (next_permutation(s.begin(), s.end()) ? s : "0") << "\n";
    return 0;
}
