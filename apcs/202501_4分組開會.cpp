#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, k, mini = (1LL) << 55;
    cin >> n >> k;
    vector<long long> x(n), p(n - k / 2 + 1), pp(n - k + 1), ppm(n - k + 1);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &x[i]);
    }
    sort(x.begin(), x.end());
    for (int i = 0; i < k / 2; ++i) {
        p[0] += x[i];
    }
    for (int i = 1; i < p.size(); ++i) {
        p[i] = p[i - 1] + x[k / 2 + i - 1] - x[i - 1];
    }
    for (int i = 0; i < pp.size(); ++i) {
        pp[i] = p[i + (k + 1) / 2] - p[i];
    }
    ppm[ppm.size() - 1] = pp[pp.size() - 1];
    for (int i = ppm.size() - 2; i >= 0; --i) {
        ppm[i] = min(ppm[i + 1], pp[i]);
    }
    for (int i = 0; i < n - 2 * k + 1; ++i) {
        mini = min(mini, pp[i] + ppm[i + k]);
    }
    cout << mini << endl;
    return 0;
}
