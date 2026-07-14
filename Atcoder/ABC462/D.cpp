#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, d, s, t;
    long long ret = 0;
    cin >> n >> d;
    vector<long long> cnt(1e6 + 1);
    for (int i = 0; i < n; ++i) {
        cin >> s >> t;
        if (s + d <= t) {
            cnt[s]++;
            cnt[t - d + 1]--;
        }
    }
    for (int i = 1; i < 1e6 + 1; ++i) {
        cnt[i] += cnt[i - 1];
        ret += cnt[i] * (cnt[i] - 1) / 2;
    }
    cout << ret;
    return 0;
}