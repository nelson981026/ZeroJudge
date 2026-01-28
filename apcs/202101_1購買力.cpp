#include <bits/stdc++.h>
using namespace std;
int abs(int a) {
    return a > 0 ? a : -a;
}
int main() {
    int n, d, a, b, c, cnt = 0, cost = 0;
    cin >> n >> d;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> c;
        if (abs(a - b) >= d || abs(b - c) >= d || abs(a - c) >= d) {
            cnt++;
            cost += (a + b + c) / 3;
        }
    }
    cout << cnt << " " << cost;
    return 0;
}