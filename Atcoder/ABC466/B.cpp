#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, c, s;
    cin >> n >> m;
    vector<int> maxa(m, -1);
    for (int i = 0; i < n; ++i) {
        cin >> c >> s;
        maxa[c - 1] = max(maxa[c - 1], s);
    }
    for (auto x : maxa) {
        cout << x << " ";
    }
    return 0;
}