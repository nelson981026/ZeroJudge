#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int m, n = s.size();
    cin >> m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    dp[0][0] = 1;
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            if (!dp[x][y]) {
                continue;
            }
            int tmp = 0;
            for (int i = 0; x + i < n; ++i) {
                tmp *= 10;
                tmp += s[x + i] - '0';
                if (y + tmp > m) {
                    break;
                } else {
                    dp[x + i + 1][y + tmp] += dp[x][y];
                }
            }
        }
    }

    for (int i = m; i >= 0; --i) {
        if (dp[n][i]) {
            cout << i << " " << dp[n][i] << "\n";
            return 0;
        }
    }
    return 0;
}