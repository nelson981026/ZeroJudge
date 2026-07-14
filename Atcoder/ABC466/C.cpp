#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, l, r, sum = 0;
    string s;
    cin >> n;
    for (l = 1, r = 2; l <= n; ++l) {
        for (r += (l == r); r <= n; ++r) {
            cout << "? " << l << " " << r << endl;
            cin >> s;
            if (s[0] == 'N') {
                break;
            } else {
                sum += r - l;
            }
        }
    }
    cout << "! " << sum << endl;
    return 0;
}