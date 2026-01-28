#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, flag;
    cin >> n;
    vector<vector<int>> a(2);
    a[0].resize(7);
    a[1].resize(7);
    for (int x = 0; x < n; ++x) {
        flag = 1;
        for (int y = 0; y < 7; ++y) {
            cin >> a[0][y];
        }
        for (int y = 0; y < 7; ++y) {
            cin >> a[1][y];
        }
        if (a[0][1] == a[0][3] || a[0][1] != a[0][5] || a[1][1] == a[1][3] || a[1][1] != a[1][5]) {
            cout << "A";
            flag = 0;
        }
        if (a[0][6] == 0 || a[1][6] == 1) {
            cout << "B";
            flag = 0;
        }
        if (a[0][1] == a[1][1] || a[0][3] == a[1][3] || a[0][5] == a[1][5]) {
            cout << "C";
            flag = 0;
        }
        cout << (flag ? "None\n" : "\n");
    }
    return 0;
}