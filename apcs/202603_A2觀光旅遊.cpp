#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, s, e;
    cin >> n >> m;
    vector<int> t(n), p(n + 2);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t[i]);
    }
    sort(t.begin(), t.end());
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &s, &e);
        auto x = lower_bound(t.begin(), t.end(), s);
        auto y = upper_bound(t.begin(), t.end(), e);
        p[x - t.begin()]++;
        p[y - t.begin()]--;
    }
    long long sum = p[0];
    for (int i = 1; i < n; ++i) {
        p[i] += p[i - 1];
        sum += p[i];
    }
    cout << sum << "\n";
    return 0;
}