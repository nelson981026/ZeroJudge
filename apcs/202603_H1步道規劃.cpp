#include <bits/stdc++.h>
using namespace std;
#define PLL pair<long long, long long>
int main() {
    int n, k;
    cin >> n >> k;
    vector<PLL> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first;
    }
    for (int i = 0; i < n; ++i) {
        cin >> p[i].second;
    }
    sort(p.begin(), p.end());
    long long l = -1, r = (1LL) << 60;
    while (l < r - 1) {
        long long m = (l + r) / 2, cnt = 0, sum = 0;
        for (int i = 0; i < n - 1; ++i) {
            long long detla =
                (p[i + 1].first - p[i].first) + max(0LL, 2 * (p[i + 1].second - p[i].second));
            if (sum + detla > m) {
                cnt++;
                sum = 0;
            } else {
                sum += detla;
            }
        }
        if (cnt >= k) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << r << endl;
    return 0;
}