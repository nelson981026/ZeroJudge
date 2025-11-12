#include <limits.h>
#include <stdio.h>
#include <string.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int main(void) {
    int m, n, x, y;
    scanf("%d%d", &m, &n);
    int arr[m][n], dp[m + 1][n];

    for (x = 0; x < m; ++x) {
        for (y = 0; y < n; ++y) {
            scanf("%d", &arr[x][y]);
        }
    }
    memset(dp, INT_MIN, sizeof(dp));
    memset(dp, 0, sizeof(dp[0]));

    int floor, begin, end, temp, best, i;
    for (floor = 0; floor < m; ++floor) {
        for (end = 0; end < n; ++end) {
            //<-
            for (begin = end, temp = 0; begin >= 0; --begin) {
                temp += arr[floor][begin];
                if (temp + dp[floor][begin] > dp[floor + 1][end]) {
                    dp[floor + 1][end] = temp + dp[floor][begin];
                }
            }
            //->
            for (begin = end, temp = 0; begin < n; ++begin) {
                temp += arr[floor][begin];
                if (temp + dp[floor][begin] > dp[floor + 1][end]) {
                    dp[floor + 1][end] = temp + dp[floor][begin];
                }
            }
        }
    }

    best = INT_MIN;
    for (i = 0; i < n; ++i) {
        if (dp[m][i] > best) {
            best = dp[m][i];
        }
    }

    printf("%d\n", best);
    return 0;
}