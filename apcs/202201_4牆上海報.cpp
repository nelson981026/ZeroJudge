#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> h, w;
bool check(int height) {
    int cnt, x, y;
    for (x = 0, y = 0, cnt = 0; x < k && y <= n; ++x) {
        for (; y <= n; ++y) {
            if (h[y] >= height) {
                cnt++;
            } else {
                cnt = 0;
            }
            if (cnt >= w[x]) {
                cnt = 0;
                ++y;
                break;
            }
        }
    }
    return y <= n;
}
int main() {
    bool ret;
    cin >> n >> k;
    h.resize(n);
    for (auto &x : h) {
        cin >> x;
    }
    h.emplace_back(-1);
    w.resize(k);
    for (auto &y : w) {
        cin >> y;
    }
    int l = 0, r = 1e9 + 5, m;
    while (l < r - 1) {
        m = (l + r) / 2;
        ret = check(m);
        if (ret)
            l = m;
        else
            r = m;
    }
    cout << l;
    return 0;
}