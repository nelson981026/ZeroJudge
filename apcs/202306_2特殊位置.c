#include <stdio.h>
#define ABS(a) (((a) > 0) ? (a) : (-(a)))
int main() {
    int n, m, x, y, a, b, tar;
    scanf("%d%d", &n, &m);
    int arr[n][m], ret[m * n][2], cou = 0, sum;
    for (x = 0; x < n; ++x) {
        for (y = 0; y < m; ++y) {
            scanf("%d", &arr[x][y]);
        }
    }
    for (x = 0; x < n; ++x) {
        for (y = 0; y < m; ++y) {
            sum = 0;
            tar = arr[x][y];
            for (a = x - tar; a <= x + tar; ++a) {
                if (a < 0 || a >= n) {
                    continue;
                }
                for (b = y - tar + ABS(x - a); b <= y + tar - ABS(x - a); ++b) {
                    if (b < 0 || b >= m) {
                        continue;
                    }
                    sum += arr[a][b];
                }
            }
            if (sum % 10 == tar % 10) {
                ret[cou][0] = x;
                ret[cou++][1] = y;
            }
        }
    }
    printf("%d\n", cou);
    for (x = 0; x < cou; ++x) {
        printf("%d %d\n", ret[x][0], ret[x][1]);
    }
    return 0;
}
