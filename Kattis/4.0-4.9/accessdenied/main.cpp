#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string input = "DENIED";
    int timing = 5;
    string password = "A";
    cout << password << endl;
    cin >> input >> input;
    while (input == "DENIED") {
        cin.ignore(2);
        cin >> timing >> input;
        if (timing == 5) {
            password += 'A';
        } else {
            int idx = (timing - 14) / 9;
            password[idx] = password[idx] == 'Z' ? 'a' : password[idx] == 'z' ? '0' : char(password[idx] + 1);
        }
        cout << password << endl;
        cin >> input >> input;
    }
}
