#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define R first
#define L second
vector<PII> c;
int n, k;
bool check(int d) {
    int cnt = 0, last = -(1 << 30);
    for (auto [r, l] : c) {
        if (l >= last) {
            last = r + d;
            cnt++;
        }
    }
    return cnt >= k;
}
int main() {
    cin >> n >> k;
    c.resize(n);
    for (auto &x : c)
        cin >> x.L >> x.R;
    sort(c.begin(), c.end());
    int l = -1, r = (1e9 + 1), m;
    while (l < r - 1) {
        m = (l + r) / 2;
        if (check(m))
            l = m;
        else
            r = m;
    }
    cout << ((l <= 0) ? -1 : l) << endl;
    return 0;
}