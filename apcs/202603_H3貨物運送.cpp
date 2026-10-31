#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define INF (1LL) << 50
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> task(k);
    vector<vector<int>> cost(n, vector<int>(n));
    vector<vector<LL>> dp(k + 1, vector<LL>(n, INF));
    dp[0][0] = 0;
    int last = 0;
    for (auto &x : task) {
        cin >> x;
        x--;
    }
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            cin >> cost[x][y];
        }
    }
    for (int x = 0; x < k; ++x) {
        for (int y = 0; y < n; ++y) {
            dp[x + 1][y] = dp[x][y] + cost[last][task[x]];
            // if(dp[x+1][y]<INF){
            //     printf("\tdp[%d][%d]=%lld\n",x+1,y,dp[x+1][y]);
            // }
        }
        for (int y = 0; y < n; ++y) {
            // if(dp[x+1][last]>dp[x][y]+cost[y][task[x]]){
            //     printf("\t-dp[%d][%d]=%lld\n",x+1,last,dp[x][y]+cost[y][task[x]]);
            // }
            dp[x + 1][last] = min(dp[x + 1][last], dp[x][y] + cost[y][task[x]]);
        }
        last = task[x];
    }
    long long ret = INF;
    for (int i = 0; i < n; ++i) {
        ret = min(ret, dp[k][i] + cost[last][n - 1] + cost[i][n - 1]);
    }
    cout << ret << endl;
    return 0;
}