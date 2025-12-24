#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;
int main() {
    int n, maxa = 1;
    cin >> n;
    pair<int, int> arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr + n);
    int dp[n];
    for (int x = 0; x < n; ++x) {
        dp[x] = 1;
        for (int y = 0; y < x; ++y) {
            if (arr[y].second <= arr[x].second && dp[y] + 1 > dp[x]) {
                dp[x] = dp[y] + 1;
            }
        }
        if (dp[x] > maxa) {
            maxa = dp[x];
        }
    }
    cout << maxa;
    return 0;
}
