#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k, maxa = 0;
    cin >> n >> k;
    vector<int> val(n);
    vector<vector<int>> dp(n, vector<int>(k + 1));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &val[i]);
    }
    dp[0][0] = max(val[0], 0);
    maxa = max(maxa, val[0]);
    for (int x = 1; x < n; ++x) {
        dp[x][0] = max(dp[x - 1][0] + val[x], 0);
        maxa = max(maxa, dp[x][0]);
        for (int y = 1; y <= k; ++y) {
            dp[x][y] = max({dp[x - 1][y - 1], dp[x - 1][y] + val[x], 0});
            maxa = max(maxa, dp[x][y]);
        }
    }
    cout << maxa << "\n";
}