#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    char x;
    string s;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (s[x - 'A'] == 'o') {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}