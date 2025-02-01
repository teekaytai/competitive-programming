#include <bits/stdc++.h>
using namespace std;

bool cmp(char c1, char c2) {
    cout << "? " << c1 << " " << c2 << endl;
    char cmp; cin >> cmp;
    return cmp == '<';
}

void sort(string& s, int l, int r) {
    if (r - l < 2) return;
    int m = (l + r) / 2;
    sort(s, l, m);
    sort(s, m, r);
    string aux;
    merge(s.begin() + l, s.begin() + m, s.begin() + m, s.begin() + r, back_inserter(aux), cmp);
    move(aux.begin(), aux.end(), s.begin() + l);
}

int main() {
    int n, q; cin >> n >> q;
    string s;
    for (int i = 0; i < n; ++i) s += 'A' + i;
    if (n != 5) {
        sort(s, 0, n);
    } else {
        if (!cmp(s[0], s[1])) swap(s[0], s[1]);
        if (!cmp(s[2], s[3])) swap(s[2], s[3]);
        if (!cmp(s[0], s[2])) {swap(s[0], s[2]); swap(s[1], s[3]);}
        if (cmp(s[2], s[4])) {
            if (!cmp(s[3], s[4])) swap(s[3], s[4]);
            if (cmp(s[1], s[3])) {
                if (!cmp(s[1], s[2])) swap(s[1], s[2]);
            } else {
                swap(s[1], s[2]); swap(s[2], s[3]);
                if (!cmp(s[3], s[4])) swap(s[3], s[4]);
            }
        } else if (cmp(s[0], s[4])) {
            if (cmp(s[1], s[2])) {
                swap(s[3], s[4]); swap(s[2], s[3]);
                if (!cmp(s[1], s[2])) swap(s[1], s[2]);
            } else {
                swap(s[1], s[4]);
                if (!cmp(s[3], s[4])) swap(s[3], s[4]);
            }
        } else {
            swap(s[3], s[4]);
            swap(s[2], s[3]);
            swap(s[1], s[2]);
            swap(s[0], s[1]);
            if (!cmp(s[2], s[3])) {
                swap(s[2], s[3]);
                if (!cmp(s[3], s[4])) swap(s[3], s[4]);
            }
        }
    }
    cout << "! " << s << endl;
}
