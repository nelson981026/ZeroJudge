#include <stdio.h>
int main(void) {
    int r, c, max = 0, sum = 0, t;
    scanf("%d%d", &r, &c);
    unsigned char p1[r][c], p2[r][c];
    for (int x = 0; x < r; ++x) {
        for (int y = 0; y < c; ++y) {
            scanf("%hhu", &p1[x][y]);
        }
    }
    for (int x = 0; x < r; ++x) {
        for (int y = 0; y < c; ++y) {
            scanf("%hhu", &p2[x][y]);
        }
    }
    // 0 deg
    for (int x = 0; x < r; ++x) {
        for (int y = 0; y < c; ++y) {
            if (p1[x][y] == p2[x][y]) {
                sum++;
            }
        }
    }
    if (sum > max) {
        max = sum;
    }
    sum = 0;
    // 90 deg
    if (r == c) {
        for (int x = 0; x < r; ++x) {
            for (int y = 0; y < c; ++y) {
                if (p1[x][y] == p2[y][c - 1 - x]) {
                    sum++;
                }
            }
        }
        if (sum > max) {
            max = sum;
        }
        sum = 0;
    }
    // 180 deg
    for (int x = 0; x < r; ++x) {
        for (int y = 0; y < c; ++y) {
            if (p1[x][y] == p2[r - 1 - x][c - 1 - y]) {
                sum++;
            }
        }
    }
    if (sum > max) {
        max = sum;
    }
    sum = 0;
    // 270 deg
    if (r == c) {
        for (int x = 0; x < r; ++x) {
            for (int y = 0; y < c; ++y) {
                if (p1[x][y] == p2[r - 1 - y][x]) {
                    sum++;
                }
            }
        }
        if (sum > max) {
            max = sum;
        }
        sum = 0;
    }
    printf("%d%%\n", (max * 100 / (r * c)));
    return 0;
}
