#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, s = 0, tmp, f = 0;
    cin >> n >> m;
    int maxn[n];
    for (int x = 0; x < n; ++x) {
        cin >> maxn[x];
        for (int y = 1; y < m; ++y) {
            cin >> tmp;
            if (tmp > maxn[x]) {
                maxn[x] = tmp;
            }
        }
        s += maxn[x];
    }
    cout << s << endl;
    for (int x : maxn) {
        if (!(s % x)) {
            cout << (f ? " " : "") << x;
            f = 1;
        }
    }
    if (!f) {
        cout << "-1";
    }
    return 0;
}
