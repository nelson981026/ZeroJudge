#include <stdio.h>

int main() {
    int n, k, x, y, min, max = 0;
    scanf("%d %d", &n, &k);
    if (k != 2) {
        printf("0\n");
        return 0;
    }
    int dis[n][n], team;
    for (x = 0; x < n; ++x) {
        for (y = 0; y < n; ++y) {
            scanf(" %d", &dis[x][y]);
        }
    }
    for (team = 1; team < (1 << n) - 1; ++team) {
        min = 1000000001;
        for (x = 0; x < n; ++x) {
            for (y = x + 1; y < n; y++) {
                if (!(team & (1 << x)) != !(team & (1 << y))) {
                    if (dis[x][y] < min) {
                        min = dis[x][y];
                    }
                }
            }
        }
        if (min > max) {
            max = min;
        }
    }
    printf("%d\n", max);
    return 0;
}