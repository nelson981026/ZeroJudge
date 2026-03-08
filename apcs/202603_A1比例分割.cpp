#include <bits/stdc++.h>
using namespace std;
inline long long up(long long a, long long b) {
    return (a / b) + ((a % b) ? (1) : (0));
}
int main() {
    int n, m, l, r, a, b;
    cin >> n >> m;
    vector<long long> w(n + 1);
    scanf("%d", &w[1]);
    for (int i = 2; i <= n; ++i) {
        scanf("%d", &w[i]);
        w[i] += w[i - 1];
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d%d", &l, &r, &a, &b);
        long long tar = up(w[l - 1] * b + w[r] * a, a + b);
        auto x = lower_bound(w.begin(), w.end(), tar);
        printf("%d\n", x - w.begin());
    }
    return 0;
}