#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            cout << c;
        }
    }
    cout << endl;
    return 0;
}