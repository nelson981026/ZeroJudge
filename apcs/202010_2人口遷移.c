#include <limits.h>
#include <stdio.h>
#include <string.h>
int main(void) {
    int r, c, k, m, x, y, i;
    scanf("%d%d%d%d", &r, &c, &k, &m);
    int city[r][c], delta[r][c];
    for (x = 0; x < r; ++x) {
        for (y = 0; y < c; ++y) {
            scanf("%d", &city[x][y]);
        }
    }
    for (i = 0; i < m; ++i) {
        memset(delta, 0, sizeof(delta));
        for (x = 0; x < r; ++x) {
            for (y = 0; y < c; ++y) {
                if (x > 0) {
                    if (city[x - 1][y] != -1) {
                        delta[x][y] -= city[x][y] / k;
                        delta[x - 1][y] += city[x][y] / k;
                    }
                }
                if (x < r - 1) {
                    if (city[x + 1][y] != -1) {
                        delta[x][y] -= city[x][y] / k;
                        delta[x + 1][y] += city[x][y] / k;
                    }
                }
                if (y > 0) {
                    if (city[x][y - 1] != -1) {
                        delta[x][y] -= city[x][y] / k;
                        delta[x][y - 1] += city[x][y] / k;
                    }
                }
                if (y < c - 1) {
                    if (city[x][y + 1] != -1) {
                        delta[x][y] -= city[x][y] / k;
                        delta[x][y + 1] += city[x][y] / k;
                    }
                }
            }
        }
        for (x = 0; x < r; ++x) {
            for (y = 0; y < c; ++y) {
                city[x][y] += delta[x][y];
            }
        }
    }
    int min = INT_MAX, max = INT_MIN;
    for (x = 0; x < r; ++x) {
        for (y = 0; y < c; ++y) {
            if (city[x][y] != -1) {
                if (city[x][y] > max) {
                    max = city[x][y];
                }
                if (city[x][y] < min) {
                    min = city[x][y];
                }
            }
        }
    }
    printf("%d\n%d\n", min, max);
    return 0;
}