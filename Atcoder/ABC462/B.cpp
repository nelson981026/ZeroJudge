#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k, a;
    cin >> n;
    vector<vector<int>> vv(n);
    for (int x = 1; x <= n; ++x) {
        cin >> k;
        for (int y = 0; y < k; ++y) {
            cin >> a;
            vv[a - 1].emplace_back(x);
        }
    }
    for (auto v : vv) {
        cout << v.size();
        for (int x : v) {
            cout << " " << x;
        }
        cout << endl;
    }
}