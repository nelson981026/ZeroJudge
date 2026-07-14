#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define S first
#define R second
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        string s;
        cin >> n >> s;
        vector<LL> x(n), y(n - 1);
        vector<pair<LL, LL>> dp(n);
        for (auto &a : x)
            cin >> a;
        for (auto &b : y)
            cin >> b;
        dp[0] = {s[0] == 'S' ? 0 : -x[0], s[0] == 'R' ? 0 : -x[0]};
        for (int i = 1; i < n; ++i) {
            dp[i] = {max(dp[i - 1].S, dp[i - 1].R + y[i - 1]) - (s[i] == 'S' ? 0 : x[i]),
                     max(dp[i - 1].S, dp[i - 1].R) - (s[i] == 'R' ? 0 : x[i])};
        }
        cout << max(dp[n - 1].S, dp[n - 1].R) << endl;
    }
    return 0;
}